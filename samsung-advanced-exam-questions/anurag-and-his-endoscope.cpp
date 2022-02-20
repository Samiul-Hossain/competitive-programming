#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

struct Node {
    int x;
    int y;
    int l;
}q[100000];

int front, rear;

void initQueue() {
    front = rear = 0;
}

int isEmpty() {
    return front == rear;
}

void push(int a, int b, int len) {
    q[rear].x = a;
    q[rear].y = b;
    q[rear].l = len;
    rear++;
}

struct Node pop() {
    struct Node temp = q[front]; 
    front++;
    return temp;
}

int Ans;
int T;
int N, M, R, C, L;
int matrix[50][50];
int visited[50][50];

void init() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            matrix[i][j] = 0;
            visited[i][j] = 0;
        }
    }
}

void readCase() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d",&matrix[i][j]);
        }
    }
}

void bfs() {
    initQueue();
    visited[R][C] = 1;
    push(R, C, L-1);
    Ans++;
    while (!isEmpty()) {
        struct Node temp = pop();
        if (temp.l == 0)
            continue;
        int X = temp.x;
        int Y = temp.y;
        //up
        if (X - 1 >= 0 && !visited[X - 1][Y] && matrix[X-1][Y] != 0 && matrix[X][Y] != 3 && matrix[X][Y] != 5 && matrix[X][Y] != 6
            && matrix[X-1][Y] != 3 && matrix[X-1][Y] != 4 && matrix[X-1][Y] != 7) {
            visited[X - 1][Y] = 1;
            push(X - 1, Y, temp.l - 1);
            Ans++;
        }
        //right
        if (Y + 1 < M && !visited[X][Y+1] && matrix[X][Y+1] != 0 && matrix[X][Y] != 2 && matrix[X][Y] != 6 && matrix[X][Y] != 7
            && matrix[X][Y+1] != 2 && matrix[X][Y+1] != 4 && matrix[X][Y+1] != 5) {
            visited[X][Y + 1] = 1;
            push(X, Y + 1, temp.l - 1);
            Ans++;
        }
        //down
        if (X + 1 < N && !visited[X + 1][Y] && matrix[X + 1][Y] != 0 && matrix[X + 1][Y] != 3 && matrix[X + 1][Y] != 5 && matrix[X + 1][Y] != 6
            && matrix[X][Y] != 3 && matrix[X][Y] != 4 && matrix[X][Y] != 7) {
            visited[X + 1][Y] = 1;
            push(X + 1, Y, temp.l - 1);
            Ans++;
        }
        //left
        if (Y - 1 >= 0 && !visited[X][Y - 1] && matrix[X][Y - 1] != 0 && matrix[X][Y - 1] != 2 && matrix[X][Y - 1] != 6 && matrix[X][Y - 1] != 7
            && matrix[X][Y] != 2 && matrix[X][Y] != 4 && matrix[X][Y] != 5) {
            visited[X][Y - 1] = 1;
            push(X, Y - 1, temp.l - 1);
            Ans++;
        }
    }
}

void solve() {
    Ans = 0;
    if (L == 0)
        return;
    if (matrix[R][C] == 0)
        return;
    bfs();
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d %d %d", &N, &M, &R, &C, &L);
        init();
        readCase();
        solve();
        printf("%d\n", Ans);
    }
    return 0;
}