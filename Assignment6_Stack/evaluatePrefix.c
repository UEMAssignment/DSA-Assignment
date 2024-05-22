#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

int top = -1;
int stack[MAX];

// Checking if stack is full
int isFull()
{
    return top == MAX - 1;
}

// Checking if stack is empty
int isEmpty()
{
    return top == -1;
}

// Pushing an element onto the stack
void push(int item)
{
    if (isFull())
    {
        printf("Stack Overflow\n");
        exit(EXIT_FAILURE);
    }
    top++;
    stack[top] = item;
}

// Popping an element from the stack
int pop()
{
    if (isEmpty())
    {
        printf("Stack Underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack[top--];
}

// Evaluating a prefix expression
int evaluatePrefix(char *expression)
{
    int i, operand;

    for (i = strlen(expression) - 1; i >= 0; i--)
    {
        if (isdigit(expression[i]))
        {
            // Handle multi-digit operands
            int j = i;
            int num = 0;
            while (i >= 0 && isdigit(expression[i]))
            {
                num = num * 10 + (expression[i] - '0');
                i--;
            }
            i++; // Adjust i to the correct position after the loop
            push(num);
        }
        else if (expression[i] == ' ' || expression[i] == '\t')
        {
            // Skip whitespaces
            continue;
        }
        else
        {
            // Operator encountered
            int operand1 = pop();
            int operand2 = pop();

            switch (expression[i])
            {
            case '+':
                operand = operand1 + operand2;
                break;
            case '-':
                operand = operand1 - operand2;
                break;
            case '*':
                operand = operand1 * operand2;
                break;
            case '/':
                operand = operand1 / operand2;
                break;
            default:
                printf("Invalid operator\n");
                exit(EXIT_FAILURE);
            }

            push(operand);
        }
    }

    return pop();
}

int main()
{
    char expression[MAX];

    printf("Enter the prefix expression: ");
    fgets(expression, MAX, stdin);
    expression[strcspn(expression, "\n")] = '\0'; // Remove newline character

    int result = evaluatePrefix(expression);

    printf("Result: %d\n", result);

    return 0;
}
