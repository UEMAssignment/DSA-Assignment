#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
int stack[MAX_SIZE], size, top = -1;

int isFull()
{
    if (top == size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty()
{
    if (top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(int element)
{
    if (isFull())
    {
        printf("Overflow !!!");
    }
    else
    {
        top++;
        stack[top] = element;
        printf("%d has been pushed to the stack.", stack[top]);
    }
}

void pop()
{
    if (isEmpty())
    {
        printf("Underflow !!!");
    }
    else
    {
        printf("%d has been popped from the stack.", stack[top]);
        top = top - 1;
    }
}

void peek()
{
    if (isEmpty())
    {
        printf("Empty Stack !!!");
    }
    else
    {
        printf("Peek : %d", stack[top]);
    }
}

void display()
{
    if (isEmpty())
    {
        printf("Empty Stack !!!");
    }
    else
    {
        int i;
        for (i = 0; i <= top; i++)
        {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

void main()
{
    int choice, element;
    // int *stack = (int *)malloc(sizeof(stack));
    printf("Enter the size of the array : ");
    scanf("%d", &size);
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