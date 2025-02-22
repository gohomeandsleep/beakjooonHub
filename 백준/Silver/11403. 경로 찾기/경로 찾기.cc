#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;

void checkVisit(const vector<vector<int>> &arr, int start) {
	vector<int> visited(N, 0);
	queue<int> q;
	for (int i = 0; i < N; i++) {
		if (arr[start][i] == 1) {
			visited[i] = 1;
			q.push(i);
		}
	}

	while (!q.empty()) {
		int tmp = q.front();
		q.pop();
		for (int i = 0; i < N; i++) {
			if (arr[tmp][i] == 1 && !visited[i]) {
				visited[i] = 1;
				q.push(i);
			}
		}
	}

	for (int i = 0; i < N; i++) {
		cout << visited[i] << " ";
	}
	cout << endl;
}

int main() {
	cin >> N;

	vector<vector<int>> arr(N, vector<int> (N, 0));
	int k;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> k;
			arr[i][j] = k;
		}
	}

	for (int i = 0; i < N; i++) {
		checkVisit(arr, i);
	}

	return 0;
}