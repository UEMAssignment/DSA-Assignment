#include <stdio.h>
int array[] = {27, 15, 39, 21, 28, 70};
int size = sizeof(array) / sizeof(array[0]);

void insertionSort()
{
    int i, j, k, key;

    printf("The Original array is : ");
    printf("[ ");
    for (i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("]");
    printf("\n\n");

    for (i = 1; i < size; i++)
    {
        key = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;

        printf("Array after iteration %d: ", i);
        printf("[ ");
        for (k = 0; k < size; k++)
        {
            printf("%d ", array[k]);
        }
        printf("]\n");
    }

    printf("The array after Insertion Sorting is : ");
    printf("[ ");
    for (i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("]");
    printf("\n\n");
}

int main()
{
    insertionSort();
    return 0;
}