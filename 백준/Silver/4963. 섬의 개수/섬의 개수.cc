#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dy[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

bool inRange(int y, int x, int h, int w) {
	return y >= 0 && x >= 0 && y < h && x < w;
}

void visit(vector<vector<int>> &arr, int y, int x, int h, int w) {
	queue<pair<int, int>> q;
	q.push({ y, x });
	while (!q.empty()) {
		int nextY = q.front().first;
		int nextX = q.front().second;
		arr[nextY][nextX] = 2;
		q.pop();
		for (int i = 0; i < 8; i++) {
			if (inRange(nextY + dy[i], nextX + dx[i], h, w) && arr[nextY + dy[i]][nextX + dx[i]] == 1) {
				q.push({ nextY + dy[i], nextX + dx[i] });
				arr[nextY + dy[i]][nextX + dx[i]] = 2;
			}
		}
	}
}

int main() {
	while (true) {
		int w, h;
		cin >> w >> h;
		if (w == 0 && h == 0) return 0;

		vector<vector<int>> arr(h);
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				int k;
				cin >> k;
				arr[i].push_back(k);
			}
		}

		int result = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (arr[i][j] == 1) {
					visit(arr, i, j, h, w);
					result++;
				}
			}
		}

		cout << result << endl;
	}
}