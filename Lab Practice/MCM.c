#include <stdio.h>

void MCM(int p[], int n)
{
    int m[n + 1][n + 1];
    int s[n + 1][n + 1];
    int i, j, k, l, q;

    for (i = 1; i <= n; i++)
        m[i][i] = 0;

    for (l = 2; l <= n; l++)
    {
        for (i = 1; i <= n - l + 1; i++)
        {
            j = i + l - 1;
            m[i][j] = 999999;

            for (k = i; k < j; k++)
            {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];

                if (q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    printf("\nMinimum Number of Multiplications = %d\n", m[1][n]);

    printf("\nCost Matrix:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (j < i)
                printf("  - ");
            else
                printf("%3d ", m[i][j]);
        }
        printf("\n");
    }

    printf("\nSplit Matrix:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (j <= i)
                printf("  - ");
            else
                printf("%3d ", s[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int n, i;

    printf("Enter number of matrices: ");
    scanf("%d", &n);

    int p[n + 1];

    printf("Enter %d dimensions: ", n + 1);
    for (i = 0; i <= n; i++)
        scanf("%d", &p[i]);

    MCM(p, n);

    return 0;
}