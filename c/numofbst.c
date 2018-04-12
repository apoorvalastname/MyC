#include <stdio.h>
#include <stdlib.h>

// This function computes the number of binary search trees possible
// for a give set of unique values/keys
int num_of_bt(int n)
{
   int i, sum;
   if (n==0 || n==1)
      return 1;
   for (sum=0,i=0;i<n;i++)
      sum+=num_of_bt(n-1-i)*num_of_bt(i);
   return sum;
}

void main()
{
   int n;
   printf("\n Number of binary search trees that are possible for an input of n keys. n = ");
   scanf("%d",&n);
   printf("\n Number of binary search trees for %d keys : %d \n",n, num_of_bt(n));
}
