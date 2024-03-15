#include <stdio.h>

int array[] = {27, 15, 39, 21, 28, 70};
int size = sizeof(array) / sizeof(array[0]);

void bubbleSort()
{
    int i, j, temp;

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
        for (j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }

        printf("Array after iteration %d: ", i + 1);
        printf("[ ");
        for (int k = 0; k < size; k++)
        {
            printf("%d ", array[k]);
        }
        printf("]\n");
    }

    printf("\nThe array after bubble sorting is : ");
    printf("[ ");
    for (i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("]");
}

int main()
{
    bubbleSort();
    return 0;
}
