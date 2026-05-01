#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 1000

int adj[MAX][MAX];
int adjSize[MAX];
bool visited[MAX];
int stack[MAX];
int top = -1;

void dfs(int node, int V)
{
    visited[node] = true;

    for (int i = 0; i < adjSize[node]; i++)
    {
        int neighbor = adj[node][i];

        if (!visited[neighbor])
        {
            dfs(neighbor, V);
        }
    }

    stack[++top] = node;
}

void topoSort(int V)
{
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            dfs(i, V);
        }
    }

    while (top >= 0)
    {
        printf("%d ", stack[top--]);
    }
}

int main()
{
    int V, E;
    scanf("%d %d", &V, &E);

    for (int i = 0; i < V; i++)
        adjSize[i] = 0;

    for (int i = 0; i < E; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);

        adj[u][adjSize[u]++] = v;
    }

    topoSort(V);

    return 0;
}
