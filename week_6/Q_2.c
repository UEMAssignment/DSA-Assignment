#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Define the maximum number of vertices in the graph
#define MAX_VERTICES 100

// Structure to represent a node in the adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Structure to represent the graph
struct Graph {
    int numVertices;
    struct Node* adjList[MAX_VERTICES];
};

// Function to create a new graph with 'V' vertices
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = V;
    for (int i = 0; i < V; ++i)
        graph->adjList[i] = NULL;
    return graph;
}

// Function to add an edge between two vertices
void addEdge(struct Graph* graph, int src, int dest) {
    // Add an edge from src to dest
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = dest;
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    // Add an edge from dest to src (for undirected graph)
    // newNode = (struct Node*)malloc(sizeof(struct Node));
    // newNode->vertex = src;
    // newNode->next = graph->adjList[dest];
    // graph->adjList[dest] = newNode;
}

// Function to perform BFS traversal
void BFS(struct Graph* graph, int startVertex, char vertices[]) {
    int visited[MAX_VERTICES] = {0}; // Initialize visited array
    struct Node* queue[MAX_VERTICES];
    int front = 0, rear = 0;

    // Mark the start vertex as visited and enqueue it
    visited[startVertex] = 1;
    queue[rear++] = graph->adjList[startVertex];

    while (front < rear) {
        struct Node* currentNode = queue[front++];
        printf("%c\t", vertices[currentNode->vertex]);

        // Enqueue adjacent vertices
        struct Node* temp = currentNode;
        while (temp != NULL) {
            int adjVertex = temp->vertex;
            if (!visited[adjVertex]) {
                visited[adjVertex] = 1;
                queue[rear++] = graph->adjList[adjVertex];
            }
            temp = temp->next;
        }
    }
}

int main() {
    char vertices[] = {'P', 'Q', 'R', 'S', 'T', 'U'};
    //                  0,   1,   2,   3,   4,   5
    struct Graph* graph = createGraph(6);

    // Add edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 0, 3);

    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);

    addEdge(graph, 2, 3);
    addEdge(graph, 2, 5);

    addEdge(graph, 3, 4);
    addEdge(graph, 3, 5);

    addEdge(graph, 4, 5);

    printf("Enter the starting vertex: ");
    char vertex;
    scanf("%c", &vertex);
    vertex = toupper(vertex);
    int i;
    int flag = 0;
    for (i = 0; i < 6; i++) {
        if (vertices[i] == vertex){
            flag = 1;
            break;
        } 
    }
    if (!flag) {
        printf("Invalid vertex\n");
        return 0;
    }

    printf("BFS traversal starting from vertex %c:\n", vertex);
    BFS(graph, i, vertices);

    printf("\n");
    return 0;
}
