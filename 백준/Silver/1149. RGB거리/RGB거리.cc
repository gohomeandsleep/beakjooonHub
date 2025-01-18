#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<vector<int>> arr(N, vector<int>(3));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			int k;
			cin >> k;
			arr[i][j] = k;
		}
	}

	for (int i = 1; i < N; i++) {
		arr[i][0] += min(arr[i - 1][1], arr[i - 1][2]);
		arr[i][1] += min(arr[i - 1][0], arr[i - 1][2]);
		arr[i][2] += min(arr[i - 1][0], arr[i - 1][1]);
	}

	cout << min(min(arr[N - 1][0], arr[N - 1][1]), arr[N - 1][2]);

	return 0;
}