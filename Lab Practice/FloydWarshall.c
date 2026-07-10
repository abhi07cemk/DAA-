#include <stdio.h>
void fw(int adj[][10], int n)
{
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (adj[i][j] > adj[i][k] + adj[k][j])
                {
                    adj[i][j] = adj[i][k] + adj[k][j];
                }
            }
        }
    }
    printf("\n Shortest Path Matrix : \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d \t", adj[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int adj[10][10], n, i, j;
    printf("Enter number of vertices : ");
    scanf("%d", &n);
    printf("Enter Adjacency Matrix : ");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }
    fw(adj, n);
}