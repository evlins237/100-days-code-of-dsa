#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int val, idx;
} Pair;

void merge(Pair arr[], int left, int mid, int right, int count[]) {
    int n = right - left + 1;
    Pair *temp = (Pair *)malloc(n * sizeof(Pair));

    int i = left, j = mid + 1, k = 0;
    int rightCount = 0;

    while (i <= mid && j <= right) {
        if (arr[j].val < arr[i].val) {
            temp[k++] = arr[j++];
            rightCount++;
        } else {
            count[arr[i].idx] += rightCount;
            temp[k++] = arr[i++];
        }
    }

    while (i <= mid) {
        count[arr[i].idx] += rightCount;
        temp[k++] = arr[i++];
    }

    while (j <= right)
        temp[k++] = arr[j++];

    for (i = left; i <= right; i++)
        arr[i] = temp[i - left];

    free(temp);
}

void mergeSort(Pair arr[], int left, int right, int count[]) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid, count);
        mergeSort(arr, mid + 1, right, count);
        merge(arr, left, mid, right, count);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    Pair pairs[n];
    int count[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        pairs[i].val = arr[i];
        pairs[i].idx = i;
        count[i] = 0;
    }

    mergeSort(pairs, 0, n - 1, count);

    for (int i = 0; i < n; i++)
        printf("%d ", count[i]);

    return 0;
}
