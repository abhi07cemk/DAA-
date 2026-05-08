#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int x[MAX];
int count = 0;

int place(int k, int i)
{
    for (int j = 1; j <= k - 1; j++)
    {
        if ((x[j] == i) || (abs(x[j] - i) == abs(j - k)))
        {
            return 0;
        }
    }
    return 1;
}

void printBoard(int n)
{
	for(int i = 1; i<=n; i++)
	{
		for(int j = 1; j<=n; j++)
		{
			if(x[i] == j)
			{
				printf("Q ");
			}
			else
			{
				printf("_ ");
			}
		}
		printf("\n");
	}
}

void NQueens(int k, int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (place(k, i))
        {
            x[k] = i;

            if (k == n)
            {
                count++;
		printBoard(n);
		printf("\n");

                for (int j = 1; j <= n; j++)
                {
                    printf("%d ", x[j]);
                }

                printf("\n");
            }
            else
            {
                NQueens(k + 1, n);
            }
        }
    }
}

int main()
{
    int n;

    printf("Enter Number of Queens: ");
    scanf("%d", &n);

    

    NQueens(1, n);

    printf("\nTotal Number of Solutions = %d\n", count);

    return 0;
}