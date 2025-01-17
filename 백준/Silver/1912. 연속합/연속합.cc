#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> arr;

	for (int i = 0; i < N; i++) {
		int k;
		cin >> k;
		arr.push_back(k);
	}

	int maxV = -2147483647;
	maxV = max(maxV, arr[0]);
	int psum = arr[0];
	//cout << arr[0] << endl;

	for (int i = 1; i < N; i++) {
		//cout << psum + arr[i] << " : " << arr[i] << endl;
		psum = max(psum + arr[i], arr[i]);
		maxV = max(maxV, psum);
		//cout << maxV << endl;
	}

	cout << maxV << endl;
}