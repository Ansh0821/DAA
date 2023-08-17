#include <stdio.h>

void printGraph(int a[10][10], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
}

int min(int x, int y)
{
    if (x > y)
    {
        return y;
    }
    return x;
}

void floyd(int dist[10][10], int n)
{
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                dist[i][j] = min(dist[i][j], (dist[i][k] + dist[k][j]));
            }
        }
    }
}

void main()
{
    int graph[10][10], n;
    printf("Enter the no. of nodes:\n");
    scanf("%d", &n);

    printf("Enter the elements of matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    printGraph(graph, n);
    floyd(graph, n);
    printf("The all pair shortest path is:\n");
    printGraph(graph, n);
}