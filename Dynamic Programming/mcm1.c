#include <stdio.h>
#include <limits.h>

#define N 4  // dimensions (3 matrices)

int main()
{
    int p[N] = {1, 2, 3, 4};  // dimensions
    int m[N][N];  // cost matrix
    int s[N][N];  // split matrix

    int i, j, k, L, q;

    // Initialize diagonal to 0
    for (i = 1; i < N; i++)
        m[i][i] = 0;

    // Chain length
    for (L = 2; L < N; L++)
    {
        for (i = 1; i < N - L + 1; i++)
        {
            j = i + L - 1;
            m[i][j] = INT_MAX;

            for (k = i; k <= j - 1; k++)
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

    // Print Minimum Cost
    printf("Minimum number of multiplications: %d\n\n", m[1][N - 1]);

    // Print Cost Matrix
    printf("Cost Matrix (m):\n");
    for (i = 1; i < N; i++)
    {
        for (j = 1; j < N; j++)
        {
            if (j < i)
                printf("  - ");
            else
                printf("%3d ", m[i][j]);
        }
        printf("\n");
    }

    // Print Split Matrix
    printf("\nSplit Matrix (s):\n");
    for (i = 1; i < N; i++)
    {
        for (j = 1; j < N; j++)
        {
            if (j <= i)
                printf("  - ");
            else
                printf("%3d ", s[i][j]);
        }
        printf("\n");
    }

    return 0;
}