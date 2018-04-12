#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
}

static fun7(char **p, int n)
{
   iame[i] = myname;
       scanf("%s",p);
    }
    fun1 (name,i);

}

static fun2(char **p, int n)
{
   int i;
   for (i=0;i<n;i++)
       printf ("%s\n",p[i]);
}

void fun3()
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

}


void fun4()
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

}









