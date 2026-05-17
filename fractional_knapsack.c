#include <stdio.h>

int main()
{
    float wt[5], cost[5], x[5], pr = 0;
    int i, n, cu;

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter weights:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%f", &wt[i]);
    }

    printf("Enter costs:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%f", &cost[i]);
    }

    printf("Enter capacity: ");
    scanf("%d", &cu);

    for(i = 0; i < n; i++)
    {
        if(wt[i] > cu)
            break;
        else
        {
            cu = cu - wt[i];
            x[i] = 1.0;
            pr = pr + cost[i];
        }
    }

    if(i < n)
    {
        x[i] = cu / (float) wt[i];
        pr = pr + (x[i] * cost[i]);
    }

    printf("\nSelected fractions are:\n");

    for(i = 0; i < n; i++)
    {
        printf("%.2f\t", x[i]);
    }

    printf("\nMaximum Profit = %.2f", pr);

    return 0;
}