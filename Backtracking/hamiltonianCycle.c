#include <stdio.h>

int graph[10][10], x[10];
int n;

int place(int k, int v)
{
    if (graph[x[k - 1]][v] == 0)
        return 0;

    for (int i = 1; i < k; i++)
    {
        if (x[i] == v)
            return 0;
    }

    if (k == n && graph[v][x[1]] == 0)
        return 0;

    return 1;
}

void hamiltonian(int k)
{
    for (int v = 2; v <= n; v++)
    {
        if (place(k, v))
        {
            x[k] = v;

            if (k == n)
            {
                for (int i = 1; i <= n; i++)
                    printf("%d ", x[i]);

                printf("%d\n", x[1]);
            }
            else
            {
                hamiltonian(k + 1);
            }
        }
    }
}

int main()
{
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    x[1] = 1;

    printf("Hamiltonian Cycles:\n");

    hamiltonian(2);

    return 0;
}