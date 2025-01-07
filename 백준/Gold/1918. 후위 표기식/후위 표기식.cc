#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

template<class T>
void dump(stack<T> s) {
	stack<T> t;
	int size = s.size();

	for (int i = 0; i < size; i++) {
		int tmp = s.top();
		t.push(tmp);
		s.pop();
	}

	for (int i = 0; i < size; i++) {
		cout << t.top();
		t.pop();
	}
}

int icp(char s) {
	if (s == '(') return 3;
	if (s == '*' || s == '/') return 2;
	if (s == '+' || s == '-') return 1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	vector<char> result;

	stack<char> token;

	for (int i = 0; i < s.size(); i++) {
		if (string("+-*/()").find(s[i]) != string::npos) { //연산자
			if (token.size() == 0) { //아무것도 없으면 삽입
				token.push(s[i]);
			}
			else if (s[i] == ')') { //여는 괄호 나올 때까지 다 pop
				while (token.top() != '(') {
					result.push_back(token.top());
					token.pop();
				}
				token.pop();
			}
			else { //연산자 우선순위 고려햐여 push하거나 pop
				int prev = icp(token.top());
				int pres = icp(s[i]);
				//cout << prev << " : " << pres << endl;
				if (prev == 3 || prev < pres) { //삽입하는 상황
					token.push(s[i]);
				}
				else{ //빼내는 하는 상황
					while (!token.empty() && icp(token.top()) >= pres && icp(token.top()) != 3) {
						result.push_back(token.top());
						token.pop();
					}
					token.push(s[i]);
				}
			}
		}
		else { //피연산자므로 바로 결과에 추가
			result.push_back(s[i]);
		}
		//debug
		//cout << "현재 문자열 : ";
		//for (int i = 0; i < result.size(); i++) {
		//	cout << result[i];
		//}
		//cout << endl;
		//cout << "현재 토큰 : ";
		//dump(token);
		//cout << endl;
		//system("pause");
	}

	while (!token.empty()) {
		result.push_back(token.top());
		token.pop();
	}

	for (int i = 0; i < result.size(); i++) {
		cout << result[i];
	}

	return 0;
}