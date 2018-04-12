#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _B
{
   int b1;
   int b2;
}B;
typedef struct _A
{
   int a1;
   int a2;
   char *a3;
   B *b;
}A;

A **globalas;
static int n;

void copyB(B *myb, B *b)
{
   if (!b || !myb)
      return;
   b->b1=myb->b1;
   b->b2=myb->b2;
}
void copyA(A *mya, A *a)
{
   if(!a || !mya)
      return;
   a->a1=mya->a1;
   a->a2=mya->a2;
   a->a3=strdup(mya->a3);
   a->b=calloc(1,sizeof(B));
   copyB((mya->b),(a->b));
}
void printB(B *b)
{
   if (!b)
      return;
   printf("B -- b1 : %d\n",b->b1);
   printf("B -- b2 : %d\n",b->b2);
}
void printA(A *a)
{
   if (!a)
      return;
   printf("A -- a1 : %d\n",a->a1);
   printf("A -- a2 : %d\n",a->a2);
   if (a->a3)
      printf("A -- a3 : %s\n",a->a3);
   if (a->b)
      printB(a->b); 
}
void setA(A **a, int i)
{
   char mystr[50];
   snprintf(mystr,50,"apoorva%d",i);
   A *mya=calloc(1,sizeof(A));
   mya->a1=i;
   mya->a2=i;
   mya->a3=strdup(mystr);
   mya->b=calloc(1,sizeof(B));
   mya->b->b1=i;
   mya->b->b2=i;
   *a=mya; 
}
void main()
{
   A *a;
   A *mya[5];
   int i,j,x,start=3,count=5;
   for (j=0,i=start;i<start+count;j++,i++)
   {
      a=calloc(1,sizeof(A));
      setA(&mya[j],i);
      copyA(mya[j],a);
      globalas=realloc(globalas,sizeof(A)*(j+1));
      globalas[j]=a;
      printf("\nPrinting Globalas struct \n");
      n=j+1;
      for (x=0;x<n;x++)
      {
         printf("Globalas - %d\n",x);
         printA(globalas[x]);
      }
      printf("\nPrinted Globalas struct : current n : %d\n",n);
   }
}



