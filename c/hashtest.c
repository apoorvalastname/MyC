#include <stdio.h>

#define val(x) #x
#define value(x) val(x) 
typedef enum { ONE = 1, TWO, THREE }nums;
void main()
{
   nums mynum=ONE;
   printf("\nApoorva -- hash test : x : %s : %s \n\n",val(mynum),value(mynum));
}
