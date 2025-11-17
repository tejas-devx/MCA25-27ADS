#include <stdio.h>
#include <stdlib.h>

#define MAX 30

// Structure for an edge
struct Edge {
    int u, v, w;
};

// Disjoint set parent array
int parent[MAX];

// Function to find parent of a vertex (with path compression)
int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

// Function to perform union of two sets
void union_sets(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

int main() {
    struct Edge edges[MAX];
    struct Edge result[MAX]; // To store MST edges
    int V, E;
    int i, j, total_cost = 0, count = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &V);
    printf("Enter number of edges: ");
    scanf("%d", &E);

    printf("\nEnter edges (source destination weight):\n");
    for (i = 0; i < E; i++)
        scanf("%d%d%d", &edges[i].u, &edges[i].v, &edges[i].w);

    // Sort edges by weight (Bubble Sort for simplicity)
    for (i = 0; i < E - 1; i++) {
        for (j = 0; j < E - i - 1; j++) {
            if (edges[j].w > edges[j + 1].w) {
                struct Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }

    // Initialize each vertex as its own parent
    for (i = 0; i < V; i++)
        parent[i] = i;

    i = 0; // index for edges[]
    while (count < V - 1 && i < E) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;

        int set_u = find(u);
        int set_v = find(v);

        if (set_u != set_v) { // No cycle
            result[count++] = edges[i];
            union_sets(set_u, set_v);
            total_cost += w;
        }
        i++;
    }

    printf("\nEdges in the Minimum Cost Spanning Tree:\n");
    for (i = 0; i < count; i++)
        printf("%d -- %d == %d\n", result[i].u, result[i].v, result[i].w);

    printf("Minimum Cost of Spanning Tree: %d\n", total_cost);

    return 0;
}
