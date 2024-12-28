#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	queue<int> removeEdge;
	vector<int> Edge;

	int root = -1;
	for (int i = 0; i < N; i++) {
		int E;
		cin >> E;
		Edge.push_back(E);
		if (E == -1) root = i;
	}

	int RE;
	cin >> RE;
	Edge[RE] = -10;
	removeEdge.push(RE);
	while (!removeEdge.empty()) {
		int k = removeEdge.front();
		for (int i = 0; i < Edge.size(); i++) {
			if (Edge[i] == k) {
				removeEdge.push(i);
				Edge[i] = -10;
			}
		}
		removeEdge.pop();
	}

	vector<vector<int>> array(N+1);

	for (int i = 0; i < N; i++) {
		int E = Edge[i];
		if (E >= 0) {
			array[E].push_back(i);
			array[i].push_back(E);
		}
	}

	//리프 노드를 더해줌
	int res = 0;
	for (int i = 0; i < N; i++) {
		if (array[i].size() == 1) res += 1;
	}
	
	//루트 노드의 자식이 1개면 결과에서 하나를 제거 
	int freq = 0;
	for (int i = 0; i < N; i++) {
		if (Edge[i] == root) freq += 1;
	}
	if (freq == 1 && array[root].size() > 0) res -= 1;

	if (res == 0 && root != RE) cout << 1;
	else cout << res;

	return 0;
}