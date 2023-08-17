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

void merge(int a[], int low, int high, int mid)
{
    int b[high + 1];
    int i = low, j = mid + 1, k = low;

    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            b[k] = a[i];
            k++;
            i++;
        }
        else
        {
            b[k] = a[j];
            k++;
            j++;
        }
    }

    while (i <= mid)
    {
        b[k] = a[i];
        k++;
        i++;
    }

    while (j <= high)
    {
        b[k] = a[j];
        k++;
        j++;
    }

    for (i = low; i < high + 1; i++)
    {
        a[i] = b[i];
    }
}

void mergeSort(int a[], int low, int high)
{
    if (low < high)
    {
        int mid;
        mid = (low + high) / 2;
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        merge(a, low, high, mid);
    }
}

void main()
{
    int n;
    clock_t start, end;
    printf("Enter the no. of books:\n");
    scanf("%d", &n);
    int arr[n];
    printf("Random generated book ISBNs:\n");

    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 1000;
    }

    printArray(arr, n);
    
    start = clock();
    mergeSort(arr, 0, n-1);
    end = clock();

    printf("------The sorted array is------\n");
    printArray(arr, n);

    double final = (double)(end - start)/CLOCKS_PER_SEC;
    printf("The final time taken is: %f\n",final);
}