  #include <stdio.h>

#define MAX 1000

int adj[MAX][MAX];
int visited[MAX];
int n;

void dfs(int v) {
    visited[v] = 1;
    for (int i = 0; i < n; i++) {
        if (adj[v][i] && !visited[i]) {
            dfs(i);
        }
    }
}

int isConnected() {
    dfs(0);

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            return 0;
        }
    }

    return 1;
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    if (isConnected()) {
        printf("Connected\n");
    } else {
        printf("Not Connected\n");
    }

    return 0;
}
