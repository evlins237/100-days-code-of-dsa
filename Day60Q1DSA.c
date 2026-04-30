#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for (int i = 0; i <= (n - 2) / 2; i++) {
        int l = 2*i + 1;
        int r = 2*i + 2;

        if (l < n && arr[i] > arr[l]) {
            printf("NO");
            return 0;
        }

        if (r < n && arr[i] > arr[r]) {
            printf("NO");
            return 0;
        }
    }

    printf("YES");
    return 0;
}
