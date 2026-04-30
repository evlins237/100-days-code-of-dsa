#include <stdio.h>
#include <stdlib.h>

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

Node* insert(Node* root, int val) {
    if (root == NULL) return newNode(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

Node* lca(Node* root, int a, int b) {
    if (root == NULL) return NULL;
    if (a < root->data && b < root->data)
        return lca(root->left, a, b);
    if (a > root->data && b > root->data)
        return lca(root->right, a, b);
    return root;
}

int main() {
    int n;
    scanf("%d", &n);

    Node* root = NULL;

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        root = insert(root, x);
    }

    int a, b;
    scanf("%d %d", &a, &b);

    Node* ans = lca(root, a, b);
    if (ans != NULL)
        printf("%d", ans->data);

    return 0;
}
