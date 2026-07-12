// #include<stdio.h>

// int ip[] = {1,2,3,4,5,6,7,8,9,10,16,11,13,14,15,12};

// int pat[] = {0,1,0,1,1,0,1,0,0,1,0,1,1,0,1,0};

// int main()
// {
//     int i,j;
//     int count = 0;

//     for(i = 0; i<15-1; i++)
//     {
//         for(j = i+1; j<15; j++)
//         {
//             if(ip[j] < ip[i])
//             {
//                 count++;
//             }
//         }
//     }
//     for(i=0; i<15;i++)
//     {
//         if(ip[i] == 16)
//         {
//             count += pat[i];
//         }
//     }
//     if(count%2 == 0)
//     {
//         printf("Solvable");
//     }
//     else
//     {
//         printf("Unsolvable");
//     }
//     return 0;
// }

#include<stdio.h>

//int ip[] = {1,2,3,4,5,6,7,8,9,10,16,11,13,14,15,12};
//
//int pat[] = {0,1,0,1,1,0,1,0,0,1,0,1,1,0,1,0};

int main()
{
	int ip[16], pat[16];
	int i,j;
	int count = 0;
	
	printf("Enter the 16 Puzzle Numbers : ");
	for(int  i = 0; i<16; i++)
	{
		scanf("%d", &ip[i]);
	}
	
	printf("Enter the Pattern Values : ");
	for(i = 0; i<16; i++)
	{
		scanf("%d", &pat[i]);
	}
	
	for(i = 0; i<15-1; i++)
	{
		for(j = i+1; j<15;  j++)
		{
			if(ip[j] < ip[i])
			{
				count++;
			}
		}
	}
	for(i = 0; i<15; i++)
	{
		if(ip[i] == 16)
		{
			count += pat[i];
		}
	}
	
	if(count % 2 == 0)
		printf("SOlvable");
	else
	{
		printf("Unsolvable");
	}
}