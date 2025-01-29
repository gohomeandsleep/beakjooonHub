#include <iostream>
#include <queue>
#include <functional>

using namespace std;

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    
	priority_queue<int> pq;

	int N;
	cin >> N;

	int k;
	for (int i = 0; i < N; i++) {
		cin >> k;
		if (k == 0) {
			if (pq.empty()) cout << 0 << "\n";
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else {
			pq.push(k);
		}
	}

	return 0;
}