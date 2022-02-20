#include <iostream>
using namespace std;

int n, m, answer;
int company[10], oil[10];

int MIN(int x, int y){
    if(x<y) return x;
    else return y;
}

int MAX(int x, int y){
    if(x>y) return x;
    else return y;
}

void getMinDiff(){
    int mini = 9999;
    int maxi = 0;
    for(int i=0; i<n; i++){
        mini = MIN(mini, company[i]);
        maxi = MAX(maxi, company[i]);
    }
    if((maxi-mini) <answer)
        answer = maxi-mini;
}

void solution(int last, int current, int num){
    if((current+1)%m == last){
        for(int i=num; i<n; i++){
            company[i] += oil[current];
            getMinDiff();
            company[i] -= oil[current];
        }
        return;
    }
    if(num == n){
        return;
    }
    company[num] += oil[current];
    solution(last, (current+1)%m, num);
    company[num] -= oil[current];
    solution(last, current, num+1);
}

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        cin >> n >>m;
        for(int i=0; i<m; i++){
            cin >> oil[i];
        }
        for(int i=0; i<n; i++){
            company[i] = 0;
        }
        answer = 9999;
        for(int i=0; i<m; i++){
            solution(i, i, 0);
        }
        cout << answer << endl;
    }

}