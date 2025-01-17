#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N;
	cin >> N;

	if (N == 1) {
		cout << 9 << endl;
		return 0;
	}

	vector<vector<int>> arr(10, vector<int>(N, 0));

	for (int i = 0; i < 10; i++) {
		arr[i][0] = 1;
	}

	for (int x = 1; x < N; x++) {
		for (int y = 0; y < 10; y++) {
			//cout << y << " : " << x << endl;
			if (y == 0) arr[y][x] = arr[1][x - 1];
			else if (y == 9) arr[y][x] = arr[8][x - 1];
			else arr[y][x] = (arr[y - 1][x - 1] + arr[y + 1][x - 1]) % 1000000000;
		}
	}

	int result = 0;
	for (int i = 1; i < 10; i++) {
		//cout << arr[i][N - 1] << endl;
		result = (result + arr[i][N - 1]) % 1000000000;
	}

	cout << result << endl;

	return 0;
}