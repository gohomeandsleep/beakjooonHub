#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int height, width, result, maxValue;

int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

bool inRange(int y, int x) {
	return y >= 0 && x >= 0 && y < height && x < width;
}

void dfs(const vector<vector<int>> &arr, int y, int x, vector<vector<bool>> &visited, int depth, int psum) {
	if (psum + (3 - depth) * maxValue <= result)
		return;
	if (depth == 3) {
		result = max(result, psum);
		return;
	}
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (inRange(ny, nx) && !visited[ny][nx]) {
			visited[ny][nx] = 1;
			dfs(arr, ny, nx, visited, depth + 1, psum + arr[ny][nx]);
			visited[ny][nx] = 0;
		}
	}
}

void bob(const vector<vector<int>> &arr, int y, int x) { //
	vector<int> avail;
	int psum = arr[y][x];
	int n = 0;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (inRange(ny, nx)) {
			n++;
			psum += arr[ny][nx];
			avail.push_back(arr[ny][nx]);
		}
	}

	if (n == 4) {
		result = max(result, psum - *min_element(avail.begin(), avail.end()));
	}
	else if (n == 3) {
		result = max(result, psum);
	}
}

int main() {
	scanf("%d %d", &height, &width);

	vector<vector<int>> arr(height, vector<int> (width, 0));
	int k;

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			scanf("%d", &k);
			arr[i][j] = k;
		}
	}

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			maxValue = max(maxValue, arr[i][j]);
		}
	}

	vector<vector<bool>> visited(height, vector<bool> (width, false));
	result = 0;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			visited[i][j] = 1;
			dfs(arr, i, j, visited, 0, arr[i][j]);
			bob(arr, i, j);
			visited[i][j] = 0;
		}
	}

	printf("%d", result);

	return 0;
}