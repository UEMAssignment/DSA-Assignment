#include <stdio.h>
int array[] = {27, 15, 39, 21, 28, 70};
int size = sizeof(array) / sizeof(array[0]);

void selectionSort()
{
    int i, j, k, min, temp;

    printf("The original array is : ");
    printf("[ ");
    for (i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("]");
    printf("\n\n");

    for (i = 0; i < size - 1; i++)
    {
        min = i;
        for (j = i + 1; j < size; j++)
        {
            if (array[j] < array[min])
            {
                min = j;
            }
        }
        temp = array[i];
        array[i] = array[min];
        array[min] = temp;

        printf("Array after iteration %d: ", i + 1);
        printf("[ ");
        for (k = 0; k < size; k++)
        {
            printf("%d ", array[k]);
        }
        printf("]\n");
    }

    printf("The array after Selection Sorting is : ");
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
    selectionSort();
    return 0;
}
