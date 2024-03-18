#include <stdio.h>
#include <stdbool.h>

#define V 4 // Number of vertices (you can adjust this)

// Function to check if the graph is complete
bool isCompleteGraph(int G[][V]) {
    int expectedEdges = V * (V - 1) / 2;
    int actualEdges = 0;

    for (int i = 0; i < V; ++i) {
        for (int j = i + 1; j < V; ++j) {
            if (G[i][j] == 1) {
                actualEdges++;
            }
        }
    }

    return actualEdges == expectedEdges;
}

int main() {
    int G[][V] = {
        {0, 1, 0, 1},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {1, 0, 1, 0}
    };

    if (isCompleteGraph(G)) {
        printf("The graph is complete.\n");
    } else {
        printf("The graph is not complete.\n");
    }

    return 0;
}
