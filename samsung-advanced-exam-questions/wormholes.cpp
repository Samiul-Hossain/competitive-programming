#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int sx, sy, dx, dy, N, T, Ans;
int SX[10];
int SY[10];
int DX[10];
int DY[10];
int C[10];
int visited[10];

int abs(int a) {
    if (a < 0)
        return -a;
    return a;
}

void init() {
    Ans = 999999;
    for (int i = 0; i < N; i++) {
        visited[i] = 0;
    }
}

int getSum(int a, int b, int c, int d) {
    return abs(a - c) + abs(b - d);
}

void permute(int cx, int cy, int vis, int sum) {
    int temp = sum + abs(cx - dx) + abs(cy - dy);
    if (temp < Ans)
        Ans = temp;
    if (vis == N)
        return;
    for (int i = 0; i < N; i++) {
        if (visited[i] == 0) {
            visited[i] = 1;
            int temp = getSum(cx, cy, SX[i], SY[i]);
            permute(DX[i], DY[i], vis + 1, sum + temp + C[i]);
            temp = getSum(cx, cy, DX[i], DY[i]);
            permute(SX[i], SY[i], vis + 1, sum + temp + C[i]);
            visited[i] = 0;
        }
    }
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        scanf("%d %d %d %d", &sx, &sy, &dx, &dy);
        init();
        for (int i = 0; i < N; i++) {
            scanf("%d %d %d %d %d", &SX[i], &SY[i], &DX[i], &DY[i], &C[i]);
        }
        permute(sx, sy, 0, 0);
        printf("%d\n", Ans);
    }
    return 0;
}