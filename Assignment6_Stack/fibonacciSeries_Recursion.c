// #include <stdio.h>
// void fibonacciSeries(int n, int a, int b)
// {
//     if (n > 0)
//     {
//         printf("%d ", a);
//         fibonacciSeries(n - 1, b, a + b);
//     }
// }

// void main()
// {
//     int n;

//     printf("Enter the number of terms in the Fibonacci series: ");
//     scanf("%d", &n);

//     printf("Fibonacci Series: ");

//     // Starting the series with 0 and 1
//     fibonacciSeries(n, 0, 1);

//     printf("\n");
// }

// ..............................................................................................

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
    int range, fibo, i;
    printf("Enter the range : ");
    scanf("%d", &range);
    for (i = 0; i < range; i++)
    {
        printf("%d ", fibonacci(i));
    }
}