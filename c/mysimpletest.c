#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _teststruct 
{
   char * teststr;
   int testint;
} teststruct;

static fun1(char **p, int n)
{
   int i;
   for (i=0;i<n;i++)
       printf ("%s\n",p[i]);
}

void main()
{
    char **name,*myname;
    int i,j;
    char p[100];
    printf("Enter all your friends' names (q to quit) : \n");
    scanf("%s",p);
    for(i=0;(strcmp(p,"q"));i++)
    {
       myname = calloc(sizeof(char *)*strlen(p),1);
       strcpy(myname,p);
       name = (char **)realloc(name, sizeof(char *)*(i+1));
       name[i] = myname;
       scanf("%s",p);
    }
    fun1 (name,i);

    char *checkempty = calloc(25,sizeof(char));
    if (checkempty)
       printf("\n Apoorva -- checkempty string is allocated");
    if (checkempty && *checkempty)
       printf("\n Apoorva -- lets see checkempty string has value ");
    else
       printf("\n Apoorva -- lets see checkempty string has no value ");

    teststruct *newstruct=calloc(1,sizeof(teststruct));
    if (!newstruct)
       printf("\n Apoorva -- newstruct is alloced ");
    if (*newstruct)
       printf("\n Apoorva -- newstruct has value " );
    else
       printf("\n Apoorva -- newstruct has no value " );


}






