#include <vector>
#include <iostream>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	if (k == 0) {
		cout << 1 << endl;
		return 0;
	}

	vector<vector<int>> arr(k, vector<int>(n, 0));

	for (int i = 0; i < n; i++) {
		arr[0][i] = i + 1;
	}

	for (int i = 1; i < k; i++) { //y 좌표
		for (int j = 0; j < n; j++) { //x 좌표
			if (i > j) continue;
			else if (i == j) arr[i][j] = 1;
			else arr[i][j] = (arr[i - 1][j - 1] + arr[i][j - 1]) % 10007;
		}
	}

	cout << arr[k - 1][n - 1] << endl;

	return 0;
}

