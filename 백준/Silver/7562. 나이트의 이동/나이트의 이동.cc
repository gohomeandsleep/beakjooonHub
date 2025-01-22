#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int dy[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int dx[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

bool inRange(int y, int x, int n) {
	return y >= 0 && x >= 0 && y < n && x < n;
}

int main() {
	int testCase;
	cin >> testCase;

	for (int i = 0; i < testCase; i++) {
		int N; //전체 격자의 크기
		cin >> N;
		vector<vector<int>> visit(N, vector<int>(N, 0));
		int stpX, stpY; // 시작 지점
		cin >> stpY >> stpX;
		int endX, endY; //끝 지점
		cin >> endY >> endX;
		//시작점과 끝점이 같을 경우 종료 조건
		if (stpX == endX && stpY == endY) {
			cout << 0 << endl;
			continue;
		}
		queue<pair<pair<int, int>, int>> q;
		q.push({ { stpY, stpX }, 0 });
		bool isFind = false;
		while (!isFind) {
			int nextY = q.front().first.first;
			int nextX = q.front().first.second;
			int k = q.front().second;
			visit[nextY][nextX] = -1;
			q.pop();
			for (int i = 0; i < 8; i++) {
				int locY = nextY + dy[i];
				int locX = nextX + dx[i];
				if (locY == endY && locX == endX) {
					cout << k + 1 << endl;
					isFind = true;
				}
				if (inRange(locY, locX, N) && visit[locY][locX] == 0) {
					visit[locY][locX] = -1;
					q.push({ {locY, locX}, k + 1 });
				}
			}
		}

	}

	return 0;
}