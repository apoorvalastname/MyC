#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Given a pyramid of consecutive integers:
// 1
// 2 3
// 4 5 6
// 7 8 9 10
// 11 12 13 14 15
// 16 17 18 19 20 21
// ......
//
// Find the sum of all the integers in the row number N.
// For example:
// The row #3: 4 + 5 + 6 = 15
// The row #5: 11 + 12 + 13 + 14 + 15 = 65   
void sum(int n)
{
   int i,sum;
   for(sum=i=0;i<n;i++)
      sum+=n*(n+1)/2-i;
   printf("Sum : %d",sum);

}


// Find the longest common suffix of two linked lists
typedef struct linkedlist
{
   char ch;
   struct linkedlist *next; 
}llist;

llist *firsthead, *secondhead;
void push(llist **node, char ch, bool first)
{
   llist *newnode=calloc(1,sizeof(llist));
   newnode->ch=ch;
   newnode->next=*node;
   *node=newnode; 
}
void printllist(llist *node)
{  
   printf("\n List : ");
   while (node)
   {
      printf("%c ",node->ch);
      node=node->next; 
   }
   printf("\n");
}
void recrevlist(llist **node, llist *prev)
{
   if (!*node)
   {
      *node=prev;
      return;
   }
   llist *curnode=*node;
   *node=curnode->next;
   curnode->next=prev;
   recrevlist(node,curnode);
}
void reversellist(llist **node)
{
   recrevlist(node,NULL);
}
void longestsuffix(llist *first, llist *second)
{
   llist *prev=first,*firsthead=first;
   for (;((first!=NULL) && (second!=NULL) && (first->ch==second->ch));prev=first,first=first->next,second=second->next);
   prev->next=NULL;
   printf("\nLongest Matching suffix ");
   reversellist(&firsthead);
   printllist(firsthead);
}

void main()
{
   //int n=0;
   //printf ("\n n = ");
   //scanf("%d",&n);
   //sum(n);

   llist *first=NULL, *second=NULL;
   printf("\nValues of first linked list : ");
   char ch = 'a';
   scanf("%c",&ch);
   while (ch!='\n')
   {
      push(&first,ch,true);
      scanf("%c",&ch);
   }
   ch = 'b';
   printf("\nValues of second linked list : ");
   scanf("%c",&ch);
   while (ch!='\n')
   {
      push(&second,ch,false);
      scanf("%c",&ch);
   }
   printllist(first);   
   printllist(second);   
   reversellist(&first);
   reversellist(&second);
   longestsuffix(first,second);
   
}
