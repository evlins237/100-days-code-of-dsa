 #include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start, end;
} Interval;

int cmpStart(const void *a, const void *b) {
    return ((Interval *)a)->start - ((Interval *)b)->start;
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void heapifyUp(int heap[], int i) {
    while (i > 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(&heap[(i - 1) / 2], &heap[i]);
        i = (i - 1) / 2;
    }
}

void heapifyDown(int heap[], int size, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left] < heap[smallest])
        smallest = left;
    if (right < size && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(heap, size, smallest);
    }
}

void push(int heap[], int *size, int val) {
    heap[*size] = val;
    (*size)++;
    heapifyUp(heap, *size - 1);
}

void pop(int heap[], int *size) {
    heap[0] = heap[*size - 1];
    (*size)--;
    heapifyDown(heap, *size, 0);
}

int minRooms(Interval arr[], int n) {
    qsort(arr, n, sizeof(Interval), cmpStart);

    int *heap = (int *)malloc(n * sizeof(int));
    int size = 0;

    push(heap, &size, arr[0].end);

    for (int i = 1; i < n; i++) {
        if (heap[0] <= arr[i].start)
            pop(heap, &size);
        push(heap, &size, arr[i].end);
    }

    int result = size;
    free(heap);
    return result;
}

int main() {
    int n;
    scanf("%d", &n);

    Interval arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d %d", &arr[i].start, &arr[i].end);

    printf("%d\n", minRooms(arr, n));
    return 0;
}
