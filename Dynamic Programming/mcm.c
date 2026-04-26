#include <stdio.h>
#include <limits.h>

#define N 4  // number of dimensions (matrices = N-1)

int main()
{
    int p[N] = {1, 2, 3, 4};  // dimensions
    int m[N][N];  // cost table

    int i, j, k, L, q;

    // Cost is zero for single matrix
    for (i = 1; i < N; i++)
        m[i][i] = 0;

    // L = chain length
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
                }
            }
        }
    }

    printf("Minimum number of multiplications: %d\n", m[1][N - 1]);

    return 0;
}