#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int N, M, K;
int matrix[15][15];
int Ans;

void flip(int count) {
    if (count == K) {
        int sum = 0;
        int temp;
        for (int i = 0; i < N; i++) {
            temp = 0;
            for (int j = 0; j < M; j++) {
                if (matrix[i][j] == 1)
                    temp++;
            }
            if (temp == M)
                sum++;
        }
        if (sum > Ans)
            Ans = sum;
        return;
    }
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            matrix[j][i] = 1 - matrix[j][i];
        }
        flip(count + 1);
        for (int j = 0; j < N; j++) {
            matrix[j][i] = 1 - matrix[j][i];
        }
    }
}

int main()
{
    scanf("%d %d %d", &N, &M, &K);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    Ans = 0;
    flip(0);
    printf("%d", Ans);
    return 0;
}