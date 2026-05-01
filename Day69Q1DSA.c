#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 1000

typedef struct {
    int v;
    int weight;
    struct Node* next;
} Node;

Node* adj[MAX];
int dist[MAX];
int visited[MAX];

typedef struct {
    int node;
    int dist;
} HeapNode;

HeapNode heap[MAX * MAX];
int size = 0;

void swap(HeapNode *a, HeapNode *b)
{
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

void push(int node, int d)
{
    heap[size].node = node;
    heap[size].dist = d;
    int i = size++;
    
    while (i > 0 && heap[i].dist < heap[(i - 1) / 2].dist)
    {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

HeapNode pop()
{
    HeapNode root = heap[0];
    heap[0] = heap[--size];

    int i = 0;
    while (1)
    {
        int smallest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if (l < size && heap[l].dist < heap[smallest].dist)
            smallest = l;
        if (r < size && heap[r].dist < heap[smallest].dist)
            smallest = r;

        if (smallest != i)
        {
            swap(&heap[i], &heap[smallest]);
            i = smallest;
        }
        else break;
    }

    return root;
}

void addEdge(int u, int v, int w)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->v = v;
    newNode->weight = w;
    newNode->next = adj[u];
    adj[u] = newNode;
}

void dijkstra(int V, int src)
{
    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[src] = 0;
    push(src, 0);

    while (size > 0)
    {
        HeapNode curr = pop();
        int u = curr.node;

        if (visited[u]) continue;
        visited[u] = 1;

        Node* temp = adj[u];

        while (temp != NULL)
        {
            int v = temp->v;
            int w = temp->weight;

            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                push(v, dist[v]);
            }

            temp = temp->next;
        }
    }

    for (int i = 0; i < V; i++)
    {
        printf("%d ", dist[i]);
    }
}
