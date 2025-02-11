#include <iostream>
#include <vector>

using namespace std;

bool isOne(vector<vector<int>> arr, int N, int stx, int sty){
    int first = arr[stx][sty];
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if (first != arr[stx+i][sty+j]) return false;
        }
    }
    return true;
}

void print(vector<vector<int>> arr, int N, int stx, int sty){
    if (isOne(arr, N, stx, sty)) {
        cout << arr[stx][sty];
    }
    else{
        cout << "(";
        print(arr, N / 2, stx, sty);
        print(arr, N / 2, stx, sty  + N / 2);
        print(arr, N / 2, stx + N / 2 , sty);
        print(arr, N / 2, stx + N / 2, sty + N / 2);
        cout << ")";
    }
    
}

int main(){
    int N;
    cin >> N;
    
    vector<vector<int>> arr(N, vector<int> (N, 0));
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            char k;
            cin >> k;
            arr[i][j] = int(k - '0');
        }
    }
    
    print(arr, N, 0, 0);
}