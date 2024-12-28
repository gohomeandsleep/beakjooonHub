#include <stack>
#include <string>
#include <iostream>

using namespace std;

int main() {
	string s;
	getline(cin, s);
	stack<char> st;
	int current = 0;
	while (current != s.size()) {
		if (s[current] == '<') {
			//cout << "1" << endl;
			while (!st.empty()) {
				cout << st.top();
				st.pop();
			}

			while (s[current] != '>') {
				cout << s[current];
				current++;
			}
			cout << '>';
			current++;
		}

		else if (s[current] == ' ') {
			//cout << "2" << endl;
			while (!st.empty()) {
				cout << st.top();
				st.pop();
			}
			cout << ' ';
			current++;
		}

		else {
			//cout << "3" << endl;
			st.push(s[current]);
			current++;
		}
	}

	while (!st.empty()) {
		cout << st.top();
		st.pop();
	}

	return 0;
}