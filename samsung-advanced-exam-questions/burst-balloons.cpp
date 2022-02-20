#include <iostream>
using namespace std;

int N;
int coins[15];
int Ans;

int getSum(int l, int r, int n){
    int ms = 0;
    for(int i=l+1; i<r; i++){
        int cs = getSum(l, i, n) + getSum(i, r, n);
        if(l==0 && r==n){
            cs = cs + coins[i];
        }
        else{
            cs = cs + coins[l]*coins[r];
        }
        if(cs>ms){
            ms = cs;
        }
    }
    return ms;
}

int main() {
    scanf("%d", &N);
    for(int i=1; i<=N; i++){
        scanf("%d", &coins[i]);
    }
    coins[0] = coins[N+1] = 1;
    Ans = getSum(0, N+1, N+1);
    printf("%d\n", Ans);
    return 0;
}
