
#include <stdio.h>

void swap(float arr[], int i, int j)
{
    float temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int main() {
    
    int n,i,j;
    float capacity;

    float totalProfit = 0.0;
    // float weight, profit, x, pr = 0;

    printf("Enter Knapsack Capacity : ");
    scanf("%f", &capacity);
    
    printf("Enter Number of Items : ");
    scanf("%d", &n);
    
    float profit[n];
    float weight[n];
    float ratio[n];
    float x[n];

    printf("Enter Profits of the Items : ");

    for(i = 0; i<n; i++)
    {
        scanf("%f", &profit[i]);
    }
    
    printf("Enter Weights of the Items :  ");

    for(i = 0; i<n; i++)
    {
        scanf("%f", &weight[i]);
    }

    for(i = 0; i<n; i++)
    {
        ratio[i] = profit[i]/weight[i];
        x[i] = 0.0; 
    }

    for(i=0; i<n-1; i++)
    {
        for(j = 0; j<n-i-1; j++)
        {
            if(ratio[j] < ratio[j+1])
            {
                swap(ratio,j,j+1);
                swap(weight,j,j+1);
                swap(profit,j,j+1);
            }
        }
    }
    for(i = 0; i<n; i++)
    {
        if(weight[i] > capacity)
            break;
        else
        {
            capacity -= weight[i];
            x[i] = 1.0;
            totalProfit += profit[i];
        }
    }

    if(i < n)
    {
        x[i] = capacity / (float) weight[i];
        totalProfit += (x[i] * profit[i]);
    }

    printf("\n Selected Fractions are : ");
    for(i = 0; i<n; i++)
    {
        printf("%.2f ", x[i]);
    }

    printf("\n Maximum Profit : %.2f\n",totalProfit);
    
    return 0;
}