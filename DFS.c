#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_VERTICES 100

struct Node
{
    int vertex;
    struct Node *next;
};

struct Graph
{
    int numVertices;
    bool visited[MAX_VERTICES];
    struct Node *adjLists[MAX_VERTICES];
};

struct Graph *createGraph(int vertices)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    for (int i = 0; i < vertices; ++i)
    {
        graph->visited[i] = false;
        graph->adjLists[i] = NULL;
    }

    return graph;
}

void addEdge(struct Graph *graph, int src, int dest)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->vertex = dest;
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}

void DFS(struct Graph *graph, int vertex, char vertexes[])
{
    graph->visited[vertex] = true;
    printf("%c\t", vertexes[vertex]);

    struct Node *adjList = graph->adjLists[vertex];
    while (adjList != NULL)
    {
        int connectedVertex = adjList->vertex;
        if (!graph->visited[connectedVertex])
        {
            DFS(graph, connectedVertex, vertexes);
        }
        adjList = adjList->next;
    }
}

int main()
{
    char vertexes[] = {'P', 'Q', 'R', 'S', 'T', 'U'};
    struct Graph *graph = createGraph(6);

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
    scanf(" %c", &vertex);
    vertex = toupper(vertex);

    int flag = 0;
    for (int i = 0; i < 6; i++)
    {
        if (vertexes[i] == vertex)
        {
            flag = 1;
            DFS(graph, i, vertexes);
            break;
        }
    }

    if (!flag)
    {
        printf("Invalid vertex\n");
    }

    printf("\n");
    return 0;
}
