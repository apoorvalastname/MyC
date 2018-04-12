#include <stdio.h>
#include <stdlib.h>
#include "helper.h"

typedef struct _node
{
   int val;
   struct _node *left;
   struct _node *right;
}node;

typedef struct _queue
{
   node *nodeptr;
   struct _queue *next;
}queue;

queue *head_queue,*tail,*head_stack;
void init_queue()
{
   head_queue=tail=head_stack=NULL;
}

#define print_tree_traversal(x,y) \
{ \
   init_queue(); \
   print_subtitle (y); \
   print_##x(root); \
   printf("\n"); \
}

#define pop_from_push_to(ds_1,ds_2) \
   for (subtree=pop_queue(&head_##ds_2);subtree;subtree=pop_queue(&head_##ds_2)) \
   {\
      printf (" %d ",subtree->val);\
      push_##ds_1(subtree->left);\
      push_##ds_1(subtree->right);\
   }

node *create_node(int val)
{
   node *newnode = calloc(1,sizeof(node));
   newnode->val=val;
   newnode->left=NULL;
   newnode->right=NULL;
   return (newnode);
}
void insert_node(node **root, node *newnode)
{
   if (!*root) 
      *root=newnode;
   else if (newnode->val < (*root)->val)
      insert_node(&((*root)->left), newnode);
   else
      insert_node(&((*root)->right), newnode);
}
node *create_bst(int *a, size_t sizea)
{
   node *root=NULL;
   size_t i;
   for(i=0;i<sizea;i++)
   {
      node *newnode = create_node(a[i]);
      insert_node(&root, newnode);      
   }
   return root;
}

void print_dfs(node *root)
{
   if(root)
      printf(" %d ",root->val);
   if(root->left)
      print_dfs(root->left);
   if(root->right)
      print_dfs(root->right);
}

queue *create_queue(node *nodeptr)
{
   queue *newqnode = calloc(1,sizeof(queue));
   newqnode->nodeptr=nodeptr;
   newqnode->next=NULL;
   return newqnode;
}
void push_queue(node *nodeptr)
{  
   queue *newqnode = create_queue(nodeptr);
   if (!head_queue)
      head_queue=tail=newqnode;
   else
   {
      tail->next=newqnode;
      tail=newqnode;
   }
}
void push_stack(node *nodeptr)
{
   queue *newstack = create_queue(nodeptr);
   if(!head_stack)
      head_stack=newstack;
   else
   {
      newstack->next=head_stack;
      head_stack=newstack;
   }
}
node *pop_queue(queue **pheadptr)
{
   if (!pheadptr || !*pheadptr)
      return NULL;
   queue *headptr=*pheadptr;
   node *popped = headptr->nodeptr;
   *pheadptr=headptr->next;
   free(headptr);
   return (popped);
}
void print_bfs(node *root)
{
   printf(" %d ",root->val);
   if (root->left)
      push_queue(root->left);
   if (root->right)
      push_queue(root->right);
   node *child=pop_queue(&head_queue);
   if (child)
      print_bfs(child);
}
void print_spiral(node *root)
{
   if (root)
      push_stack(root);
   node *subtree;
   pop_from_push_to(queue,stack);
   pop_from_push_to(stack,queue);
   if(!head_stack && !head_queue)
      return;
   print_spiral(NULL);
}
void main()
{
   int a[]={4,2,6,8,1,10,3,7,9,5};
   size_t sizea = sizeof(a)/sizeof(int);
   print_title(" BINARY SEARCH ",a,sizea);
   node *root = create_bst(a, sizea);
   print_tree_traversal(dfs," Depth First Search ");
   print_tree_traversal(bfs," Breadth First Search ");
   print_tree_traversal(spiral," Spiral or Zigzag Traversal ");
}
