#include <stdio.h>

void swap(float arr[], int i, int j);

int main()
{
    float wt[5], cost[5], ratio[5], x[5], pr = 0;
    float temp;
    int i, j, n, cu;

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter weights:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%f", &wt[i]);
    }

    printf("Enter costs:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%f", &cost[i]);
    }

    printf("Enter capacity: ");
    scanf("%d", &cu);

    for (i = 0; i < n; i++)
    {
        ratio[i] = cost[i] / wt[i];
        x[i] = 0.0;
    }

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (ratio[j] < ratio[j + 1])
            {
                // temp = ratio[j];
                // ratio[j] = ratio[j + 1];
                // ratio[j + 1] = temp;

                // temp = wt[j];
                // wt[j] = wt[j + 1];
                // wt[j + 1] = temp;

                // temp = cost[j];
                // cost[j] = cost[j + 1];
                // cost[j + 1] = temp;

                swap(ratio, j, j + 1);
                swap(wt, j, j + 1);
                swap(cost, j, j + 1);
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        if (wt[i] > cu)
            break;
        else
        {
            x[i] = 1.0;
            cu = cu - wt[i];
            pr = pr + cost[i];
        }
    }

    if (i < n)
    {
        x[i] = cu / wt[i];
        pr = pr + (x[i] * cost[i]);
    }

    printf("\nSelected fractions are:\n");

    for (i = 0; i < n; i++)
    {
        printf("%.2f\t", x[i]);
    }

    printf("\nMaximum Profit = %.2f\n", pr);

    return 0;
}

void swap(float arr[], int i, int j)
{
    float temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}