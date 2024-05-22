#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    srand(time(NULL));

    int size = 10000; // You can change the input size as needed
    // Create dynamic arrays
    int *arr1 = malloc(size * sizeof(int));
    int *arr2 = malloc(size * sizeof(int));

    // Check for memory allocation failure
    if (arr1 == NULL || arr2 == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Initialize arrays with random values
    for (int i = 0; i < size; i++)
    {
        arr1[i] = arr2[i] = rand() % 1000;
    }

    clock_t start, end;

    // Measure time for merge sort
    start = clock();
    mergeSort(arr1, 0, size - 1);
    end = clock();
    printf("Merge Sort Time: %f seconds\n", ((double)(end - start)) / CLOCKS_PER_SEC);

    // Measure time for quicksort
    start = clock();
    quickSort(arr2, 0, size - 1);
    end = clock();
    printf("Quick Sort Time: %f seconds\n", ((double)(end - start)) / CLOCKS_PER_SEC);

    return 0;
}
