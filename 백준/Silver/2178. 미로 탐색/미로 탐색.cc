#include <queue>
#include <vector>
#include <iostream>

using namespace std;

bool inRange(int y, int x, int h, int w) { //범위 내인지 확인
	return (x >= 0 && y >= 0 && x < w && y < h);
}

int main() {
	int h, w;
	cin >> h >> w;

	vector<vector<char>> miro(h);

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			char k;
			cin >> k;
			miro[i].push_back(k);
		}
	}

	queue<pair<pair<int, int>, int>> q; //좌표, 이동 횟수
	q.push({ {0,0}, 0 });

	vector<int> dx, dy;

	dx.push_back(1);
	dx.push_back(-1);
	dx.push_back(0);
	dx.push_back(0);

	dy.push_back(0);
	dy.push_back(0);
	dy.push_back(1);
	dy.push_back(-1);

	while (!q.empty()) {
		pair<pair<int, int>, int> front = q.front();
		int att = front.second + 1;
		int y = front.first.first;
		int x = front.first.second;
		//cout << y << x << "(" << att << ")" << endl;
		miro[y][x] = '2'; // 방문한 지점 2 처리 ->중복 방문 X
		q.pop();

		if (x == w - 1 && y == h - 1) {
			cout << att;
			return 0;
		}

		for (int i = 0; i < 4; i++) {
			//cout << "check" << y + dy[i] << " : "  << x + dx[i] << endl;
			if (inRange(y + dy[i], x + dx[i], h, w) && miro[y + dy[i]][x + dx[i]] == '1') {
				q.push({ {y + dy[i], x + dx[i]}, att });
				miro[y + dy[i]][x + dx[i]] = '2';
				//cout << y + dy[i] << ", " << x + dx[i] << "추가" << endl;
			}
		}
		//system("pause");
	}

	return 0;
}