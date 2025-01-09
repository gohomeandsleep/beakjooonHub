#include <iostream>
#include <queue>
#include <vector>

using namespace std;

bool inRange(long long k) {
	return (k >= 0 && k < 1000000000);
}

int main() {
	long long stp, endp;
	cin >> stp >> endp;

	if (stp == endp) { //시작과 끝이 동일 ->이동 횟수 0회로 1 출력
		cout << 1 << endl;
		return 0;
	}

	queue<pair<long long, int>> q;
	vector<bool> visited(1000000001, false);
	q.push({ stp, 0 });
	
	while (!q.empty()) {
		pair<long long, int> front = q.front();
		long long k = front.first;
		int att = front.second + 1;
		q.pop();

		if (k * 2 == endp || 10 * k + 1 == endp) {
			cout << att + 1;
			return 0;
		}
		
		if (inRange(k * 2) && !visited[k * 2]) {
			q.push({ k * 2, att });
		}
		if (inRange(10 * k + 1) && !visited[10 * k + 1]) {
			q.push({ 10 * k + 1, att });
		}
	}

	cout << "-1";
	return 0;
}