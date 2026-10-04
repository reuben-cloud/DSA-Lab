#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int adj[MAX][MAX];
int n;

void BFS(int start) {
    int queue[MAX], front = 0, rear = 0;
    int visited[MAX] = {0};

    visited[start] = 1;
    queue[rear++] = start;

    printf("\nBFS Traversal: ");
    while (front < rear) {
        int v = queue[front++];
        printf("%d ", v);

        for (int w = 0; w < n; w++) {
            if (adj[v][w] == 1 && visited[w] == 0) {
                visited[w] = 1;
                queue[rear++] = w;
            }
        }
    }
    printf("\n");
}

void DFS_helper(int v, int visited[]) {
    visited[v] = 1;
    printf("%d ", v);

    for (int w = 0; w < n; w++) {
        if (adj[v][w] == 1 && visited[w] == 0) {
            DFS_helper(w, visited);
        }
    }
}

void DFS(int start) {
    int visited[MAX] = {0};
    printf("\nDFS Traversal: ");
    DFS_helper(start, visited);
    printf("\n");
}

int main() {
    int choice, start;

    printf("Enter total number of vertices: ");
    scanf("%d", &n);

    printf("Enter the Adjacency Matrix (%dx%d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    while (1) {
        printf("\n--- MENU --- \n");
        printf("1. Breadth First Search (BFS)\n");
        printf("2. Depth First Search (DFS)\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter starting vertex (0 to %d): ", n - 1);
                scanf("%d", &start);
                BFS(start);
                break;

            case 2:
                printf("Enter starting vertex (0 to %d): ", n - 1);
                scanf("%d", &start);
                DFS(start);
                break;

            case 3:
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
