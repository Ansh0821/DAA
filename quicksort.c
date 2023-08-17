#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArray(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\n");
}

int partition(int a[], int low, int high)
{
    int i = low + 1;
    int j = high;
    int pivot = a[low];
    int temp;

    do
    {
        while (a[i] <= pivot)
        {
            i++;
        }
        while (a[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }

    } while (i < j);

    temp = a[low];
    a[low] = a[j];
    a[j] = temp;
    return j;
}

void quickSort(int a[], int low, int high)
{
    if (low < high)
    {
        int partitionIndex = partition(a, low, high);
        quickSort(a, low, partitionIndex - 1);
        quickSort(a, partitionIndex + 1, high);
    }
}

void main()
{
    int n;
    clock_t start, end;
    printf("Enter the no. of files:\n");
    scanf("%d", &n);
    int arr[n];
    printf("Random generated IDs:\n");
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 1000;
    }

    printArray(arr, n);

    start = clock();
    quickSort(arr, 0, n - 1);
    end = clock();

    printf("-------The sorted array is-------\n");
    printArray(arr, n);

    double final = (double)(end - start) / CLOCKS_PER_SEC;
    printf("The final time taken is: %f\n", final);
}