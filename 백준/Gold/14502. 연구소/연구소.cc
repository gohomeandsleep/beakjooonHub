#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

bool inRange(int y, int x, int h, int w) {
	return y >= 0 && x >= 0 && y < h && x < w;
}

int virus(vector<vector<int>> array, int i, int j, int k, int N, int M) {
	//add the wall in three place
	array[i / M][i % M] = 1;
	array[j / M][j % M] = 1;
	array[k / M][k % M] = 1;

	//make the queue and push virus location(2)
	queue<pair<int, int>> q;
	for (int a = 0; a < N; a++) { // y
		for (int b = 0; b < M; b++) { // x
			if (array[a][b] == 2) {
				//virus -> q.push
				q.push({a,b});
			}
		}
	}

	//bfs search
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		array[y][x] = 2;
		q.pop();
		for (int a = 0; a < 4; a++) {
			if (inRange(y+dy[a], x+dx[a], N, M) && array[y+dy[a]][x+dx[a]] == 0) {
				array[y+dy[a]][x+dx[a]] = 2;
				q.push({y+dy[a], x+dx[a]});
			}
		}
	}

	//return the amount of 0
	int tmpResult = 0;
	for (int a = 0; a < N; a++) { // y
		for (int b = 0; b < M; b++) { // x
			if (array[a][b] == 0) tmpResult += 1; 
		}
	}
    
    return tmpResult;
}

int main() {
	int N, M; //N -> y, M -> x
	cin >> N >> M;

	vector<vector<int>> array(N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int k;
			cin >> k;
			array[i].push_back(k);
		}
	}

	int result = 0;
	for (int i = 0; i < N * M; i++) {
		for (int j = i + 1; j < N * M; j++) {
			for (int k = j + 1; k < N * M; k++) {
				if (array[i / M][i % M] == 0 && array[j / M][j % M] == 0 && array[k / M][k % M] == 0 ) {
					result = max(result, virus(array, i, j, k, N, M));
				}
			}
		}
	}

	cout << result << endl;

	return 0;
}