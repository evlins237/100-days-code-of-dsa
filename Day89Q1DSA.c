#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int sum(int arr[], int n) {
    int s = 0;
    for (int i = 0; i < n; i++) s += arr[i];
    return s;
}

int canAllocate(int arr[], int n, int m, int maxPages) {
    int students = 1;
    int pages = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > maxPages) return 0;

        if (pages + arr[i] <= maxPages) {
            pages += arr[i];
        } else {
            students++;
            pages = arr[i];
        }

        if (students > m) return 0;
    }
    return 1;
}

int allocateBooks(int arr[], int n, int m) {
    if (m > n) return -1;

    int left = arr[0];
    for (int i = 1; i < n; i++) left = max(left, arr[i]);

    int right = sum(arr, n);
    int ans = right;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (canAllocate(arr, n, m, mid)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return ans;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    printf("%d\n", allocateBooks(arr, n, m));
    return 0;
}
