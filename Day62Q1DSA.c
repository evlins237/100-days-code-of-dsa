#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* adj[100];

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void addEdge(int u, int v) {
    Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;
}

void printGraph(int n) {
    for (int i = 0; i < n; i++) {
        printf("Vertex %d: ", i);
        Node* temp = adj[i];

        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }

        printf("NULL\n");
    }
}

int main() {
    int n, m;
    int directed;

    scanf("%d %d", &n, &m);
    scanf("%d", &directed);

    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        addEdge(u, v);

        if (directed == 0) {
            addEdge(v, u);
        }
    }

    printGraph(n);

    return 0;
}
