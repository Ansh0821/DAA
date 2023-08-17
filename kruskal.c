#include <stdio.h>
#include <stdlib.h>
int p[10];
int parent(int x)
{
    while (x != p[x])
    {
        x = p[x];
    }
    return x;
}
void kruskal(int graph[10][10], int n)
{
    int u, v;
    int ne = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        p[i] = i;
    }
    while (ne < n - 1)
    {
        int min = 999;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (min > graph[i][j])
                {
                    min = graph[i][j];
                    u = i;
                    v = j;
                }
            }
        }
        if (parent(u) != parent(v))
        {
            printf("\n Connect %d->%d=%d\n", u, v, graph[u][v]);
            ne++;
            sum = sum + graph[u][v];
            p[v] = u;
        }
        graph[u][v] = 999;
        graph[v][u] = 999;
    }
    printf("MST %d\n", sum);
}
int main()
{
    int n, graph[10][10];
    printf("\n Enter no of vertices: ");
    scanf("%d", &n);
    printf("Enter the graph: \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
        printf("\n");
    }
    kruskal(graph, n);
}