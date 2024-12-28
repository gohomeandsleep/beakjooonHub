#include <stack>
#include <string>
#include <iostream>

using namespace std;

int main() {
	string s;
	cin >> s;
	
	int result = 0;
	int num = 0;
	int current = 0;

	while (current != s.size()) {
		if (s[current] == '(') {
			if (s[current + 1] == ')') {
				result += num;
				//cout << num << endl;
				current = current + 2;
			}
			else {
				num += 1;
				current++;
			}
		}
		else {
			result += 1;
			num--;
			current++;
		}
	}

	cout << result;

	return 0;
}