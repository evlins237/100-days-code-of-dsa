#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

typedef struct {
    int arr[MAX];
    int front;
    int rear;
    int size;
} Deque;

void init(Deque *dq) {
    dq->front = -1;
    dq->rear = -1;
    dq->size = 0;
}

int isEmpty(Deque *dq) {
    return dq->size == 0;
}

int isFull(Deque *dq) {
    return dq->size == MAX;
}

void push_front(Deque *dq, int val) {
    if (isFull(dq)) return;
    if (isEmpty(dq)) {
        dq->front = dq->rear = 0;
    } else {
        dq->front = (dq->front - 1 + MAX) % MAX;
    }
    dq->arr[dq->front] = val;
    dq->size++;
}

void push_back(Deque *dq, int val) {
    if (isFull(dq)) return;
    if (isEmpty(dq)) {
        dq->front = dq->rear = 0;
    } else {
        dq->rear = (dq->rear + 1) % MAX;
    }
    dq->arr[dq->rear] = val;
    dq->size++;
}

void pop_front(Deque *dq) {
    if (isEmpty(dq)) return;
    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1;
    } else {
        dq->front = (dq->front + 1) % MAX;
    }
    dq->size--;
}

void pop_back(Deque *dq) {
    if (isEmpty(dq)) return;
    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1;
    } else {
        dq->rear = (dq->rear - 1 + MAX) % MAX;
    }
    dq->size--;
}

int front(Deque *dq) {
    if (isEmpty(dq)) return -1;
    return dq->arr[dq->front];
}

int back(Deque *dq) {
    if (isEmpty(dq)) return -1;
    return dq->arr[dq->rear];
}

int size(Deque *dq) {
    return dq->size;
}

void clear(Deque *dq) {
    dq->front = dq->rear = -1;
    dq->size = 0;
}

void reverse(Deque *dq) {
    int i = dq->front;
    int j = dq->rear;
    int count = dq->size;

    while (count > 1) {
        int temp = dq->arr[i];
        dq->arr[i] = dq->arr[j];
        dq->arr[j] = temp;

        i = (i + 1) % MAX;
        j = (j - 1 + MAX) % MAX;
        count -= 2;
    }
}

void sort(Deque *dq) {
    int temp[MAX];
    int idx = 0;

    int i = dq->front;
    for (int c = 0; c < dq->size; c++) {
        temp[idx++] = dq->arr[i];
        i = (i + 1) % MAX;
    }

    for (int i = 0; i < idx - 1; i++) {
        for (int j = 0; j < idx - i - 1; j++) {
            if (temp[j] > temp[j + 1]) {
                int t = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = t;
            }
        }
    }

    dq->front = 0;
    dq->rear = idx - 1;
    dq->size = idx;

    for (int i = 0; i < idx; i++) {
        dq->arr[i] = temp[i];
    }
}

void display(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Empty\n");
        return;
    }
    int i = dq->front;
    for (int c = 0; c < dq->size; c++) {
        printf("%d ", dq->arr[i]);
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    Deque dq;
    init(&dq);

    push_back(&dq, 10);
    push_back(&dq, 20);
    push_front(&dq, 5);
    push_front(&dq, 1);

    display(&dq);

    pop_front(&dq);
    pop_back(&dq);

    display(&dq);

    printf("%d\n", front(&dq));
    printf("%d\n", back(&dq));
    printf("%d\n", size(&dq));

    reverse(&dq);
    display(&dq);

    sort(&dq);
    display(&dq);

    clear(&dq);
    display(&dq);

    return 0;
}
