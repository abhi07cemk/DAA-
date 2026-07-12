#include <stdio.h>

#define INF 9999

int main()
{
    int n, cost[10][10], dist[10], visited[10];
    int i, j, start, min, next;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);

    printf("Enter source vertex: ");
    scanf("%d", &start);

    // Initialization
    for(i = 0; i < n; i++)
    {
        dist[i] = cost[start][i];
        visited[i] = 0;
    }

    dist[start] = 0;
    visited[start] = 1;

    // Dijkstra Algorithm
    for(i = 1; i < n; i++)
    {
        min = INF;

        for(j = 0; j < n; j++)
        {
            if(!visited[j] && dist[j] < min)
            {
                min = dist[j];
                next = j;
            }
        }

        visited[next] = 1;

        for(j = 0; j < n; j++)
        {
            if(!visited[j] && dist[next] + cost[next][j] < dist[j])
            {
                dist[j] = dist[next] + cost[next][j];
            }
        }
    }

    printf("\nShortest Distances:\n");
    for(i = 0; i < n; i++)
        printf("%d -> %d = %d\n", start, i, dist[i]);

    return 0;
}