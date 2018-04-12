//input = 3
//1 2 3
//8 9 4
//7 6 5
//
//input = 4
//01 02 03 04
//12 13 14 05
//11 16 15 06
//10 09 08 07
//
//input = 8
//1  2  3  4  5  6  7  8
//28 29 30 31 32 33 34 9
//27 48 49 50 51 52 35 10
//26 47 60 61 62 53 36 11
//25 46 59 64 63 54 37 12
//24 45 58 57 56 55 38 13
//23 44 43 42 41 40 39 14
//22 21 20 19 18 17 16 15

#include <stdio.h>
#include <stdlib.h>

void printspiral(int n, int **spiral)
{
   size_t i, j;
   for(i=0;i<n;i++)
   {
      printf("\n");
      for(j=0;j<n;j++)
      {  
         printf(" %d ",spiral[i][j]);
      }
   }
   printf("\n\n\n");
}

int** spiral(int n)
{
   int i,j,x;
   int **twoD=calloc(n,sizeof(int *));
   for (i=0;i<n;i++)
      twoD[i]=calloc(n,sizeof(int));
   for (x=0,i=0;i<(n-i);i++)
   {
      for(j=i;j<(n-i);j++)
         twoD[i][j]=++x;
      for(j=i+1;j<(n-i);j++)
         twoD[j][n-i-1]=++x; 
      for(j=n-i-2;j>=i;j--)
         twoD[n-i-1][j]=++x;
      for(j=n-i-2;j>i;j--)
         twoD[j][i]=++x;
   }   
   return (twoD);
}
void freespiral(int n,int **twoD)
{
   size_t i=0;
   for(i=0;i<n;i++)
      free(twoD[i]);
   free(twoD);
}
void main()
{
   int n;
   printf("\n Enter the value of n to get the spiral of that size : ");
   scanf("%d",&n);
   int **twoD=spiral(n);
   printspiral( n,twoD);
   freespiral(n,twoD);
}
