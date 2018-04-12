#include <stdio.h>

typedef struct _innerstruct
{
   int innerint;
}innerstruct;

typedef struct _mystruct
{
   int intvar;
   char *strvar;
   innerstruct **pinner;
   int n_pinner;
}mystruct;

void fillinnerstruct(innerstruct *ainner,int n)
{
   ainner->innerint=n;
}
void fillstruct(mystruct *astruct,int n)
{
   int i;
   astruct->intvar=10+n;
   astruct->strvar=strdup("apoorva");
   for (i=0;i<n;i++)
   {
      innerstruct **ppinner=realloc(astruct->pinner,sizeof(innerstruct *)*(n+1));
      innerstruct *inner=calloc(1,sizeof(innerstruct));
      ppinner[i]=inner;
      fillinnerstruct(inner,i);
      astruct->pinner=ppinner;
   }
   astruct->n_pinner=n;
}
void innerdump(innerstruct *ainner)
{
   printf("\ninner->innerint : %d",ainner->innerint);
}
void structdump(mystruct *astruct)
{
   int i;
   printf("\nstruct->intvar : %d",astruct->intvar);
   printf("\nstruct->strvar : %s",astruct->strvar);
   printf("\nstruct->pinner : ");
   for(i=0;i<astruct->n_pinner;i++)
      innerdump(astruct->pinner[i]);
}
void main()
{
   mystruct *pastruct=calloc(1,sizeof(mystruct));
   printf("\nstruct -- just allocated... need to fill them ");
   fillstruct(pastruct, 5);
   printf("\nstruct -- just filled... need to print them ");
   structdump(pastruct);
   printf("\nstruct -- just printed...");
}
