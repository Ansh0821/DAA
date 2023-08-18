#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubble(int *a, int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void printArray(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\n");
}

void main()
{
    int n;
    clock_t start, end;
    printf("Enter the no. of goods:\n");
    scanf("%d", &n);
    int arr[n];

    srand(time(NULL));
    printf("Random generated items:\n");
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 1000;
    }

    printArray(arr, n);
    start = clock();
    bubble(arr, n);
    end = clock();
    printf("--------The sorted array is--------\n");
    printArray(arr, n);

    double final = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\n Total time taken = %f", final);
}