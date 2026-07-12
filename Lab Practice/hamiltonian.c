#include <stdio.h>

int graph[10][10], path[10], n;

int isSafe(int v, int pos)
{
    int i;

    if(graph[path[pos-1]][v] == 0)
        return 0;

    for(i = 0; i < pos; i++)
        if(path[i] == v)
            return 0;

    return 1;
}

int Hamiltonian(int pos)
{
    int v;

    if(pos == n)
    {
        if(graph[path[n-1]][path[0]] == 1)
            return 1;
        else
            return 0;
    }

    for(v = 1; v < n; v++)
    {
        if(isSafe(v, pos))
        {
            path[pos] = v;

            if(Hamiltonian(pos + 1))
                return 1;

            path[pos] = -1;
        }
    }

    return 0;
}

int main()
{
    int i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    path[0] = 0;

    if(Hamiltonian(1))
    {
        printf("Hamiltonian Cycle: ");
        for(i = 0; i < n; i++)
            printf("%d ", path[i]);

        printf("%d", path[0]);
    }
    else
    {
        printf("No Hamiltonian Cycle");
    }

    return 0;
}