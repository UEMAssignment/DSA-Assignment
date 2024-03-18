#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the maximum number of vertices
#define MAX_VERTICES 100

// Structure to represent an adjacency list node
struct Node {
    int vertex;
    struct Node* next;
};

// Structure to represent the graph
struct Graph {
    int numVertices;
    struct Node* adjLists[MAX_VERTICES];
};

// Function to create a new graph with 'n' vertices
struct Graph* createGraph(int n) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = n;
    for (int i = 0; i < n; ++i)
        graph->adjLists[i] = NULL;
    return graph;
}

// Function to add an edge between vertices 'u' and 'v'
void addEdge(struct Graph* graph, int u, int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = graph->adjLists[u];
    graph->adjLists[u] = newNode;
}

// Function to count the number of vertices and edges
void countVerticesAndEdges(struct Graph* graph) {
    int numVertices = graph->numVertices;
    int numEdges = 0;

    for (int i = 0; i < numVertices; ++i) {
        struct Node* current = graph->adjLists[i];
        while (current) {
            ++numEdges;
            current = current->next;
        }
    }

    printf("Number of vertices: %d\n", numVertices);
    printf("Number of edges: %d\n", numEdges / 2); // Divide by 2 since each edge is counted twice
}
bool detectCycleDFS(int node, int visited[], int recStack[], struct Graph* graph) {
    visited[node] = 1;
    recStack[node] = 1;

    struct Node* current = graph->adjLists[node];
    while (current) {
        int adjacentVertex = current->vertex;
        if (!visited[adjacentVertex]) {
            if (detectCycleDFS(adjacentVertex, visited, recStack, graph))
                return true;
        } else if (recStack[adjacentVertex]) {
            return true;
        }
        current = current->next;
    }

    recStack[node] = 0;
    return false;
}

bool detectCycle(struct Graph* graph) {
    int numVertices = graph->numVertices;
    int visited[MAX_VERTICES] = {0};
    int recStack[MAX_VERTICES] = {0};

    for (int i = 0; i < numVertices; ++i) {
        if (!visited[i]) {
            if (detectCycleDFS(i, visited, recStack, graph))
                return true;
        }
    }

    return false;
}

int main() {
    int numVertices, numEdges;
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);
    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    struct Graph* graph = createGraph(numVertices);

    printf("Enter the edges (u v):\n");
    for (int i = 0; i < numEdges; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }


    countVerticesAndEdges(graph);
     if (detectCycle(graph))
        printf("The graph contains a cycle.\n");
    else
        printf("The graph does not contain a cycle.\n");

    return 0;
   

}
