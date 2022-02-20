#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int rare[5][2];
int T, N, R;
int matrix[22][22];
int visited[22][22];
int Ans;
int X[] = { 0, 0, 1, -1 };
int Y[] = { 1, -1, 0, 0 };
int front, rear;

struct Node {
	int x;
	int y;
	int l;
}q[10000];

void initQueue() {
	front = 0;
	rear = 0;
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

void init() {
	Ans = 999999;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			matrix[i][j] = 0;
			visited[i][j] = 0;
		}
	}
}

void initV() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j] = 0;
		}
	}
}

int bfs(int cx, int cy, int dx, int dy) {
	int a, b;
	push(cx, cy, 0);
	visited[cx][cy] = 1;
	while (!isEmpty()) {
		struct Node temp = pop();
		if (temp.x == dx && temp.y == dy) {
			return temp.l;
		}
		for (int i = 0; i < 4; i++) {
			a = temp.x + X[i];
			b = temp.y + Y[i];
			if (a >= 0 && b >= 0 && a < N && b < N && matrix[a][b] != 0 && visited[a][b] == 0) {
				visited[a][b] = 1;
				push(a, b, temp.l + 1);
			}
		}
	}
	return 0;
}

int main()
{
	scanf("%d", &T);
	while (T--) {
		int a, b;
		scanf("%d %d", &N, &R);
		init();
		for (int i = 0; i < R; i++) {
			scanf("%d %d", &a, &b);
			rare[i][0] = a-1;
			rare[i][1] = b-1;
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &matrix[i][j]);
			}
		}
		for (int i = 0; i < R; i++) {
			matrix[rare[i][0]][rare[i][1]] = 3;
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				int temp1;
				if (matrix[i][j] == 1) {
					temp1 = 0;
					for (int k = 0; k < R; k++) {
						initV();
						initQueue();
						int temp2 = bfs(i, j, rare[k][0], rare[k][1]);
						if (temp2 > temp1) {
							temp1 = temp2;
						}
					}
					if (temp1 < Ans) {
						Ans = temp1;
					}
				}
			}
		}
		printf("%d\n", Ans);
	}
	return 0;
}
