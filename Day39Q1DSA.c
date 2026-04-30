#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100000

int heap[MAX];
int size = 0;

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void heapifyUp(int i) {
    while (i > 0) {
        int p = (i - 1) / 2;
        if (heap[p] > heap[i]) {
            swap(&heap[p], &heap[i]);
            i = p;
        } else break;
    }
}

void heapifyDown(int i) {
    while (1) {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int s = i;

        if (l < size && heap[l] < heap[s]) s = l;
        if (r < size && heap[r] < heap[s]) s = r;

        if (s != i) {
            swap(&heap[i], &heap[s]);
            i = s;
        } else break;
    }
}

void insert(int x) {
    heap[size] = x;
    heapifyUp(size);
    size++;
}

int peek() {
    if (size == 0) return -1;
    return heap[0];
}

int extractMin() {
    if (size == 0) return -1;
    int root = heap[0];
    heap[0] = heap[size - 1];
    size--;
    heapifyDown(0);
    return root;
}

int main() {
    int n;
    scanf("%d", &n);

    while (n--) {
        char op[20];
        scanf("%s", op);

        if (strcmp(op, "insert") == 0) {
            int x;
            scanf("%d", &x);
            insert(x);
        } else if (strcmp(op, "peek") == 0) {
            printf("%d\n", peek());
        } else if (strcmp(op, "extractMin") == 0) {
            printf("%d\n", extractMin());
        }
    }

    return 0;
}
