#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

// void dump(vector<vector<char>> arr) {
// 	for (int i = 0; i < N; i++) {
// 		for (int j = 0; j < N; j++) {
// 			cout << arr[i][j] << " ";
// 		}
// 		cout << endl;
// 	}
// 	cout << endl;
// }

// int check(vector<vector<char>> arr) {
// 	int res = 0;

// 	dump(arr);

// 	//check row
// 	for (int i = 0; i < N; i++) {
// 		int rept = 1;
// 		char tmp = arr[i][0];
// 		for (int j = 1; j < N; j++) {
// 			if (tmp == arr[i][j]) rept += 1;
// 			else {
// 				res = max(res, rept);
// 				tmp = arr[i][j];
// 				rept = 1;
// 			}
// 		}
// 	}

// 	//check column
// 	for (int i = 0; i < N; i++) {
// 		int rept = 1;
// 		char tmp = arr[0][i];
// 		for (int j = 1; j < N; j++) {
// 			if (tmp == arr[j][i]) rept += 1;
// 			else {
// 				res = max(res, rept);
// 				tmp = arr[j][i];
// 				rept = 1;
// 			}
// 		}
// 	}

// 	return res;
// }

int swapRow(vector<vector<char>> arr, int y, int x) {
	//[y][x-1] <-> [y][x]
	char tmp = arr[y][x];
	arr[y][x] = arr[y][x - 1];
	arr[y][x - 1] = tmp;

	int res = 0;

	//dump(arr);

	//check row
	for (int i = 0; i < N; i++) {
		int rept = 1;
		char tmp = arr[i][0];
		for (int j = 1; j < N; j++) {
			if (tmp == arr[i][j]) rept += 1;
			else {
				res = max(res, rept);
				tmp = arr[i][j];
				rept = 1;
			}
		}
		res = max(res, rept);
	}

	//check column
	for (int i = 0; i < N; i++) {
		int rept = 1;
		char tmp = arr[0][i];
		for (int j = 1; j < N; j++) {
			if (tmp == arr[j][i]) rept += 1;
			else {
				res = max(res, rept);
				tmp = arr[j][i];
				rept = 1;
			}
		}
		res = max(res, rept);
	}

	return res;
}

int swapCol(vector<vector<char>> arr, int y, int x) {
	//[y-1][x] <-> [y][x]
	char tmp = arr[y][x];
	arr[y][x] = arr[y - 1][x];
	arr[y - 1][x] = tmp;


	int res = 0;

	//dump(arr);

	//check row
	for (int i = 0; i < N; i++) {
		int rept = 1;
		char tmp = arr[i][0];
		for (int j = 1; j < N; j++) {
			if (tmp == arr[i][j]) rept += 1;
			else {
				res = max(res, rept);
				tmp = arr[i][j];
				rept = 1;
			}
		}
	}

	//check column
	for (int i = 0; i < N; i++) {
		int rept = 1;
		char tmp = arr[0][i];
		for (int j = 1; j < N; j++) {
			if (tmp == arr[j][i]) rept += 1;
			else {
				res = max(res, rept);
				tmp = arr[j][i];
				rept = 1;
			}
		}
	}

	return res;
}

int main() {
	cin >> N;

	vector<vector<char>> arr(N, vector<char> (N, '.'));
	char k;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> k;
			arr[i][j] = k;
		}
	}

	int result = 0;
	//row
	for (int i = 0; i < N; i++) {
		for (int j = 1; j < N; j++) {
			result = max(result, swapRow(arr, i, j));
		}
	}

	//column
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < N; j++) {
			result = max(result, swapCol(arr, i, j));
		}
	}

	cout << result << endl;

	return 0;
}