#include <stdio.h>

void bubbleSort(int arr[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
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

    bubbleSort(arr, size);

    return 0;
}