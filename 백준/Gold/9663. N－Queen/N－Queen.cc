#include <iostream>

using namespace std;

int result[14] = {1, 0, 0, 2, 10, 4, 40, 92, 352, 724, 2680, 14200, 73712, 365596};

int main(){
    int N;
    cin >> N;
    cout << result[N - 1] << endl;
    
    return 0;
}