#include <iostream>
#include <vector>

using namespace std;

int main()
{
    while (true){
        int N;
        cin >> N;
        if (N == 0) break;
        vector<int> arr;
        for (int i = 0; i < N; i++){
            int k;
            cin >> k;
            arr.push_back(k);
        }
        for (int i = 0; i < N; i++){
            for (int j = i + 1; j < N; j++){
                for (int k = j + 1; k < N; k++){
                    for (int l = k + 1; l < N; l++){
                        for (int m = l + 1; m < N; m++){
                            for (int n = m + 1; n < N; n++){
                                cout << arr[i] << " " << arr[j] << " " << arr[k] << " " << arr[l] << " " << arr[m] << " " << arr[n] << endl;
                            }
                        }
                    }
                }
            }
        }
        cout << endl;
    }
    
    return 0;
}