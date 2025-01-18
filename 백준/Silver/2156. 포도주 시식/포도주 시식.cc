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

	int maxV = 0;
	vector<int> resultArr;
	if (N <= 3) { //적은 n에 대한 처리
		if (N == 1) cout << arr[0];
		else if (N == 2) cout << arr[0] + arr[1];
		else {
			sort(arr.begin(), arr.end());
			cout << arr[2] + arr[1] << endl;
		}
		return 0;
	}
	else {
		resultArr.push_back(arr[0]);
		resultArr.push_back(arr[0] + arr[1]);
		maxV = max(maxV, resultArr[1]);
		resultArr.push_back(max(max(arr[0] + arr[1], arr[0] + arr[2]), arr[1] + arr[2]));
		maxV = max(maxV, resultArr[2]);

	}

	for (int i = 3; i < N; i++) {
		if (i == 3) resultArr.push_back(max(resultArr[i - 3] + arr[i - 1],resultArr[i - 2]) + arr[i]);
		else resultArr.push_back(max(max(resultArr[i - 3] + arr[i - 1], resultArr[i - 4] + arr[i - 1]), resultArr[i - 2]) + arr[i]);
		maxV = max(maxV, resultArr[i]);
		//cout << maxV << " : " << resultArr[i] << endl;
	}

	cout << maxV << endl;

	return 0;
}