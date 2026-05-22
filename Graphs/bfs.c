#include <stdio.h>

int visited[10];
int adj[10][10];
int q[10];
int front = 0, rear = -1;

void enq(int d)
{
    rear = rear + 1;
    q[rear] = d;
}


int qdel()
{
    int d;
    d = q[front];

    printf("%d ", d);

    front = front + 1;

    return d;
}


void BFS(int n, int st)
{
    int d, i;

    enq(st);
    visited[st] = 1;

    d = qdel();

    for(i = 0; i < n; i++)
    {
        if(adj[d][i] == 1 && visited[i] == 0)
        {
            enq(i);
            visited[i] = 1;
        }
    }

    while(front <= rear)
    {
        d = qdel();

        for(i = 0; i < n; i++)
        {
            if(adj[d][i] == 1 && visited[i] == 0)
            {
                enq(i);
                visited[i] = 1;
            }
        }
    }
}

int main()
{
    int n, st, i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }

    for(i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    printf("Enter starting vertex: ");
    scanf("%d", &st);

    printf("BFS Traversal: ");

    BFS(n, st);

    return 0;
}