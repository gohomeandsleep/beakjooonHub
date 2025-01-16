#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class UnionFind {
private:
	vector<int> parent, rank;
public:
	UnionFind(int n) {
		parent.resize(n);
		rank.resize(n, 0);
		for (int i = 0; i < n; i++) {
			parent[i] = i;
		}
	}

	int find(int x) {
		if (parent[x] != x) parent[x] = find(parent[x]);
		return parent[x];
	}

	void unite(int x, int y) {
		int rootX = find(x);
		int rootY = find(y);
		if (rootX != rootY) {
			if (rank[rootX] > rank[rootY]) parent[rootY] = rootX;
			else if (rank[rootY] > rank[rootX]) parent[rootX] = rootY;
			else {
				parent[rootY] = rootX;
				rank[rootX]++;
			}
		}
	}

	bool connect(int x, int y) {
		return find(x) == find(y);
	}
};


bool comp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
	return a.second < b.second;
}

int main() {
	int vertex, edge;
	cin >> vertex >> edge;

	vector<pair<pair<int, int>, int>> edges;
	for (int i = 0; i < edge; i++) {
		int s, e, w;
		cin >> s >> e >> w;
		edges.push_back({ {s, e}, w });
	}

	sort(edges.begin(), edges.end(), comp);

	int result = 0;
	UnionFind u(10001);

	for (int i = 0; i < edge; i++) {
		int st = edges[i].first.first;
		int ed = edges[i].first.second;
		int wt = edges[i].second;

		if (!u.connect(st, ed)) {
			result += wt;
			u.unite(st, ed);
		}
	}

	cout << result << endl;

	return 0;
}