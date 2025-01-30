#include <iostream>
#include <vector>

using namespace std;

int blue = 0;
int white = 0;

bool isOne(vector<vector<int>> &arr, int N, int stpy, int stpx) {
    //debug
     //std::cin.get();
     //for (int i = stpy; i < stpy + N; i++){
     //    for (int j = stpx; j < stpx + N; j++){
     //        cout << arr[i][j] << " ";
     //    }
     //    cout << endl;
     //}

    int result = arr[stpy][stpx];
    for (int i = stpy; i < stpy + N; i++) {
        for (int j = stpx; j < stpx + N; j++) {
            if (arr[i][j] != result) return false;
        }
    }
    return true;
}

void find(vector<vector<int>> &arr, int N, int stpy, int stpx) {
    //array, total size, start point
    if (isOne(arr, N, stpy, stpx)) {
        if (arr[stpy][stpx] == 1) blue += 1;
        else white += 1;
        return;
    }
    else {
        find(arr, N / 2, stpy, stpx);
        find(arr, N / 2, stpy + N / 2, stpx);
        find(arr, N / 2, stpy, stpx + N / 2);
        find(arr, N / 2, stpy + N / 2, stpx + N / 2);
    }
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    int k;
    vector<vector<int>> arr(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    find(arr, N, 0, 0);

    cout << white << "\n" << blue << endl;

    return 0;
}