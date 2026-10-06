#include <stdio.h>
#include <stdlib.h>

int adj[20][20], n;

void BFS(int start) {
    int q[20], visited[20] = {0}, f = 0, r = 0;
    visited[start] = 1;
    q[r++] = start;

    printf("\nBFS Traversal: ");
    while (f < r) {
        int v = q[f++];
        printf("%d ", v);
        for (int w = 0; w < n; w++) {
            if (adj[v][w] && !visited[w]) {
                visited[w] = 1;
                q[r++] = w;
            }
        }
    }
    printf("\n");
}

void DFS(int v, int visited[]) {
    visited[v] = 1;
    printf("%d ", v);
    for (int w = 0; w < n; w++) {
        if (adj[v][w] && !visited[w]) DFS(v = w, visited); // recursive inline call
    }
}

int get_start() {
    int start;
    printf("Enter starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);
    return start;
}

int main() {
    int choice, visited[20] = {0};

    printf("Enter total number of vertices: ");
    scanf("%d", &n);

    printf("Enter the Adjacency Matrix (%dx%d):\n", n, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    while (1) {
        printf("\n--- MENU --- \n1. Breadth First Search (BFS)\n2. Depth First Search (DFS)\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            BFS(get_start());
        } else if (choice == 2) {
            for (int i = 0; i < n; i++) visited[i] = 0;
            printf("\nDFS Traversal: ");
            DFS(get_start(), visited);
            printf("\n");
        } else if (choice == 3) {
            exit(0);
        } else {
            printf("Invalid choice! Try again.\n");
        }
    }
}
