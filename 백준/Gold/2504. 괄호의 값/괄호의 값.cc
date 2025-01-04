#include <stack>
#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

template <class T>
void print(stack<T> s) {
	stack<T> temp;
	while (!s.empty()) {
		T what = s.top();
		temp.push(what);
		s.pop();
	}

	while (!temp.empty()) {
		cout << temp.top() << " "; // 스택의 맨 위 요소 출력
		temp.pop();                // 요소 제거
	}
	cout << endl;
}

int main() {
	string s;
	cin >> s;

	double result = 0;

	stack<string> st;

	for (int i = 0; i < s.size(); i++) {
		string current(1, s[i]);
		if (s[i] == '(') {
			st.push(current);
		}
		if (s[i] == '[') {
			st.push(current);
		}
		if (s[i] == ')') {
			if (st.empty()) { //탈출 조건
				std::cout << 0;
				return 0;
			}
			else {
				if (s[i - 1] != '(') {
					// 반복해서 숫자 뽑아서 더함
					double tmp = 0;
					while (st.top() != "(") {
						if (st.top() == "[") {
							std::cout << 0;
							return 0;
						}
						tmp += double(stoi(st.top()));
						st.pop();
					}
					st.pop();
					if (st.empty()) {
						// 스택이 빌 경우결과에 추가
						result += tmp * 2;
					}
					else {
						// 스택이 비지 않을 경우 그 값의 2배 push함
						st.push(to_string(tmp * 2));
					}
				}
				else { //() -> 숫자 2 push
					st.pop();
					if (st.empty()) {
						result += 2;
					}
					else {
						st.push("2");
					}
				}
			}
		}
		if (s[i] == ']') {
			if (st.empty()) {
				std::cout << 0;
				return 0;
			}
			else {
				if (s[i - 1] != '[') {
					double tmp = 0;
					while (st.top() != "[") {
						if (st.top() == "(") {
							std::cout << 0;
							return 0;
						}
						tmp += double(stoi(st.top()));
						st.pop();
					}
					st.pop();
					if (st.empty()) {
						result += double(tmp) * 3;
					}
					else {
						st.push(to_string(tmp * 3));
					}
				}
				else {
					st.pop();
					if (st.empty()) {
						result += 3;
					}
					else {
						st.push("3");
					}
				}
			}
		}
		//print(st);
		//std::cout << result << endl;
		//system("pause");
	}
	if (!st.empty()) std::cout << 0;
	else std::cout << fixed << setprecision(0) << result;

	return 0;
}