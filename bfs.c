#include <stdio.h>
#include <stdlib.h>

struct queue 
{
    int size;
    int r;
    int f;
    int *arr;
};

int isEmpty(struct queue *q)
{
    if (q->r == q->f)
    {
        return 1;
    }
    return 0;
}

int isFull(struct queue *q)
{
    if (q->r == q->size - 1)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct queue *q, int val)
{
    if (isFull(q))
    {
        printf("Queue already full!!!\n");
    }
    else
    {
        q->r++;
        q->arr[q->r] = val;
    }
}

int dequeue(struct queue *q)
{
    int a = -1;
    if (isEmpty(q))
    {
        printf("Queue already empty!!!\n");
    }
    else
    {
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}

void main()
{
    struct queue q;
    q.size = 100;
    q.r = q.f = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));

    int start_node = 0, n, u;
    int graph[10][10];
    printf("Enter no. of nodes:\n");
    scanf("%d", &n);
    int visited[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("-------------BFS Traversal-------------\n");
    printf("%d",start_node);
    visited[start_node] = 1;
    enqueue(&q, start_node);

    while (!isEmpty(&q))
    {
        int u = dequeue(&q);
        for (int j = 0; j < n; j++)
        {
            if (graph[u][j] == 1 && visited[j] == 0)
            {
                printf("%d", j);
                visited[j] = 1;
                enqueue(&q, j);
            }
        }
    }
    free(q.arr);
}
