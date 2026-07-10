#include<stdio.h>

int LS(int arr[], int n, int key, int index)
{
    if(index >= n)
    {
        return -1;
    }
    if(arr[index] == key)
    {
        return index;
    }
    return LS(arr,n,key,index+1);
}

int main()
{
    int arr[20], n, key;
    printf("Enter Size : ");
    scanf("%d", &n);
    printf("Enter elements : ");
    for(int i = 0; i<n;  i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter Key : ");
    scanf("%d", &key);

    int result = LS(arr,n,key, 0);
    if(result == -1)
    {
        printf("Element not Found");
    }
    else{
        printf("Element found at Index %d", result);
    }
}