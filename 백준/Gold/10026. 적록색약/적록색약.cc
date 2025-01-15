#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool inRange(int y, int x, int n) {
	return y >= 0 && x >= 0 && y < n && x < n;
}

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void visit(vector<vector<char>>& grid, int y, int x, int n) {
	char what = grid[y][x];
	queue<pair<int, int>> q; //방문처리할 큐
	q.push({ y, x });
	while (!q.empty()) {
		int nextY = q.front().first;
		int nextX = q.front().second;
		grid[nextY][nextX] = 'V';
		q.pop();
		for (int i = 0; i < 4; i++) {
			if (inRange(nextY + dy[i], nextX + dx[i], n) && grid[nextY + dy[i]][nextX + dx[i]] == what) {
				grid[nextY + dy[i]][nextX + dx[i]] = 'V';
				q.push({ nextY + dy[i], nextX + dx[i] });
			}
		}
	}
}

int main() {
	int N;
	cin >> N;

	vector<vector<char>> grid(N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			char k;
			cin >> k;
			grid[i].push_back(k);
		}
	}

	vector<vector<char>> gridNormal = grid;
	int normal = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (gridNormal[i][j] != 'V') {
				normal++;
				visit(gridNormal, i, j, N);
			}
		}
	}

	cout << normal << " ";
	
	vector<vector<char>> gridYak = grid;
	int yak = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (gridYak[i][j] == 'G') gridYak[i][j] = 'R';
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (gridYak[i][j] != 'V') {
				yak++;
				visit(gridYak, i, j, N);
			}
		}
	}

	cout << yak << endl;
}