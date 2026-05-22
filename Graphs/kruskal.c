#include <stdio.h>

int parent[10];


int find(int i)
{
    while(parent[i] != i)
    {
        i = parent[i];
    }

    return i;
}


void uni(int a, int b)
{
    parent[a] = b;
}

int main()
{
    int n, i, j;
    int cost[10][10];
    int min, a, b;
    int u, v;
    int edges = 0;
    int mincost = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost adjacency matrix:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);

            if(cost[i][j] == 0)
            {
                cost[i][j] = 999;
            }
        }
    }

    /* initialize parent array */
    for(i = 0; i < n; i++)
    {
        parent[i] = i;
    }

    printf("\nEdges selected:\n");

    while(edges < n - 1)
    {
        min = 999;

        /* find minimum edge */
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                if(cost[i][j] < min)
                {
                    min = cost[i][j];

                    a = u = i;
                    b = v = j;
                }
            }
        }

        u = find(u);
        v = find(v);

        /* check cycle */
        if(u != v)
        {
            printf("%d -> %d = %d\n", a, b, min);

            mincost = mincost + min;

            uni(u, v);

            edges++;
        }

        cost[a][b] = cost[b][a] = 999;
    }

    printf("\nMinimum cost = %d", mincost);

    return 0;
}