#include <iostream>
#include <vector>

using namespace std;

class Union {
private:
	vector<int> parent, rank;
public:
	//생성자
	Union(int n) {
		parent.resize(n);
		rank.resize(n);
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
			else if (rank[rootX] < rank[rootY]) parent[rootX] = rootY;
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

int main() {
	int vertex, edge;
	cin >> vertex >> edge;

	Union u(1000);

	for (int i = 0; i < edge; i++) {
		int x, y;
		cin >> x >> y;
		u.unite(x, y);
	}

	vector<int> result;
	int reduct = 0;

	for (int i = 0; i < 1000; i++) {
		bool isValid = true;
		for (int j = 0; j < result.size(); j++) {
			if (u.connect(result[j], i)) {
				isValid = false;
				reduct++;
			}
		}
		if (isValid) {
			result.push_back(i);
		}
		
	}

	cout << vertex - reduct << endl;

	return 0;

}