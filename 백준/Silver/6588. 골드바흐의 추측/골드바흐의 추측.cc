#include <iostream>
#include <cstdio>

using namespace std;

bool prime[1000001];

int main(){
    
    //prime
    prime[0] = 0;
    prime[1] = 0;
    for (int i = 2; i < 1000001; i++){
        prime[i] = 1;
    }
    
    for (int i = 2; i < 1001; i++){
        if (prime[i] == 1){
            for (int j = 2; j *  i < 1000001; j++){
                prime[i*j] = 0;
            }
        }
    }
    
    int k;
    while (true){
        scanf("%d", &k);
        if (k == 0) break;
        for (int i = 3; i <= k / 2; i++){
            if (prime[i] && prime[k - i]){
                printf("%d = %d + %d\n", k, i, k-i);
                break;
            }
        }
        
    }
    
    return 0;
}