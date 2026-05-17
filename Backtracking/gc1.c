#include <stdio.h>

#define MAX 20

int x[MAX];
int count = 0;

int place(int k, int i, int graph[][MAX])
{
    for(int j = 1; j <= k - 1; j++)
    {
        if(graph[k][j] == 1 && x[j] == i)
        {
            return 0;
        }
    }

    return 1;
}

void GraphColoring(int k, int n, int m, int graph[][MAX])
{
    for(int i = 1; i <= m; i++)
    {
        if(place(k, i, graph))
        {
            x[k] = i;

            if(k == n)
            {
                count++;

                for(int j = 1; j <= n; j++)
                {
                    printf("%d ", x[j]);
                }

                printf("\n");
            }
            else
            {
                GraphColoring(k + 1, n, m, graph);
            }
        }
    }
}

int main()
{
    int n, m;
    int graph[MAX][MAX];

    printf("Enter Number of Vertices : ");
    scanf("%d", &n);

    printf("Enter Number of Colors : ");
    scanf("%d", &m);

    printf("Enter Adjacency Matrix :\n");

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
    printf("\n");
    GraphColoring(1, n, m, graph);

    printf("\nTotal Number of Solutions = %d\n", count);

    return 0;
}