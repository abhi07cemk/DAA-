#include <stdio.h>
#include <stdlib.h>

void makeSet()
{
    int x;
    printf("Enter A Number : ");
    scanf("%d", &x);
    printf("%d is the Only member of the Set and Hence it is the Set Representative", x);
}

int findSet()
{
    int n, target;
    printf("Enter Size of Array : ");
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter Element %d : ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("Enter Element to Search : ");
    scanf("%d", &target);
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            printf("Element found!\n");
            printf("Set Representative = %d\n", arr[0]);
            return arr[0];
        }
    }
    printf("Element Not Found!!");
    return -1;
}

void unionSet()
{
    int n1, n2, i, j, k;
    printf("Enter Size of first Array : ");
    scanf("%d", &n1);

    int a[n1];

    for (int i = 0; i < n1; i++)
    {
        printf("Enter Element %d : ", i + 1);
        scanf("%d", &a[i]);
    }

    printf("Enter Size of Second Array : ");
    scanf("%d", &n2);

    int b[n2];

    for (int i = 0; i < n2; i++)
    {
        printf("Enter Element %d : ", i + 1);
        scanf("%d", &b[i]);
    }

    int c[n1 + n2];

    i = 0, j = 0, k = 0;
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
    while (i < n1)
        c[k++] = a[i++];
    while (j < n2)
        c[k++] = b[j++];

    printf("Array C (union) : ");
    for (i = 0; i < k; i++)
    {
        printf("%d ", c[i]);
    }
}

void intersectionSet()
{
    int n1, n2, i, j, k;

    printf("Enter Size of First Array: ");
    scanf("%d", &n1);

    int a[n1];

    for (i = 0; i < n1; i++)
    {
        printf("Enter Element %d: ", i + 1);
        scanf("%d", &a[i]);
    }

    printf("Enter Size of Second Array: ");
    scanf("%d", &n2);

    int b[n2];

    for (i = 0; i < n2; i++)
    {
        printf("Enter Element %d: ", i + 1);
        scanf("%d", &b[i]);
    }

    int c[(n1 < n2) ? n1 : n2];

    i = j = k = 0;

    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
        {
            i++;
        }
        else if (a[i] > b[j])
        {
            j++;
        }
        else
        {
            c[k++] = a[i];
            i++;
            j++;
        }
    }

    printf("Intersection: ");
    for (i = 0; i < k; i++)
        printf("%d ", c[i]);
}

int extractMin()
{
    int n;
    printf("Enter Size of Array : ");
    scanf("%d", &n);
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter Element %d : ", i + 1);
        scanf("%d", &arr[i]);
    }

    int min = arr[0];
    int pos = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
            pos = i;
        }
    }
    printf("Minimum Element : %d ", min);
    for (int i = pos; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    n--;

    printf("\nArray after Extracting Min : ");
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
        printf("\n 1. Make Set\n 2. Find Set\n 3. Union Find\n 4. Intersection Set \n 5. Extract Min\n 6. Exit\n");
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
            intersectionSet();
            break;
        case 5:
            extractMin();
            break;
        case 6:
            exit(1);
            break;
        default:
            printf("Invalid Choice");
        }
    }
}