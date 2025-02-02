#include <cstdio>

int main(){
    
    int N;
    scanf("%d", &N);
    
    int no = 0;
    int k;
    for (int i = 0; i < N; i++){
        scanf("%d", &k);
        if (!k) no++;
    }
    
    if (no > N / 2) printf("Junhee is not cute!\n");
    else printf("Junhee is cute!\n");
    
    return 0;
}