#include <stdio.h>

int adj[10][10], visited[10];
int queue[10], front = 0, rear = -1;
int n;

void BFS(int start)
{
    int i;

    visited[start] = 1;
    queue[++rear] = start;

    while (front <= rear)
    {
        int st = queue[front++];

        printf("%d ", st);

        for (i = 0; i < n; i++)
        {
            if (adj[st][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }
}

int main()
{
    int i, j, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("BFS Traversal: ");
    BFS(start);

    return 0;
}