#include <stdio.h>
#include <stdlib.h>

void makeSet()
{
    int x;
    printf("Enter A Number : ");
    scanf("%d", &x);
    printf("%d is the Only Member of the Set and Hence it is the Set Representative", x);
}

int findSet()
{
    int arr[10], n, target;

    printf("Enter Array Size : ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter Elements %d : ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Enter Element to Search : ");
    scanf("%d", &target);

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            printf("Element Found!\n");
            printf("Set Representative = %d\n", arr[0]);
            return arr[0];
        }
    }

    printf("Element Not Found!\n");
    return -1;
}

void unionSet()
{
    int n1, n2, i, j, k;

    printf("Enter size of Array A: ");
    scanf("%d", &n1);

    int a[n1];

    printf("Enter elements of Array A (sorted):\n");
    for (i = 0; i < n1; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Enter size of Array B: ");
    scanf("%d", &n2);

    int b[n2];

    printf("Enter elements of Array B (sorted):\n");
    for (i = 0; i < n2; i++)
    {
        scanf("%d", &b[i]);
    }

    int c[n1 + n2]; // Maximum possible size

    i = 0;
    j = 0;
    k = 0;

    // Merge and remove common duplicates
    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
        {
            c[k++] = a[i++];
        }
        else if (b[j] < a[i])
        {
            c[k++] = b[j++];
        }
        else
        {
            c[k++] = a[i];
            i++;
            j++;
        }
    }

    // Copy remaining elements of A
    while (i < n1)
    {
        c[k++] = a[i++];
    }

    // Copy remaining elements of B
    while (j < n2)
    {
        c[k++] = b[j++];
    }

    printf("Array C (Union): ");
    for (i = 0; i < k; i++)
    {
        printf("%d ", c[i]);
    }
}

int extract_min()
{
    int arr[10], n;

    printf("Enter Array Size : ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter Elements %d : ", i + 1);
        scanf("%d", &arr[i]);
    }

    int min = arr[0];
    int pos = 0;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
            pos = i;
        }
    }

    printf("Minimum Element = %d\n", min);

    for (int i = pos; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    n--;

    printf("Array after Extracting Min : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return min;
}

int main()
{
    int ch;

    while (1)
    {
        printf("\n 1. Make Set \n 2. Find Set \n 3. Union \n 4. Extract Min \n 5. Exit \n");
        printf("Enter Your Choice : ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            makeSet();
            break;
        case 2:
            findSet();
            break;
        case 3:
            unionSet();
            break;
        case 4:
            extract_min();
            break;
        case 5:
            exit(1);
            break;
        default:
            printf("Invalid Choice!");
        }
    }
}