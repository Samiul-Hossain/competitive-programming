#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int N, E, cycleSum, answerSize, top;
int visited[11];
int graph[11][11];
int answer[11];
int stack[11];

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void init() {
    top = -1;
    answerSize = -1;
    cycleSum = 999999;
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            graph[i][j] = 0;
        }
        answer[i] = 0;
        visited[i] = 0;
        stack[i] = 0;
    }
}

void isCycle(int current) {
    if (visited[current] == 1 && top >= 0) {
        int localSum = stack[top];
        for (int i = top - 1; i >= 0 && stack[i] != current; i--) {
            localSum += stack[i];
        }
        if (localSum < cycleSum) {
            cycleSum = localSum;
            answerSize = -1;
            answer[++answerSize] = stack[top];
            for (int i = top - 1; i >= 0 && stack[i] != current; i--) {
                answer[++answerSize] = stack[i];
            }
        }
        return;
    }
    else {
        visited[current] = 1;
        for (int i = 1; i <= N; i++) {
            if (graph[current][i] == 1) {
                stack[++top] = i;
                isCycle(i);
                top--;
            }
        }
        visited[current] = 0;
    }
}

void bubbleSort() {
    for (int i = 0; i <= answerSize; i++) {
        for (int j = 0; j <= answerSize - 1; j++) {
            if (answer[j] > answer[j + 1]) {
                swap(&answer[j], &answer[j + 1]);
            }
        }
    }
}

void printArray() {
    for (int i = 0; i <= answerSize; i++) {
        printf("%d ", answer[i]);
    }
}

int main()
{
    int temp1, temp2;
    scanf("%d %d", &N, &E);
    init();
    for (int i = 1; i <= E; i++) {
        scanf("%d %d", &temp1, &temp2);
        graph[temp1][temp2] = 1;
    }
    for (int i = 1; i <= N; i++) {
        if (visited[i] == 0) {
            stack[++top] = i;
            isCycle(i);
            top--;
        }
    }
    bubbleSort();
    printArray();
    return 0;
}