#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<vector<int>> tree(N + 1);

	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int a, b;
		cin >> a >> b;
		if (a == 2) cout << "yes" << "\n";
		else {
			if (tree[b].size() >= 2) cout << "yes" << "\n";
			else cout << "no" << "\n";
		}
	}

	return 0;
}