#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

bool inRange(int y, int x, int N) {
	return y >= 0 && x >= 0 && y < N && x < N;
}

void visit(vector<vector<int>>& arr, int y, int x, int N, int height) {
	queue<pair<int, int>> q;
	q.push({ y, x });
	arr[y][x] = -1;
	while (!q.empty()) {
		int nextY = q.front().first;
		int nextX = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int locY = nextY + dy[i];
			int locX = nextX + dx[i];
			if (inRange(locY, locX, N) && arr[locY][locX] > height) {
				arr[locY][locX] = -1;
				q.push({ locY, locX });
			}
		}
	}
}

int main() {
	int N;
	cin >> N;

	vector<vector<int>> arr(N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int k;
			cin >> k;
			arr[i].push_back(k);
		}
	}

	vector<vector<int>> tmp;
	int result = 0;
	for (int height = 0; height <= 100; height++) { //height : 잠기는 높이
		tmp = arr; //각각의 잠기는 높이에 따라 시뮬레이션할 배열을 원본에서 복사
		int field = 0; //안전 영역의 개수
		for (int i = 0; i < N; i++) { // i : y
			for (int j = 0; j < N; j++) { // j : x
				if (tmp[i][j] > height) {
					field++;
					visit(tmp, i, j, N, height);
				}
			}
		}
		result = max(result, field);
	}

	cout << result << endl;

	return 0;
}