#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int testCase;
	cin >> testCase;

	vector<int> req;
	int maxR = 0;

	for (int i = 0; i < testCase; i++) {
		int k = 0;
		cin >> k;
		maxR = max(maxR, k);
		req.push_back(k);
	}

	vector<long long> result;
	result.push_back(0);
	result.push_back(1);
	result.push_back(2);
	result.push_back(4);
	for (int i = 4; i <= maxR; i++) {
		result.push_back((result[i - 1] + result[i - 2] + result[i - 3]) % 1000000009);
	} 

	for (int i = 0; i < testCase; i++) {
		cout << result[req[i]] << endl;
	}

	return 0;


}
