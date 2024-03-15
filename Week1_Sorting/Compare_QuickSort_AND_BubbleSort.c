#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void swap(int *a, int *b);
int partition(int arr[], int low, int high);
void quickSort(int arr[], int low, int high);
void bubbleSort(int arr[], int n);

int main()
{
    srand(time(NULL));

    // Define the size of the array
    int n = 10000;

    // Create dynamic arrays
    int *arr1 = malloc(n * sizeof(int));
    int *arr2 = malloc(n * sizeof(int));

    // Check for memory allocation failure
    if (arr1 == NULL || arr2 == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Initialize arrays with random elements
    for (int i = 0; i < n; i++)
    {
        arr1[i] = arr2[i] = rand() % 1000;
    }

    // Measure time taken by Quick Sort
    clock_t start_quick = clock();
    quickSort(arr1, 0, n - 1);
    clock_t end_quick = clock();
    double time_quick = ((double)(end_quick - start_quick)) / CLOCKS_PER_SEC;

    // Measure time taken by Bubble Sort
    clock_t start_bubble = clock();
    bubbleSort(arr2, n);
    clock_t end_bubble = clock();
    double time_bubble = ((double)(end_bubble - start_bubble)) / CLOCKS_PER_SEC;

    // Display results
    printf("Quick Sort took %.6f seconds\n", time_quick);
    printf("Bubble Sort took %.6f seconds\n", time_bubble);

    // Free dynamically allocated memory
    free(arr1);
    free(arr2);

    return 0;
}

// Function to swap two elements in an array
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition the array for Quick Sort
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// Function to perform Quick Sort
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partition(arr, low, high);

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

// Function to perform Bubble Sort
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}
