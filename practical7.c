//unnati dharpure  cs23147
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

typedef struct {
    int n;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

void createGraph(Graph *G) {
    int i, j;

    printf("Enter the number of vertices: ");
    scanf("%d", &G->n);

    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < G->n; i++) {
        for (j = 0; j < G->n; j++) {
            scanf("%d", &G->adjMatrix[i][j]);
        }
    }
}

void DFS(Graph *G, int start) {
    int visited[MAX_VERTICES] = {0};
    int stack[MAX_VERTICES], top = -1;
    int i;

    stack[++top] = start;
    visited[start] = 1;

    while (top != -1) {
        int current = stack[top--];
        printf("%d ", current);
        for (i = G->n - 1; i >= 0; i--) {
            if (G->adjMatrix[current][i] == 1 && !visited[i]) {
                stack[++top] = i;
                visited[i] = 1;
                break;
            }
        }
    }
}

void BFS(Graph *G, int start) {
    int visited[MAX_VERTICES] = {0};
    int queue[MAX_VERTICES], front = 0, rear = -1;
    int visitedCount = 0;
    int visitedVertices[MAX_VERTICES];
    int i;
    queue[++rear] = start;
    visited[start] = 1;

    while (front <= rear) {
        int current = queue[front++];
        visitedVertices[visitedCount++] = current;

        for (i = 0; i < G->n; i++) {
            if (G->adjMatrix[current][i] == 1 && !visited[i]) {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }

    // Print out the visited vertices
    for (i = 0; i < visitedCount; i++) {
        printf("%d ", visitedVertices[i]);
    }
}

int main() {
    Graph G;
    int choice, startVertex;

    createGraph(&G);

    do {
        printf("\nMenu:\n");
        printf("1. DFS\n");
        printf("2. BFS\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the starting vertex for DFS: ");
                scanf("%d", &startVertex);
                DFS(&G, startVertex);
                break;
            case 2:
                printf("Enter the starting vertex for BFS: ");
                scanf("%d", &startVertex);
                BFS(&G, startVertex);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}
