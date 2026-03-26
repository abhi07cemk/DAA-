#include <stdio.h>

int binarySearch(int arr[], int left, int right, int key) {
    if (left > right) return -1;
    int mid = left + (right - left) / 2;
    if (arr[mid] == key) return mid;
    if (arr[mid] > key) return binarySearch(arr, left, mid - 1, key);
    return binarySearch(arr, mid + 1, right, key);
}

int main()
{
    int arr[20], n, target, result;

    printf("Enter Array Size : ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter Element %d : ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Enter Element to Search : ");
    scanf("%d", &target);

    result = binarySearch(arr, 0, n - 1, target);

    if (result != -1)
        printf("Element found at index %d", result);
    else
        printf("Element not found");

    return 0;
}