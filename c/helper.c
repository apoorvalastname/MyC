#include <stdio.h>
#include "helper.h"
void print_a(int *a, size_t asize)
{
   int i;
   for (i=0;i<asize;i++)
      printf("%d ",a[i]);
   printf("\n");
}
void print_title(char *title, int *a, size_t asize)
{
   printf("\n--------------------------------------------------\n");
   printf("%16s :  ",title);
   print_a(a,asize);
   printf("\n--------------------------------------------------\n");
}
void print_subtitle(char *title)
{
   printf (" %s  : \n\t",title);
}


