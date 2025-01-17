#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<vector<int>> arr(N, vector<int>(N, -1));

	int v = -1;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			int k;
			cin >> k;
			if (i > 0) { //덮어 쓸 조건
				if (j == 0) {
					arr[i][j] = k + arr[i - 1][j];
				}
				else if (j == i) {
					arr[i][j] = k + arr[i - 1][j - 1];
				}
				else {
					arr[i][j] = max(arr[i - 1][j - 1], arr[i - 1][j]) + k;
				}
			}
			else arr[i][j] = k;

			v = max(v, arr[i][j]);
		}
	}
	
	cout << v << endl;

	return 0;
	
}