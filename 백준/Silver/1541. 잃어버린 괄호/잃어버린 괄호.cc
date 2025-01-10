#include <iostream>
#include <queue>
#include <string>

using namespace std;

int popValue(queue<int>& q) {
	if (q.empty()) return 0;
	int k = q.front();
	q.pop();
	while (!q.empty()) {
		k = 10 * k + q.front();
		q.pop();
	}
	//cout << k << endl;
	return k;
}

int main() {
	string s;
	cin >> s;

	queue<int> q;
	char op = '?'; // 저장되는 연산자
	int result = 0; // 결과
	bool isMinus = false; //- 기호가 최초 등장했는지
	for (int i = 0; i < s.size(); i++) {
		//cout << s[i] << endl;
		if (s[i] == '-') {
			isMinus = true;
			if (op == '?') { // 연산자가 처음 등장 -> 더해주어야 함
				op = '-';
				result += popValue(q);
			}
			else result -= popValue(q);
		}
		else if (s[i] == '+') {
			if (isMinus) result -= popValue(q);
			else result += popValue(q);
		}
		else { // 숫자 -> queue에 추가
			q.push(s[i] - '0');
		}
	}

	if (!q.empty()) {
		if (isMinus) result -= popValue(q);
		else result += popValue(q);
	}

	cout << result << endl;

	return 0;
}