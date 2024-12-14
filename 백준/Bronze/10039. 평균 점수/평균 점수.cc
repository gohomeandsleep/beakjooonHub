#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> array(5);
	int sum = 0;
	for (int i = 0; i < 5; i++) {
		int k;
		cin >> k;
		if (k < 40) sum += 40;
		else sum += k;
	}
	
	cout << sum / 5 << endl;
}