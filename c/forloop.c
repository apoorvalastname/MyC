#include<stdio.h>
#include<string.h>

typedef struct _newstruct
{
   int aint;
   char *bstr;
   int cint;
   char *dstr;
}newstruct;

typedef struct _basestruct
{
   int abaseint;
   char *bbasestr;
}basestruct;

void print_newstruct(newstruct *pnew)
{
   if (!pnew)
      return;
   printf("\n Newstruct aint : %d",pnew->aint);
   if (pnew->bstr)
      printf("\n Newstruct bstr : %s",pnew->bstr);

   printf("\n Newstruct cint : %d",pnew->cint);
   if (pnew->dstr)
      printf("\n Newstruct dstr : %s",pnew->dstr);
}

void print_basestruct(basestruct *pbase)
{
   if (!pbase)
      return;
   printf("\n Newstruct abaseint : %d",pbase->abaseint);
   if (pbase->bbasestr)
      printf("\n Newstruct bbasestr : %s",pbase->bbasestr);
}

void main()
{
   
   basestruct *pbase = calloc(1,sizeof(basestruct));
   pbase->abaseint = 300;
   pbase->bbasestr = strdup("got");
   printf ("\nApoorva -- basestruct : \n");
   print_basestruct(pbase);

   newstruct *pnew = calloc(1,sizeof(newstruct));
   pnew->aint = 100;
   pnew->bstr = strdup("pardon");
   pnew->cint = 200;
   pnew->dstr = strdup("dwarf");
   printf ("\nApoorva -- newstruct : \n");
   print_newstruct(pnew);

   basestruct *p1base=(basestruct *)pnew;
   printf ("\nApoorva -- base--new--struct : \n");
   print_basestruct(p1base);

   newstruct *p1new=(newstruct *)pbase;
   printf ("\nApoorva -- new111--struct : \n");
   print_newstruct(p1new);

}

