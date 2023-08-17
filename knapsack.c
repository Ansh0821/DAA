#include <stdio.h>

int max(int x, int y)
{
    if (x > y)
    {
        return x;
    }
    return y;
}

void knapsack(int w[], int p[], int n, int m)
{
    int V[10][10];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < m + 1; j++)
        {
            if (i == 0 || j == 0)
            {
                V[i][j] = 0;
            }
            else if (j < w[i])
            {
                V[i][j] = V[i - 1][j];
            }
            else
            {
                V[i][j] = max(V[i - 1][j], p[i] + V[i - 1][j - w[i]]);
            }
        }
    }

    printf("Maximum profit:%d\n", V[n][m]);

    int profit = V[n][m];
    for (int i = n; i > 0 && profit > 0; i--)
    {
        if (V[i][m] != V[i - 1][m])
        {
            printf("Item weight %d gives profit %d\n", w[i], p[i]);
            m = m - w[i];
            profit = profit - p[i];
        }
    }
}

void main()
{
    int w[] = {0, 2, 1, 5, 3};
    int p[] = {0, 15, 11, 10, 13};
    knapsack(w, p, 4, 5);
}