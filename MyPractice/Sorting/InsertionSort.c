#include <stdio.h>

void insertionSort(int arr[], int n)
{
    int i, j;
    for (i = 1; i < n; i++)
    {
        int temp = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = temp;
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

    insertionSort(arr, size);

    return 0;
}