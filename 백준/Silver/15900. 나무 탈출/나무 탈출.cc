#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int N;
	cin >> N;

	vector<vector<int>> tree(N + 1, vector<int>(0));

	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	vector<int> visited(N + 1, -1);
	queue<pair<int, int>> q;
	q.push({1, 0});
	visited[1] = 0;
	
	int res = 0;
	while (q.size() != 0) {
		pair<int, int> p = q.front();
		int k = p.first;
		int depth = p.second;
		bool isVisited = false;
		for (int i = 0; i < tree[k].size(); i++) {
			int tmp = tree[k][i];
			if (visited[tmp] == -1) {
				isVisited = true;
				visited[tmp] = 0;
				q.push({ tmp, depth + 1 });
			}
		}
		if (isVisited == false) res += depth;
		
		q.pop();
		//cout << q.size() << endl;
	}

	if (res % 2 == 0) {
		cout << "No";
	}
	else {
		cout << "Yes";
	}
	

	return 0;
}