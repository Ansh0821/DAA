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

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void heapify(int a[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && a[l] > a[largest])
    {
        largest = l;
    }

    if (r < n && a[r] > a[largest])
    {
        largest = r;
    }

    if (largest != i)
    {
        swap(&a[largest], &a[i]);
        heapify(a, n, largest);
    }
}

void maxHeap(int a[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(a, n, i);
    }

    printf("------Max Heap------\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\n");
}

void heapSort(int a[], int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        swap(&a[i], &a[0]);
        heapify(a, i, 0);
    }
}

void main()
{
    int n;
    clock_t start, end;
    printf("Enter the no. of graduates:\n");
    scanf("%d", &n);
    int arr[n];

    srand(time(NULL));
    printf("Random generated rankings are:\n");
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 1000;
    }

    printArray(arr, n);
    maxHeap(arr, n);
    printf("The sorted array is:\n");

    start = clock();
    heapSort(arr, n);
    end = clock();

    printArray(arr, n);

    double final = (double)(end - start) / CLOCKS_PER_SEC;
    printf("The total time taken is:%d\n", final);
}