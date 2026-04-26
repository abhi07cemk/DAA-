#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 20

int x[MAX]; // Global array to store column positions

// Function to check if placing queen at (k, i) is valid
int Place(int k, int i)
{
    for (int j = 1; j <= k - 1; j++)
    {
        // Check same column OR same diagonal
        if ((x[j] == i) || (abs(x[j] - i) == abs(j - k)))
        {
            return 0; // false
        }
    }
    return 1; // true
}

// Function to solve N-Queens using backtracking
void NQueens(int k, int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (Place(k, i))
        {
            x[k] = i;

            if (k == n)
            {
                // Print solution
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
    printf("Enter number of queens: ");
    scanf("%d", &n);

    NQueens(1, n);

    return 0;
}