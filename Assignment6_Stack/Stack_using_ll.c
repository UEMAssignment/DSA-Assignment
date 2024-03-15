#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} node;

node *top = NULL;

void push(int element)
{

    node *newNode;
    newNode = (node *)malloc(sizeof(node));
    newNode->data = element;
    newNode->next = top;
    top = newNode;
    printf("%d has been pushed to the stack.", newNode->data);
}

void pop()
{
    node *forRemove;
    forRemove = top;
    if (top == NULL)
    {
        printf("Underflow !!!");
    }
    else
    {
        printf("%d has been popped from the stack.", forRemove->data);
        top = forRemove->next;
        free(forRemove);
    }
}

void peek()
{
    if (top == NULL)
    {
        printf("Empty Stack !!!");
    }
    else
    {
        printf("Peek : %d", top->data);
    }
}

void display()
{
    node *temp;
    temp = top;
    if (top == NULL)
    {
        printf("Empty Stack !!!");
    }
    else
    {
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }

        printf("\n");
    }
}

void main()
{
    int choice, element;

    while (1)
    {
        printf("\n\n\nMenu : \n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the element : ");
            scanf("%d", &element);
            push(element);
            break;

        case 2:
            pop();
            break;

        case 3:
            peek();
            break;

        case 4:
            printf("Displaying...\n");
            display();
            break;

        case 5:
            printf("Exiting the menu...");
            exit(0);

        default:
            printf("Invalid Choice !!!");
            break;
        }
    }
}