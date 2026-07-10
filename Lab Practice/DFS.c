#include<stdio.h>
int visited[10];
int adj[10][10];

void DFS(int n, int st)
{
    int i;
    printf("%d", st);

    visited[st] = 1;

    for(i = 0; i<n; i++)
    {
        if(adj[st][i] == 1 && visited[i] == 0)
        {
            DFS(n,i);
        }
    }
}

int main()
{
    int n,st,i,j;
    printf("Enter Number of Vertices : ");
    scanf("%d", &n);

    printf("Enter Adjacency Matrix : ");
    for(i = 0; i<n; i++)
    {
        for(j = 0; j<n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }

    for(i = 0; i<n; i++)
    {
        visited[i] = 0;
    }

    printf("Enter Starting Vertex : ");
    scanf("%d", &st);

    printf(" DFS Traversal : ");

    DFS(n,st);
    return 0;
}