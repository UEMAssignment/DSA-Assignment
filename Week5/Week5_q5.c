#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100 // You can adjust this based on your graph size

int main() {
    int n, m; // n: number of vertices, m: number of edges
     printf("Number of vertices: ");
     scanf("%d", &n);
     printf("Number of edges: ");
   
     scanf("%d", &m);

    int adjMatrix[MAX_VERTICES][MAX_VERTICES] = {0}; // Initialize adjacency matrix
	int i,j;
    for (i = 0; i < m; ++i) {
        int u, v;
        
        scanf("%d%d", &u, &v);
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1; // Assuming an undirected graph
    }

    int evenVertices = 0, oddVertices = 0;

    for (i = 0; i < n; ++i) {
        int degree = 0;
        for (j = 0; j < n; ++j) {
            degree += adjMatrix[i][j];
        }

        if (degree % 2 == 0) {
            evenVertices++;
        } else {
            oddVertices++;
        }
    }

   
    printf("Number of odd-degree vertices: %d\n", oddVertices);
    printf("Number of even-degree vertices: %d\n", evenVertices);

    return 0;
}