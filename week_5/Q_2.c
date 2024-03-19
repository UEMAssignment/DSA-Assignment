#include <stdio.h>
#include <stdlib.h>

// Node structure for the adjacency list
typedef struct Node {
    int vertex;
    int weight;
    struct Node* next;
} Node;

// Graph structure
typedef struct Graph {
    int numVertices;
    Node** adjLists;
} Graph;

// Function to create a new node
Node* createNode(int v, int w) {
    Node *newNode = malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->weight = w; 
    newNode->next = NULL;

    return newNode;
}

// Function to create a graph
Graph* createGraph(int vertices) {
    Graph *graph = malloc(sizeof(Graph));
    graph->numVertices = vertices;

    graph->adjLists = malloc(vertices * sizeof(Node *));
    for (int i = 0; i < vertices; i++)
        graph->adjLists[i] = NULL;

    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph *graph, int src, int dest, int weight) {
    Node *newNode = createNode(dest, weight);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode; 

    // Uncomment the following lines for an undirected graph
    // newNode = createNode(src, weight); 
    // newNode->next = graph->adjLists[dest]; 
    // graph->adjLists[dest] = newNode; 
}

// Function to print the graph
void printGraph(Graph* graph) {
    for (int v = 0; v < graph->numVertices; v++) {
        Node *temp = graph->adjLists[v];
        printf("Vertex %d:\n", v + 1);
        while (temp) {
            printf(" -> %d (Weight: %d)\n", temp->vertex + 1, temp->weight);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Main function
int main() {
    // Create a graph with 6 vertices
    Graph* graph = createGraph(6);

    // Add edges with weights
    addEdge(graph, 0, 1, 1); // P-Q
    addEdge(graph, 0, 3, 6); // P-S
    addEdge(graph, 0, 4, 7); // P-T
    addEdge(graph, 1, 2, 4); // Q-R
    addEdge(graph, 1, 3, 6); // Q-S
    addEdge(graph, 2, 3, 2); // R-S
    addEdge(graph, 2 ,5 ,1); // R-U
    addEdge(graph ,3 ,4 ,3); // S-T 
    addEdge(graph ,3 ,5 ,2); // S-U 
    addEdge(graph ,4 ,5 ,2); // T-U 

    // Print the graph
    printGraph(graph);

    return 0;
}
