#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

bool inRange(int y, int x, int height, int width) {
	return y >= 0 && x >= 0 && y < height && x < width;
}

int visit(vector<vector<int>> &arr, int y, int x, int height, int width) {
	queue<pair<int, int>> q;
	q.push({ y, x });
	int siz = 1;
	while (!q.empty()) {
		int nextY = q.front().first;
		int nextX = q.front().second;
		q.pop();
		arr[nextY][nextX] = -1;
		for (int i = 0; i < 4; i++) {
			int locY = nextY + dy[i];
			int locX = nextX + dx[i];
			if (inRange(locY, locX, height, width) && arr[locY][locX] == 1) {
				siz++;
				arr[locY][locX] = -1;
				q.push({ locY, locX });
			}
		}
	}
	
	return siz;
}

int main() {
	int height, width, garbage;
	cin >> height >> width >> garbage;

	vector<vector<int>> arr(height, vector<int>(width, 0));

	for (int i = 0; i < garbage; i++) {
		int y, x;
		cin >> y >> x;
		arr[y - 1][x - 1] = 1;
	}

	int result = 0;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (arr[i][j] == 1) {
				int tmp = visit(arr, i, j, height, width);
				result = max(result, tmp);
			}
		}
	}
	
	cout << result << endl;

	return 0;
}