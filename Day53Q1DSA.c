#include <stdio.h>
#include <stdlib.h>

#define MAX 1000
#define OFFSET 500

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node* newNode(int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    if (n == 0 || arr[0] == -1)
        return 0;

    Node* nodes[n];

    for (int i = 0; i < n; i++) {
        if (arr[i] != -1)
            nodes[i] = newNode(arr[i]);
        else
            nodes[i] = NULL;
    }

    for (int i = 0; i < n; i++) {
        if (nodes[i] != NULL) {
            int l = 2*i + 1;
            int r = 2*i + 2;
            if (l < n) nodes[i]->left = nodes[l];
            if (r < n) nodes[i]->right = nodes[r];
        }
    }

    Node* root = nodes[0];

    Node* queue[MAX];
    int hd[MAX];
    int front = 0, rear = 0;

    int col[MAX][MAX];
    int count[MAX] = {0};

    queue[rear] = root;
    hd[rear++] = OFFSET;

    while (front < rear) {
        Node* curr = queue[front];
        int h = hd[front++];
        
        col[h][count[h]++] = curr->data;

        if (curr->left) {
            queue[rear] = curr->left;
            hd[rear++] = h - 1;
        }
        if (curr->right) {
            queue[rear] = curr->right;
            hd[rear++] = h + 1;
        }
    }

    for (int i = 0; i < MAX; i++) {
        if (count[i] > 0) {
            for (int j = 0; j < count[i]; j++)
                printf("%d ", col[i][j]);
            printf("\n");
        }
    }

    return 0;
}
