#include <stdio.h>
#include <stdbool.h>
#include "helper.h"

bool swap(int *x, int *y)
{
   int tmp=*x;
   *x=*y;
   *y=tmp;
   return true;
}

void bubble(int *a, size_t asize)
{
   int i,j;
   bool swaped=false;
   print_title("BUBBLE SORT",a,asize);
   for (j=asize-1;j>0;j--)
   {
      for(swaped=false,i=0;i<j;i++)
      {
         if(a[i]>a[i+1])
         {
            swaped=swap(&a[i],&a[i+1]);
            print_a(a,asize);
         }
      }
      if (!swaped)
         break;
   }
}

int findsmallest(int *a,size_t asize)
{
   int i,smallest=0;
   for(i=1;i<asize;i++)
      if(a[i]<a[smallest])
         smallest=i;
   return smallest;
}

void selection(int *a, size_t asize)
{
   int i, smallest;
   print_title("SELECTION SORT",a,asize);
   for (i=0;i<asize;i++)
   {
      smallest=findsmallest(&a[i],asize-i);
      if (smallest)
      {
         swap(&a[i],&a[smallest+i]);
         print_a(a,asize);
      }
   }
}

void insert(int *a, size_t lower, size_t upper)
{
   int i,tmp=a[upper];
   for (i=upper;i>lower;i--)
   {
      a[i]=a[i-1];
   }
   a[lower]=tmp;
}
void insertion(int *a, size_t asize)
{
   int i,j;
   print_title("INSERTION SORT",a,asize);
   for(i=1;i<asize;i++)
   {
      for (j=0;j<i;j++)
      {
         if (a[i]<a[j])
         {
            insert(a,j,i);
            print_a(a,asize);
         }
      }
   }
}

void merge_bkup_lists(int *a, size_t min, size_t mid, size_t max)
{
   size_t i,j;
   for (i=min,j=mid+1;i<=mid || j<=max;i++)
   {
      if(a[j]<a[i])
      {
         insert(a,i,j);
         j++;
      }
   }
}

void copyarrays(int *acopy, int *a, size_t min, size_t max)
{
   size_t i,j;
   for (i=0,j=min;i<max-min+1;i++,j++)
   {
      acopy[i]=a[j];
   }
}
void merge_lists(int *a, size_t min, size_t mid, size_t max)
{
   size_t i,j,s;
   int acopy[max+1-min];
   copyarrays(acopy,a,min,max);

   for(s=min,i=0,j=mid+1-min;i<=mid-min && j<=max-min;s++)
   {
      if(acopy[j]<acopy[i])
      {
         a[s]=acopy[j];
         j++;
      }
      else
      {
         a[s]=acopy[i];
         i++;
      }
   }
   for (;i<=mid-min;i++,s++)
      a[s]=acopy[i];
   for (;j<=max-min;j++,s++)
      a[s]=acopy[j];
}
void recursive_merge(int *a, size_t min, size_t max)
{
   int mid;
   if (min>=max)
      return;
   mid = (min+max)/2;
   recursive_merge(a,min,mid);
   recursive_merge(a,mid+1,max);
   merge_lists(a,min,mid,max);
   print_a(a,max+1);
}
void merge(int *a, size_t asize)
{
   int i;
   print_title("MERGE SORT",a,asize);
   recursive_merge(a,0,asize-1);
   print_a(a,asize);
}
void reorder_heap(int *heap, size_t n)
{
   if(!n) return;
   size_t p=(n-1)/2;
   if (heap[n]<heap[p])
   {
      swap(&heap[n],&heap[p]);
      reorder_heap(heap,p);
   }
}
void reheap(int *heap, size_t i, size_t n)
{
   int tmp=(i+1)*2-1;
   if(tmp< n)
   {
      if (((tmp+1) < n) && (heap[tmp+1]<heap[tmp]))
         tmp++;
      if (heap[tmp]<heap[i])
      {
         swap(&heap[tmp], &heap[i]);
         reheap(heap, tmp, n);
      }
   }
}
int pop(int *heap, size_t n)
{
   if(!n)
      return 0;
   int popped = heap[0];
   heap[0]=heap[n-1]; // here n is the size of the heap
   printf(" Before reheap : ");
   print_a(heap,n-1);
   reheap(heap,0,n-1);  // here n-1 is the size of the heap, since the previous last element is moved to the 0th position
   printf(" After reheap : ");
   print_a(heap,n-1);
   return (popped);
}
void heapify(int *a, int *heap, size_t asize)
{
   int i;
   for(i=0;i<asize;i++)
   {
      heap[i]=a[i];
      reorder_heap(heap,i);
      print_a(heap,i+1);
   } 
}
void heap(int *a, size_t asize)
{
   int heap[asize];
   print_title("HEAP SORT",a,asize);
   heapify(a,heap,asize);
   printf(" Pop function on heap returns : %d\n",pop(heap,asize));
}
void main()
{
   int a[]={4,2,6,8,1,10,3,7,9,5};
   int b[]={4,2,6,8,1,10,3,7,9,5};
   int c[]={4,2,6,8,1,10,3,7,9,5};
   int d[]={4,2,6,8,1,10,3,7,9,5};
   int e[]={4,2,6,8,1,10,3,7,9,5};
   size_t asize = sizeof(a)/sizeof(int);
   print_a(a,asize);
   bubble(a,asize);
   selection(b,asize);
   insertion(c,asize);
   merge(d,asize);
   heap(e,asize);
}
