#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int queue[MAX];
int front = 0, rear = -1;

int stack[MAX];
int top = -1;

void enqueue(int x) {
    queue[++rear] = x;
}

int dequeue() {
    return queue[front++];
}

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int isQueueEmpty() {
    return front > rear;
}

int isStackEmpty() {
    return top == -1;
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        enqueue(x);
    }

    while (!isQueueEmpty())
        push(dequeue());

    while (!isStackEmpty())
        enqueue(pop());

    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);

    return 0;
}
