#include <stdio.h>

int fibonacci(int n)
{
    if (n <= 1)
    {
        return n;
    }
    else
    {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

void main()
{
    int range, fibo;
    printf("Enter the range : ");
    scanf("%d", &range);
    fibo = fibonacci(range);
    printf("%d\n", fibo);
}