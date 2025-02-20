#include <iostream>

using namespace std;

int main(){
    int TC;
    cin >> TC;
    
    for (int i = 0; i < TC; i++){
        int a, b;
        cin >> a >> b;
        
        int tmp = a;
        for (int i = 0; i < b - 1; i++){
            tmp = (tmp * a) % 10; 
        }
        
        if (tmp % 10 == 0) cout << 10 << endl;
        else cout << tmp % 10 << endl;
    }
}