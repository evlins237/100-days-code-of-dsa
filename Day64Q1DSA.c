#include <stdio.h>

#define MAX 1000

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* adj[MAX];
int visited[MAX];
int n;

Node pool[MAX * 10];
int poolIndex = 0;

Node* createNode(int value) {
    Node* newNode = &pool[poolIndex++];
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void addEdge(int u, int v) {
    Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;
}

// Queue implementation
int queue[MAX];
int front = 0, rear = 0;

void enqueue(int value) {
    queue[rear++] = value;
}

int dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

void bfs(int start) {
    enqueue(start);
    visited[start] = 1;

    while (!isEmpty()) {
        int node = dequeue();
        printf("%d ", node);

        Node* temp = adj[node];

        while (temp != NULL) {
            int neighbor = temp->data;

            if (!visited[neighbor]) {
                visited[neighbor] = 1;
                enqueue(neighbor);
            }

            temp = temp->next;
        }
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

    printf("BFS Traversal: ");
    bfs(s);

    return 0;
}
