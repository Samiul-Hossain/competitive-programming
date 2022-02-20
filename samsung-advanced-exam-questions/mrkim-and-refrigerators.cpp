#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int N;
int X[15];
int Y[15];
int Ans;
int visited[15];
int sx, sy, dx, dy;

int abs(int a) {
    if (a < 0)
        return -a;
    return a;
}

void init() {
    Ans = 999999;
    for (int i = 0; i < N; i++) {
        visited[i] = 0;
        X[i] = 0;
        Y[i] = 0;
    }
}

void tsp(int cx, int cy, int vis, int sum) {
    if (vis == N) {
        sum += abs(cx - dx) + abs(cy - dy);
        if (sum < Ans)
            Ans = sum;
        return;
    }
    for (int i = 0; i < N; i++) {
        if (visited[i] == 0) {
            visited[i] = 1;
            tsp(X[i], Y[i], vis + 1, sum + abs(cx-X[i]) + abs(cy-Y[i]));
            visited[i] = 0;
        }
    }
}

int main()
{
    int T = 10;
    int count = 1;
    while (T--) {
        scanf("%d", &N);
        init();
        scanf("%d %d %d %d", &sx, &sy, &dx, &dy);
        for (int i = 0; i < N; i++) {
            scanf("%d %d", &X[i], &Y[i]);
        }
        tsp(sx, sy, 0, 0);
        printf("# %d %d\n", count, Ans);
        count++;
    }
    return 0;
}