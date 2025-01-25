#include <iostream>
#include <vector>

using namespace std;

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

bool inRange(int y, int x, int N) {
	return y >= 0 && x >= 0 && x < N && y < N;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	int k;
	cin >> k;

	//l4l0(l k00l4l l4j80m
	int direction = 0;
	int y = 0;
	int x = 0;

	int yy = 0;
	int xx = 0;

	vector<vector<int>> arr(N, vector<int> (N, 0));
	int tmp = N * N;
	if (k == tmp) {
		yy = 1;
		xx = 1;
	}
	arr[0][0] = tmp;
	while (tmp != 1) {
		if (inRange(y+dy[direction], x+dx[direction], N) &&
		        arr[y+dy[direction]][x+dx[direction]] == 0) {
			y += dy[direction];
			x += dx[direction];
			tmp--;
			arr[y][x] = tmp;
			if (tmp == k) {
				yy = y + 1;
				xx = x + 1;
			}
		}
		else {
			direction = (direction + 1) % 4;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << yy << " " << xx << endl;
}