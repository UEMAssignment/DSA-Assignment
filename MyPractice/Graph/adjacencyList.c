#include <stdio.h>
#include <stdlib.h>

#define MAX 4

typedef struct node
{
    int vertexNo;
    struct node *next;
} node;

typedef struct list
{
    node *head;
} list;

list *adjList[MAX] = {0};

// void addNode(int s, int d)
// {
//     node *dest, *temp, *src;

//     if (adjList[s]->head == NULL)
//     {
//         src = (node *)malloc(sizeof(node));
//         src->vertexNo = s;
//         src->next = NULL;
//         adjList[s]->head = src;
//     }

//     dest = (node *)malloc(sizeof(node));
//     dest->vertexNo = d;
//     dest->next = NULL;
//     temp = adjList[s]->head;

//     while (temp->next != NULL)
//         temp = temp->next;
//     temp->next = dest;
// }

void addNode(int s, int d)
{
    if (s < 0 || s >= MAX || d < 0 || d >= MAX)
    {
        // printf("Invalid vertex number.\n");
        return;
    }

    node *dest, *temp, *src;

    if (adjList[s] == NULL)
    {
        adjList[s] = (list *)malloc(sizeof(list));
        adjList[s]->head = NULL;
    }

    if (adjList[s]->head == NULL)
    {
        src = (node *)malloc(sizeof(node));
        src->vertexNo = s;
        src->next = NULL;
        adjList[s]->head = src;
    }

    dest = (node *)malloc(sizeof(node));
    dest->vertexNo = d;
    dest->next = NULL;

    temp = adjList[s]->head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = dest;
}

void printList()
{
    int i;
    for (i = 0; i < MAX; ++i)
    {
        node *p = adjList[i]->head;
        printf("Adjacency list for vertex %d\n", i);

        while (p)
        {
            printf("%d->", p->vertexNo);
            p = p->next;
        }
        printf("X \n");
    }
}

void main()
{
    int i;
    for (i = 0; i < MAX; i++)
    {
        adjList[i] = (list *)malloc(sizeof(list));
        adjList[i]->head = NULL;
    }

    addNode(0, 1);
    addNode(0, 3);
    addNode(1, 2);
    addNode(1, 3);
    addNode(2, 3);
    addNode(3, 4);
    printList();
}