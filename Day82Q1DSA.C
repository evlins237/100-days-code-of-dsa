#include <stdio.h>

int lowerBound(int arr[], int n, int x) {
    int left = 0, right = n;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] < x)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

int upperBound(int arr[], int n, int x) {
    int left = 0, right = n;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] <= x)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

int main() {
    int arr[] = {1, 2, 4, 4, 4, 6, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 4;

    int lb = lowerBound(arr, n, x);
    int ub = upperBound(arr, n, x);

    printf("Lower Bound of %d: %d\n", x, lb);
    printf("Upper Bound of %d: %d\n", x, ub);

    return 0;
}
