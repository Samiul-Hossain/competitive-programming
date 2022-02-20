#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int N;
int gates[4];
int fisherman[4];
int visited[11];
int Ans;

int abs(int a) {
    if (a < 0)
        return -a;
    return a;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void init() {
    Ans = 999999;
    for (int i = 0; i < N; i++) {
        visited[i] = i + 1;
    }
}

void permute(int l, int r) {
    if (l == r) {
        int i, j, k, dist = 0;
        for (i = 0; i < fisherman[0]; i++) {
            dist += abs(visited[i] - gates[0]);
        }
        for (j = 0; j < fisherman[1]; j++) {
            dist += abs(visited[i] - gates[1]);
            i++;
        }
        for (k = 0; k < fisherman[2]; k++) {
            dist += abs(visited[i] - gates[2]);
            i++;
        }
        dist += i;
        if (dist < Ans)
            Ans = dist;
        return;
    }
    for (int i = l; i <= r; i++) {
        swap(&visited[l], &visited[i]);
        permute(l + 1, r);
        swap(&visited[l], &visited[i]);
    }

}

int main()
{
    scanf("%d", &N);
    init();
    for (int i = 0; i < 3; i++) {
        scanf("%d", &gates[i]);
    }
    for (int i = 0; i < 3; i++) {
        scanf("%d", &fisherman[i]);
    }
    permute(0, N - 1);
    printf("%d\n", Ans);
    return 0;
}