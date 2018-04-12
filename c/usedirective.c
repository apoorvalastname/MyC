#include<stdio.h>

#define defineints int a; int b;
#define definestruct(x)      \
typedef struct _inner##x     \
{                            \
  defineints                 \
}inner##x;                   \
typedef struct _##x##struct  \
{                            \
  defineints                 \
  inner##x pinner##x;        \
}x##struct;

definestruct(one);
definestruct(two);
definestruct(three);

#define initints(x,y) (x).a=(y)*10;(x).b=(y)*100;

#define allocstruct(x,c)          \
x##struct p##x##c;                \
initints(p##x##c,c*10)            \
initints(p##x##c.pinner##x,c*10-1)

#define printints(x) printf("\n "#x".a : %d \n "#x".b : %d \n",x.a,x.b);
#define printstruct(x,c) printints(p##x##c) printints(p##x##c.pinner##x)
#define ALLOC(x,c) allocstruct(x,c); printstruct(x,c);

#define ADD(...) int oneints[]={__VA_ARGS__};
void main()
{
   ALLOC(one,1);
   ALLOC(one,2);
   ALLOC(one,3);
   ALLOC(two,4);
   ALLOC(two,5);
   ALLOC(two,6);
   ALLOC(three,8);
   ALLOC(three,9);

}



