#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

bool inRange(int y, int x, int h, int w) {
	return x >= 0 && y >= 0 && x < w && y < h;
}

void bug(vector<vector<int>>& baat, int y, int x, int h, int w) {
	queue<pair<int, int>> q; //(y, x) 좌표 담는 공간
	q.push({ y, x });
	while (!q.empty()) {
		pair<int, int> fr = q.front();
		int nextY = fr.first;
		int nextX = fr.second;
		q.pop();
		if (baat[nextY][nextX] == 2) continue;
		baat[nextY][nextX] = 2;
		for (int i = 0; i < 4; i++) {
			if (inRange(nextY + dy[i], nextX + dx[i], h, w) && baat[nextY + dy[i]][nextX + dx[i]] == 1) {
				q.push({ nextY + dy[i], nextX + dx[i] });
			}
		}
	}
}

int main() {
	int testCase;
	cin >> testCase;

	for (int i = 0; i < testCase; i++) {
		int result = 0;
		//길이 높이 배추의 개수 입력
		int width, height, k;
		cin >> width >> height >> k;

		//밭 초기화
		vector<vector<int>> baat(height);
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				baat[i].push_back(0);
			}
		}

		//입력에 따라 밭에 배추 심음
		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> x >> y;
			baat[y][x] = 1;
		}

		//배열 전체를 순회하며 방문 처리
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if (baat[i][j] == 1) {
					result += 1;
					bug(baat, i, j, height, width);
				}
			}
		}

		cout << result << endl;
	}

	

	return 0;
}