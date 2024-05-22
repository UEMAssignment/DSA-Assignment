#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        int min = i;

        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }

        if (min != i)
        {
            swap(&arr[i], &arr[min]);
        }
    }

    printf("Sorted array : \n");

    for (i = 0; i < n; i++)
    {
        printf("%d \t", arr[i]);
    }
}

int main()
{
    int arr[] = {17, 15, 11, 18, 0, -8};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Previous array : \n");

    for (int i = 0; i < size; i++)
    {
        printf("%d \t", arr[i]);
    }

    printf("\n");

    selectionSort(arr, size);

    return 0;
}