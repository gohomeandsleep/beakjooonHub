#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> stairs;
	for (int i = 0; i < N; i++) {
		int k;
		cin >> k;
		stairs.push_back(k);
	}

	if (N == 1) {
		cout << stairs[0];
		return 0;
	}
	if (N == 2) {
		cout << stairs[0] + stairs[1];
		return 0;
	}

	vector<int> psum;
	psum.push_back(stairs[0]);
	psum.push_back(stairs[0] + stairs[1]);

	for (int i = 2; i < N; i++) {
		//cout << psum[i - 2]<< " : " << psum[i - 3] + stairs[i - 1] << endl;
		psum.push_back(max(psum[i - 2], psum[i - 3] + stairs[i - 1]) + stairs[i]);
	}

	cout << psum[N - 1] << endl;

	return 0;
}