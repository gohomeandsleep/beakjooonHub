#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;



int main(){
    cin >> N;
    
    vector<int> result;
    int k;
    for (int i = 0; i < N; i++){
        cin >> k;
        if (i == 0) { //first value -> push_back
            result.push_back(k);
            continue;
        } //
        if (k > result[result.size() - 1]){

            result.push_back(k);
        }
        for (int j = 0; j < result.size(); j++){
            if (k == result[j]) break;
            else if (k < result[j]) {
                result[j] = k;
                break;
            }
        }
        

    }
    
    cout << result.size() << endl;
    
    return 0;
}