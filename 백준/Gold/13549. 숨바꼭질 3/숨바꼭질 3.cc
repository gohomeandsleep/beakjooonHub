#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
	int stp, endp;
	cin >> stp >> endp;

	queue<pair<int, int>> move;

	if (stp == endp) {
		cout << 0 << endl;
		return 0;
	}

	vector<bool> visited(100001);
	if (stp >= 1) { //0 이상이 들어온 경우 -> 길이가 0인 모든 곳을 방문처리하고 큐에 추가
		for (int i = stp; i < 100001; i *= 2) {
			//cout << i << endl;
			visited[i] = 1;
			move.push({ i, 0 });
			if (i == endp) {
				cout << 0 << endl;
				return 0;
			}
		}
	}
	else { //0이 들어온 경우 
		move.push({ 0, 0 });
	}

	while (true) {
		pair<int, int> N = move.front();

		if (N.first * 2 == endp) {
			cout << N.second << endl;
			return 0;
		}

		if (N.first - 1 == endp || N.first + 1 == endp) {
			cout << N.second + 1 << endl;
			return 0;
		}

		if (0 <= N.first * 2 && N.first * 2 <= 100000 && !visited[N.first * 2]) {
			move.push({ N.first * 2, N.second });
			visited[N.first * 2] = 1;
		}
		if (0 <= N.first - 1 && N.first - 1 <= 100000 && !visited[N.first - 1]) {
			move.push({ N.first - 1, N.second + 1 });
			visited[N.first - 1] = 1;
		}
		if (0 <= N.first + 1 && N.first + 1 <= 100000 && !visited[N.first + 1]) {
			move.push({ N.first + 1, N.second + 1 });
			visited[N.first + 1] = 1;
		}

		
		move.pop();
	}

	return 0;
}