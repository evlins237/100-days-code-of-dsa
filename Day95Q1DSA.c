  #include <stdio.h>
#include <stdlib.h>

struct Node {
    float val;
    struct Node* next;
};

struct Node* insertSorted(struct Node* head, float value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = value;
    newNode->next = NULL;

    if (!head || value < head->val) {
        newNode->next = head;
        return newNode;
    }

    struct Node* curr = head;
    while (curr->next && curr->next->val <= value)
        curr = curr->next;

    newNode->next = curr->next;
    curr->next = newNode;
    return head;
}

void bucketSort(float arr[], int n) {
    struct Node** buckets = (struct Node**)malloc(n * sizeof(struct Node*));

    for (int i = 0; i < n; i++)
        buckets[i] = NULL;

    for (int i = 0; i < n; i++) {
        int idx = (int)(arr[i] * n);
        buckets[idx] = insertSorted(buckets[idx], arr[i]);
    }

    int k = 0;
    for (int i = 0; i < n; i++) {
        struct Node* curr = buckets[i];
        while (curr) {
            arr[k++] = curr->val;
            struct Node* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }

    free(buckets);
}

int main() {
    int n;
    scanf("%d", &n);

    float arr[n];
    for (int i = 0; i < n; i++)
        scanf("%f", &arr[i]);

    bucketSort(arr, n);

    for (int i = 0; i < n; i++)
        printf("%.6f ", arr[i]);

    return 0;
}
