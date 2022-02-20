#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int matrix[20][20];
int visited[20][20];
int N, M, flag = 0;

void init() {
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            visited[i][j] = 0;
        }
    }
}

void fill(int cx, int cy, int l) {
    if (matrix[cx][cy] == 3) {
        flag = 1;
        return;
    }
    if (cy - 1 >= 0 && matrix[cx][cy - 1] != 0 && !visited[cx][cy - 1]) {
        visited[cx][cy - 1] = 1;
        fill(cx, cy - 1, l);
    }
    if (cy + 1 < M && matrix[cx][cy + 1] != 0 && !visited[cx][cy + 1]) {
        visited[cx][cy + 1] = 1;
        fill(cx, cy + 1, l);
    }
    for (int i = 1; i <= l; i++) {
        if (cx + i < N && matrix[cx + i][cy] != 0 && !visited[cx + i][cy]) {
            visited[cx + i][cy] = 1;
            fill(cx + i, cy, l);
        }
    }
    for (int i = 1; i <= l; i++) {
        if (cx - i >= 0 && matrix[cx - i][cy] != 0 && !visited[cx - i][cy]) {
            visited[cx - i][cy] = 1;
            fill(cx - i, cy, l);
        }
    }
}

int main()
{
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    init();
    visited[N-1][0] = 1;
    for (int i = 0; i < N; i++) {
        fill(N - 1, 0, i);
        init();
        if (flag) {
            printf("%d\n", i);
            break;
        }
    }
    return 0;
}
