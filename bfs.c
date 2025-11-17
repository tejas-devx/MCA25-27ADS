#include <stdio.h>
#define SIZE 10

int queue[SIZE], front = -1, rear = -1;
int visited[SIZE];

void enqueue(int vertex) {
    if (rear == SIZE - 1)
        printf("Queue is full!\n");
    else {
        if (front == -1)
            front = 0;
        queue[++rear] = vertex;
    }
}

int dequeue() {
    if (front == -1 || front > rear)
        return -1;
    else
        return queue[front++];
}

void bfs(int adj[SIZE][SIZE], int n, int start) {
    int i, vertex;
    for (i = 0; i < n; i++)
        visited[i] = 0;

    enqueue(start);
    visited[start] = 1;

    printf("BFS Traversal starting from vertex %d: ", start);

    while (front <= rear) {
        vertex = dequeue();
        printf("%d ", vertex);

        for (i = 0; i < n; i++) {
            if (adj[vertex][i] == 1 && visited[i] == 0) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

int main() {
    int n, i, j, start;
    int adj[SIZE][SIZE];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix of the graph:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    bfs(adj, n, start);

    return 0;
}
