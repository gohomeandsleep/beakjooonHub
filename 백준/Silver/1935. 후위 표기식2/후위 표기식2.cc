#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int main() {
	int N;
	cin >> N;

	string w;
	cin >> w;

	vector<double> alpha;

	for (int i = 0; i < N; i++) {
		double tmp;
		cin >> tmp;
		alpha.push_back(tmp);
	}

	stack<double> s;

	for (int i = 0; i < w.size(); i++) {
		if (w[i] >= 65 && w[i] <= 90) {
			int loc = w[i] - 65;
			s.push(alpha[loc]);
		}
		else {
			double param2 = s.top();
			s.pop();
			double param1 = s.top();
			s.pop();
			if (w[i] == '+') {
				s.push(param1 + param2);
			}
			if (w[i] == '-') {
				s.push(param1 - param2);
			}
			if (w[i] == '*') {
				s.push(param1 * param2);
			}
			if (w[i] == '/') {
				s.push(param1 / param2);
			}
		}
	}

	cout << fixed;
	cout.precision(2);
	cout << s.top();
}