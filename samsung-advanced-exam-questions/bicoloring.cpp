#include <iostream>
using namespace std;
int graph[55][55], color[50];
int N, l, ans;

void readCase(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            graph[i][j] = 0;
        }
        color[i] = 0;
    }
    cin >> l;
    int t1, t2;
    for(int i=0; i<l; i++){
        cin >> t1 >> t2;
        graph[t1][t2] = 1;
        graph[t2][t1] = 1;
    }
}

void solution(int current, int c){
    if(!color[current]){
        color[current] = c;
        for(int i=0; i<N; i++){
            if(graph[current][i]){
                if(c==1)
                    solution(i, 2);
                else solution(i, 1);
            }
        }
    }
    else if(color[current] != c){
        ans=0;
        return;
    }
}

void solve(){
    ans = 1;
    for(int i=0; i<N; i++){
        if(!color[i] && ans){
            solution(i, 1);
        }
    }
}

void printCase(){
    if(ans)
        cout << "BICOLORABLE." <<endl;
    else cout << "NOT BICOLORABLE." <<endl;
}

int main(){
    while(1){
        cin >> N;
        if(N==0)
            break;
        
        readCase();
        solve();
        printCase();
    }
}