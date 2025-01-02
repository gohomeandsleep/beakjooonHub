#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main() {
	string org, comp;
	cin >> org >> comp;

	vector<char> stack;
	int comp_size = comp.size();

	for (char c : org) {
		stack.push_back(c);

		if (stack.size() >= comp_size) {
			bool isSame = true;
			for (int i = 0; i < comp_size; i++) {
				if (stack[stack.size() - comp_size + i] != comp[i]) {
					isSame = false;
					break;
				}
			}
			if (isSame) {
				for (int i = 0; i < comp_size; i++) {
					stack.pop_back();
				}
			}
		}
	}

	if (stack.empty()) {
		cout << "FRULA";
	}
	else {
		for (char c : stack) {
			cout << c;
		}
	}

	return 0;
}