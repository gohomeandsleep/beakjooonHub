#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		stack<char> s;
		stack<char> other;
		
		string w;
		cin >> w;
		
		for (int i = 0; i < w.size(); i++) {
			if (w[i] == '<') { //왼쪽으로 이동 즉 s->other
				if (!s.empty()) {
					char tmp = s.top();
					s.pop();
					other.push(tmp);
				}
			}
			else if (w[i] == '>') { //오른쪽으로 이동 즉 other->s
				if (!other.empty()) {
					char tmp = other.top();
					other.pop();
					s.push(tmp);
				}
			}
			else if (w[i] == '-') { // 삭제
				if (!s.empty()) {
					s.pop();
				}
			}
			else {
				s.push(w[i]);
			}
		}
		
		if (!s.empty()) {
			int s_size = s.size();
			for (int j = 0; j < s_size; j++) {
				char tmp = s.top();
				s.pop();
				other.push(tmp);
			}
		}
		
		int other_size = other.size();
		for (int j = 0; j < other_size; j++) {
			cout << other.top();
			other.pop();
		}
		cout << endl;
	}

	return 0;
}