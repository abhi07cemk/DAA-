#include <stdio.h>

#define INF 999

void BF(int adj[][10], int n)
{
	int x[] = {999,999,999,999,999};
	int i,j,k,st;
	printf("Enter Starting Vertex : ");
	scanf("%d", &st);
	x[st] = 0;

	for(k = 1; k<n; k++)
	{
		for(i = 0; i<n; i++)
		{
			for(j = 0; j<n; j++)
			{
				if(x[j] > x[i] + adj[i][j])
					x[j] = x[i] + adj[i][j];
			}
		}
	}
	for (i = 0; i<n; i++)
	{
		printf("%d ", x[i]);
	}
    printf("\n");
	printf("Checking For Negative Loop ");
    printf("\n");
	for(i = 0; i<n; i++)
	{
		for(j = 0; j<n; j++)
		{
			if(x[j] > x[i] + adj[i][j])
			{
				x[j] = x[i]+adj[i][j];
			}
		}
	}
	for (i = 0; i<n; i++)
	{
		printf("%d ", x[i]);
	}
}
int main()
{
	int n, adj[10][10],i,j;
	printf("Enter Number of Vertices : ");
	scanf("%d", &n);
	for(i = 0; i<n; i++)
	{
		for(j = 0; j<n; j++)
		{
			scanf("%d", &adj[i][j]);

		}
	}
	BF(adj,n);
	return 0;
}