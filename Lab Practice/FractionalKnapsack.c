#include<stdio.h>

void swap(float arr[], int i, int j)
{
    float temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int main()
{
    float wt[5], cost[5], x[5], ratio[5], pr = 0;
    float cu;
    int i,j,n;

    printf("Enter Number of items : ");
    scanf("%d", &n);

    printf("Enter Weights of the Items : ");
    for(i = 0; i<n; i++)
    {
        scanf("%f", &wt[i]);
        
    }
    printf("Enter Profits : ");
    for(i = 0; i<n; i++)
    {
        scanf("%f", &cost[i]);
        
    }

    printf("Enter Knapsack Capacity : ");
    scanf("%f", &cu);

    for(i = 0; i<n; i++)
    {
        ratio[i] = cost[i]/ wt[i];
        x[i] = 0.0;
    }

    for(i = 0; i<n-1; i++)
    {
        for(j = 0; j<n-i-1; j++)
        {
            if(ratio[j] < ratio[j+1])
            {
                swap(ratio,j,j+1);
                swap(wt,j,j+1);
                swap(cost,j,j+1);
            }
        }
    }

    for(i = 0; i<n; i++)
    {
        if(wt[i] > cu)
            break;
        else
        {
            cu = cu - wt[i];
            x[i] = 1.0;
            pr += cost[i];
        }
    }
    if(i < n)
    {
        x[i] = cu / (float) wt[i];
        pr += (x[i] * cost[i]);
    }

    printf("\n Selected Fractions are : \n");
    for( i = 0; i<n; i++)
    {
        printf("%2f\t", x[i]);
    }

    printf("\n Maximum Profit : %.2f", pr);
}

