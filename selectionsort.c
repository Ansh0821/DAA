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

void selectionSort(int *a, int n)
{
    int index, temp;
    for (int i = 0; i < n - 1; i++)
    {
        index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[index])
            {
                index = j;
            }
        }
        temp = a[i];
        a[i] = a[index];
        a[index] = temp;
    }
}

void main()
{
    int n;
    clock_t start, end;
    printf("Enter the no. of goods:\n");
    scanf("%d",&n);
    int arr[n];
    printf("Random generated items:\n");
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand()%1000;
    }
    
    printArray(arr, n); 
    start = clock();
    selectionSort(arr, n);
    end = clock();
    printf("--------The sorted array is--------\n");
    printArray(arr, n);

    double final = (double)(end - start) / CLOCKS_PER_SEC;
    printf("The total time taken: %f\n",final);
}