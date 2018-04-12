#include <stdio.h>
#define str(x) printf("\n Trying out # macro operator : \n\t "#x" %d\n",x)
   
#define NUMBERS {1,2,3,4}
#define ADD(x) x[0]+x[1]+x[2]+x[3]
#define newadd(x)  { int sum=0,y=sizeof(x)/sizeof(int); while(y) sum+=x[--y]; printf("\n sum of "#x"-- newadd -- %d\n",sum); }
#define newreturnadd(x) ( { int sum=0,y=sizeof(x)/sizeof(int); while(y) sum+=x[--y]; sum; })

#define createarray(elements...) {0,##elements}
#define ARRAY(...) {__VA_ARGS__}
//#define yetanotheradd(...) ({int z[]={__VA_ARGS__};sizeof(z)/sizeof(int);})
#define yetanotheradd(...) (int a[]={__VA_ARGS__}/sizeof(int))

void main()
{
   int array[]=NUMBERS;
   str(ADD(array));

   int newarray[]=createarray(10,20,30);
   str(ADD(newarray));

   int arraytest[]=ARRAY(100,200,300,400);
   str(ADD(arraytest));

   int a1[]={1,2,3,4,5,6,7,8,9};
   int x = sizeof(a1)/sizeof(int);
   printf ("\n Printing the number of elements in an array : %d\n\n",x);
   newadd(a1);
   newadd(array);
   newadd(newarray);
   newadd(arraytest);
   printf ("\n Printing the return value of the addition function : %d \n\n",newreturnadd(a1));
   
   printf("\nlength of array : %d\n\n",yetanotheradd(1,2,3,4,5,6));

}



// NOTES : https://gcc.gnu.org/onlinedocs/cpp/Stringizing.html
// If you want to stringize the result of expansion of a macro argument, you have to use two levels of macros.
//
// #define xstr(s) str(s)
// #define str(s) #s
// #define foo 4
// str (foo)
//      -> "foo"
// xstr (foo)
//      -> xstr (4)
//      -> str (4)
//      -> "4"



