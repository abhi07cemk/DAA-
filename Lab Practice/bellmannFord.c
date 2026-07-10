#include <stdio.h>

#define INF 999

void BF(int adj[][10], int n)
{
    int x[10];
    int i, j, k, st;

    for (int i = 0; i < n; i++)
    {
        x[i] = INF;
    }

    printf("Enter Starting Vertex : ");
    scanf("%d", &st);

    x[st] = 0;

    for (k = 1; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (adj[i][j] != INF && x[i] != INF && x[j] > x[i] + adj[i][j])
                {
                    x[j] = x[i] + adj[i][j];
                }
            }
        }
    }
    printf("\n Shortest Distance : \n");
    for (i = 0; i < n; i++)
    {
        if (x[i] == INF)
        {
            printf("INF");
        }
        else
        {
            printf("%d ", x[i]);
        }
    }
    printf("\n");

    int flag = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (adj[i][j] != INF && x[i] != INF && x[j] > x[i] + adj[i][j])
            {
                flag = 1;
            }
        }
    }
    if(flag)
        printf("Negative Cycle Exist.\n");
    else
        printf("Negative Cycle do not exist.\n");
}

int main()
{
    int n, adj[10][10], i, j;

    printf("Enter Number of Vertices : ");
    scanf("%d", &n);

    printf("Enter Adjacency Matrix (use %d for no edge):\n", INF);

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }

    BF(adj, n);

    return 0;
}