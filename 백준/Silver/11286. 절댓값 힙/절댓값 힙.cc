#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

struct customCompare {
    bool operator()(int a, int b) {
        if (abs(a) == abs(b)) return a > b;
        return abs(a) > abs(b); 
    }
};

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    
    priority_queue<int, vector<int>, customCompare> pq;

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