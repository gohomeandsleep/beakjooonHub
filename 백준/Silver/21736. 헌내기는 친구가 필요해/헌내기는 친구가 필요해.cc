#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

bool inRange(int y, int x, int height, int width) {
	return y >= 0 && x >= 0 && y < height && x < width;
}

int main() {
	int height, width;
	cin >> height >> width;

	vector<vector<char>> arr(height);

	int x, y;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			char k;
			cin >> k; 
			if (k == 'I') {
				y = i;
				x = j;
			}
			arr[i].push_back(k);
		}
	}

	int result = 0;
	queue<pair<int, int>> q;
	q.push({ y,x });

	while (!q.empty()) {
		int nextY = q.front().first;
		int nextX = q.front().second;
		arr[nextY][nextX] = 'V';
		q.pop();
		for (int i = 0; i < 4; i++) {
			if (inRange(nextY + dy[i], nextX + dx[i], height, width) && arr[nextY + dy[i]][nextX + dx[i]] != 'X' && arr[nextY + dy[i]][nextX + dx[i]] != 'V') {
				if (arr[nextY + dy[i]][nextX + dx[i]] == 'P') result += 1;
				q.push({ nextY + dy[i], nextX + dx[i] });
				arr[nextY + dy[i]][nextX + dx[i]] = 'V';
			}
		}
	}

	if (result == 0) cout << "TT" << endl;
	else cout << result << endl;

	return 0;
}