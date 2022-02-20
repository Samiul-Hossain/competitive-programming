#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int matrix[15][15];
int N, T;
int visited[15];
int Ans;

void init() {
    Ans = 99999;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i][j] = 0;
        }
        visited[i] = 0;
    }
}

void solve(int current, int vis, int sum) {
    if (vis == N) {
        sum += matrix[current][0];
        if (sum < Ans)
            Ans = sum;
        return;
    }
    for (int i = 0; i < N; i++) {
        if (visited[i] == 0) {
            visited[i] = 1;
            solve(i, vis + 1, sum + matrix[current][i]);
            visited[i] = 0;
        }
    }
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        init();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                scanf("%d", &matrix[i][j]);
            }
        }
        visited[0] = 1;
        solve(0, 1, 0);
        printf("%d\n", Ans);
    }
    return 0;
}