#include <stdio.h>

#define MAX 20

int x[MAX];
int count = 0;

int place(int k, int i, int graph[][MAX])
{
    for (int j = 1; j <= k - 1; j++)
    {
        if (graph[k][j] == 1 && x[j] == i)
        {
            return 0;
        }
    }
    return 1;
}

void GC(int k, int n, int m, int graph[][MAX])
{
    for (int i = 1; i <= m; i++)
    {
        if (place(k, i, graph))
        {
            x[k] = i;
            if (k == n)
            {
                count++;
                for (int j = 1; j <= n; j++)
                {
                    printf("%d ", x[j]);
                }
                printf("\n");
            }
            else
            {
                GC(k + 1, n, m, graph);
            }
        }
    }
}

int main()
{
    int n, m;
    int graph[MAX][MAX];

    printf("Enter number of vertices : ");
    scanf("%d", &n);

    printf("Enter number of Colours :  ");
    scanf("%d", &m);

    printf("Enter Adjacency Matrix : ");

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
    printf("\n");
    GC(1, n, m, graph);

    printf("Total Number of Solutions : %d", count);
}