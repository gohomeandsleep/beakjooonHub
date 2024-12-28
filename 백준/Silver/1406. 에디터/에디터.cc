#include <stack>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	string s;
	cin >> s;
	stack<char> st, tmp;
	for (int i = 0; i < s.size(); i++) {
		st.push(s[i]);
	}

	int order;
	cin >> order;
	for (int i = 0; i < order; i++) {
		char what, w, temp;
		cin >> what;
		if (what == 'L') {
			if (!st.empty()) {
				temp = st.top();
				//std::cout << temp << endl;
				st.pop();
				tmp.push(temp);
			}
		}
		if (what == 'D') {
			if (!tmp.empty()) {
				temp = tmp.top();
				//std::cout << temp << endl;
				tmp.pop();
				st.push(temp);
			}
		}
		if (what == 'B') {
			if (!st.empty()) st.pop();
		}
		if (what == 'P') {
			cin >> w;
			st.push(w);
		}

	}

	while (!st.empty()){
		char temp = st.top();
		st.pop();
		tmp.push(temp);
	}

	while (!tmp.empty()) {
		std::cout << tmp.top();
		tmp.pop();
	}
}