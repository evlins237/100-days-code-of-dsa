#include <stdio.h>
#include <stdlib.h>

void topoSort(int V, int adj[][1000], int adjSize[])
{
    int indegree[1000] = {0};
    int queue[1000];
    int front = 0, rear = 0;

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < adjSize[i]; j++)
        {
            indegree[adj[i][j]]++;
        }
    }

    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
        {
            queue[rear++] = i;
        }
    }

    int count = 0;

    while (front < rear)
    {
        int node = queue[front++];
        printf("%d ", node);
        count++;

        for (int i = 0; i < adjSize[node]; i++)
        {
            int neighbor = adj[node][i];
            indegree[neighbor]--;

            if (indegree[neighbor] == 0)
            {
                queue[rear++] = neighbor;
            }
        }
    }

    if (count != V)
    {
        printf("\nCycle detected (Topological sort not possible)");
    }
}

int main()
{
    int V, E;
    scanf("%d %d", &V, &E);

    int adj[1000][1000];
    int adjSize[1000] = {0};

    for (int i = 0; i < E; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);

        adj[u][adjSize[u]++] = v;
    }

    topoSort(V, adj, adjSize);

    return 0;
}
