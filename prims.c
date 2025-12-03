#include <stdio.h>

#define INF 9999
#define MAX 10

int main() {
    int cost[MAX][MAX], visited[MAX], n;
    int i, j, count = 0, mincost = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);

            if (cost[i][j] == 0)
                cost[i][j] = INF;    
        }
        visited[i] = 0;   
    }

    visited[0] = 1;  

    printf("\nEdges in Minimum Cost Spanning Tree:\n");

    while (count < n - 1) {
        int min = INF;
        int u = -1, v = -1;

        for (i = 0; i < n; i++) {
            if (visited[i]) {
                for (j = 0; j < n; j++) {
                    if (!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        printf("%d - %d = %d\n", u, v, min);
        visited[v] = 1;
        mincost += min;
        count++;
    }

    printf("\nMinimum Cost = %d\n", mincost);
    return 0;
}
