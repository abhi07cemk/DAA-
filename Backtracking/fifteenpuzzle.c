#include <stdio.h>

int ip[] = {1,2,3,4,5,6,7,8,9,10,16,11,13,14,15,12};

int pat[] = {0,1,0,1,1,0,1,0,0,1,0,1,1,0,1,0};

int main()
{
    int i, j;
    int count = 0;

    for(i = 0; i < 15 - 1; i++)
    {
        for(j = i + 1; j < 15; j++)
        {
            if(ip[j] < ip[i] && ip[j] != 16)
            {
                count++;
            }
        }
    }

    for(i = 0; i < 15; i++)
    {
        if(ip[i] == 16)
        {
            count += pat[i];
        }
    }

    if(count % 2 == 0)
    {
        printf("Solvable");
    }
    else
    {
        printf("Unsolvable");
    }

    return 0;
}