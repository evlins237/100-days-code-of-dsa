#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int sum(int arr[], int n) {
    int s = 0;
    for (int i = 0; i < n; i++) s += arr[i];
    return s;
}

int canPaint(int boards[], int n, int k, int maxTime) {
    int painters = 1;
    int time = 0;

    for (int i = 0; i < n; i++) {
        if (boards[i] > maxTime) return 0;

        if (time + boards[i] <= maxTime) {
            time += boards[i];
        } else {
            painters++;
            time = boards[i];
        }

        if (painters > k) return 0;
    }
    return 1;
}

int minTime(int boards[], int n, int k) {
    int left = boards[0];
    for (int i = 1; i < n; i++) left = max(left, boards[i]);

    int right = sum(boards, n);
    int ans = right;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (canPaint(boards, n, k, mid)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return ans;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int boards[n];
    for (int i = 0; i < n; i++) scanf("%d", &boards[i]);

    printf("%d\n", minTime(boards, n, k));
    return 0;
}
