#include <stdio.h>
#include <stdbool.h>

#define MAX 1000

int n;
int visited[MAX];
int adj[MAX][MAX];   // adjacency matrix for simplicity

bool dfs(int node, int parent) {
    visited[node] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[node][i]) {

            if (!visited[i]) {
                if (dfs(i, node))
                    return true;
            }
            else if (i != parent) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    int m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        adj[u][v] = 1;
        adj[v][u] = 1;   // undirected graph
    }

    int hasCycle = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1)) {
                hasCycle = 1;
                break;
            }
        }
    }

    if (hasCycle)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
