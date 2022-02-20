#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int T, N;
int matrix[15][5];
int visited[15][5];
int Ans;
int Y[] = { -1, 0, 1 };

void init() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 5; j++) {
            matrix[i][j] = 0;
            visited[i][j] = 0;
        }
    }
}

void readCase() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 5; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void fill(int cx, int cy, int bomb, int free, int sum) {
    if (cx == 0) {
        if (sum > Ans)
            Ans = sum;
        return;
    }
    int x = cx - 1, y;
    for (int i = 0; i < 3; i++) {
        y = cy + Y[i];
        if (x >= 0 && y >= 0 && y < 5 && matrix[x][y] == 2) {
            if (free > 0) {
                fill(x, y, bomb, free - 1, sum);
            }
            else if (bomb == 1) {
                fill(x, y, 0, 4, sum);
            }
            else {
                if (sum > Ans)
                    Ans = sum;
                return;
            }
        }
        else if (x >= 0 && y >= 0 && y < 5 && (matrix[x][y] == 0 || matrix[x][y] == 1)) {
            if(free>0)
                fill(x, y, bomb, free - 1, sum + matrix[x][y]);
            else
                fill(x, y, bomb, free, sum + matrix[x][y]);
        }
    }
}

int main()
{
    scanf("%d", &T);
    int count = 1;
    while (T--) {
        Ans = 0;
        scanf("%d", &N);
        init();
        readCase();
        fill(N, 2, 1, 0, 0);
        printf("#%d %d\n", count, Ans);
        count++;
    }
    return 0;
}