#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "helper.h"

typedef struct _linkedlist
{
   int val;
   struct _linkedlist *next;
}llist;

void print_ll (llist *head, char *title)
{
   print_subtitle(title);
   for (;head!=NULL;head=head->next)
      printf(" %d ",head->val);
   printf("\n");
}

llist *reverse_ll (llist *head, llist *reversedlist)
{
   if (!head)
      return reversedlist;
   llist *tmpnode = head->next;
   head->next=reversedlist;
   reverse_ll(tmpnode,head);
}

llist *insert_ll (int val, llist *head, llist **ptail, bool stack)
{
   llist *node = calloc(1,sizeof(llist));
   node->val=val;
   if (stack)
   {
      node->next=head;
      head=node;
   }
   else
   {  
      node->next=NULL;
      llist *tail=*ptail;
      if (tail)
      {
         tail->next=node;
         *ptail=node;
      }
      else
         head=*ptail=node;
   }
   return (head);
}

llist *create_ll(int *a, size_t asize, bool stack)
{  
   llist *head=NULL, *tail=NULL;
   size_t i=0;
   for (i=0;i<asize;i++)
      head=insert_ll (a[i],head, &tail, stack);
   return head;
}
void main()
{
   int a[]={4,2,6,8,1,10,3,7,9,5};
   size_t asize=sizeof(a)/sizeof(int);
   llist *head = create_ll(a, asize, 1); // create stack
   print_ll(head,"LINKED LIST - STACK");
   head=reverse_ll(head,NULL);
   print_ll(head,"REVERSED STACK");
   head = create_ll(a, asize, 0); // create queue
   print_ll(head,"LINKED LIST AS QUEUE");
   head=reverse_ll(head,NULL);
   print_ll(head,"REVERSED QUEUE");
}
