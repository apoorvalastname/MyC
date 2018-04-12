#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef enum {N=0, A,B,C } endingenum;
typedef struct _eachnode
{
   int count;
   int totalcount;
   bool processed;   
}eachnode;
typedef struct mystruct
{
   bool getcb_received;
   endingenum getcb_node;
   eachnode a;
   eachnode b;
}mystruct;

static mystruct myX;

void eachnode_set(eachnode *node, int n)
{
   node->count = n;
}
void print_mystruct(eachnode node)
{
   printf("\n myX.getcb_node : %d ",myX.getcb_node);
   printf("\n count : %d ",node.count);
   printf("\n myX.a.totalcount : %d ",node.totalcount);
   printf("\n");
}
void main()
{
   int node; 
   int num;
   printf("\nEnter the node to be processed(1/2) and count : ");
   scanf("%d %d",&node,&num);
   myX.getcb_node=num+5;
   if (node < \
      10)
      eachnode_set(&myX.a, num);
   else
      eachnode_set(&myX.b, num);
   printf("\n A");
   print_mystruct(myX.a);
   printf("\n B");
   print_mystruct(myX.b);
}
