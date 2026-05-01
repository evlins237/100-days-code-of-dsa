#include <stdio.h>

#define MAX 1000

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* adj[MAX];
int visited[MAX];
int n;

Node nodes_pool[MAX * 10];
int pool_index = 0;

Node* createNode(int value) {
    Node* newNode = &nodes_pool[pool_index++];
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void addEdge(int u, int v) {
    Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;
}

void dfs(int v) {
    visited[v] = 1;
    printf("%d ", v);

    Node* temp = adj[v];

    while (temp != NULL) {
        int neighbor = temp->data;

        if (!visited[neighbor]) {
            dfs(neighbor);
        }

        temp = temp->next;
    }
}

int main() {
    int m, s;

    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);   // directed graph
    }

    scanf("%d", &s);

    printf("DFS Traversal: ");
    dfs(s);

    return 0;
}
