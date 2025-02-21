#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int result = 0;
int N;

void dfs(const vector<pair<int, int>> &arr, int d, int r){
    if (d + arr[d].first == N){ //terminate condition 1 - sangdam O
        result = max(result, r + arr[d].second);
    }
    if (d + 1 == N){ //terminate condition 1 - sangdam X
        result = max(result, r);
    }
    if (d + arr[d].first < N){ //sangdam O
        dfs(arr, d + arr[d].first, r + arr[d].second);
    }
    if (d + 1 < N){ //sangdam X
        dfs(arr, d + 1, r);
    }
}

int main(){
    cin >> N;
    
    vector<pair<int, int>> arr;
    int day, reward;
    for (int i = 0; i < N; i++){
        cin >> day >> reward;
        arr.push_back({day, reward});
    }
    
    dfs(arr, 0, 0);
    
    cout<< result << endl;
    
    return 0;
}