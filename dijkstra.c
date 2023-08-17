#include <stdio.h>
#include <stdlib.h>
int dist[10];
int visited[10];
void dijk(int V[10][10], int n, int source)
{
    int u, v;
    for (int i = 0; i < n; i++)
    {
        dist[i] = V[source][i];
        visited[i] = 0;
    }
    visited[source] = 1;
    for (int ne = 0; ne < n; ne++)
    {
        int min = 999;
        for (int i = 0; i < n; i++)
        {
            if (visited[i] == 0 && min > dist[i])
            {
                min = dist[i];
                u = i;
            }
        }
        visited[u] = 1;
        for (v = 0; v < n; v++)
        {
            if (visited[v] == 0 && dist[v] > dist[u] + V[u][v])
            {
                dist[v] = dist[u] + V[u][v];
            }
        }
    }
}
int main()
{
    int V[10][10], n;
    printf(" Enter no of vertices: \n");
    scanf("%d", &n);
    printf(" Enter graph: \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &V[i][j]);
        }
        printf("\n");
    }
    int source = 0;
    dijk(V, n, source);
    printf("\n ---SSP--- from source");
    for (int i = 0; i < n; i++)
    {
        printf("\n  %d->%d=%d", source, i, dist[i]);
    }
    return 0;
}