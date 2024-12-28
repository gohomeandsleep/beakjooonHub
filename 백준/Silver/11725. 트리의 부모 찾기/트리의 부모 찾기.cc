#include <iostream>
#include <vector>
#include <queue>

using namespace std; 

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
	int N;
	cin >> N;

    vector<vector<int>> tree(N, vector<int>(0));

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a - 1].push_back(b - 1);
        tree[b - 1].push_back(a - 1);
    }

    vector<int> parent(N, -1);

    queue<int> q;
    vector<int> visited(N, 0);
    q.push(0);
    visited[0] = 1;

    //cout << q.size() << endl;
    while (q.size() != 0) {
        int k = q.front();
        //cout << "검색하는 수 : " << k + 1 << endl;
        for (int i = 0; i < tree[k].size(); i++) {
            int tmp = tree[k][i];
            //cout << tmp << endl;
            if (visited[tmp] == 0) {
                parent[tmp] = k + 1;
                visited[tmp] = 1;
                //cout <<  "추가되는 수 : " << i + 1 << endl;
                q.push(tmp);
            }
        }
        q.pop();
        //system("pause");
    }

    for (int i = 1; i < N; i++) {
        cout << parent[i] << "\n";
    }

	return 0;
}