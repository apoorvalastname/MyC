// Write a function to return if two words are exactly "one edit" away, where an edit is:
//     Inserting one character anywhere in the word (including at the beginning and end)
//     Removing one character
//     Replacing exactly one character

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool count_diffs(char *str1, char *str2, bool isequal)
{  
   size_t i,j,count=0;
   size_t len1 = strlen(str1);
   size_t len2 = strlen(str2);
   for(i=0,j=0;i<len1 && j<len2;i++,j++)
   {
      if (str1[i]!=str2[j])
      {
         if (count)
            return (false);
         count++;
         if (!isequal)
            j--;
      }
   }
   return (true);
}
bool edit_away(char *str1, char *str2)
{
   size_t len1 = strlen(str1);
   size_t len2 = strlen(str2);
   bool isequal=false;
   char *bigstr=str1,*smallstr=str2;

   if (len1>len2) 
   {
      if (len1-len2 > 1)
         return (false);
   }
   else if (len2>len1)
   {
      if (len2-len1 > 1)
         return (false);
      bigstr=str2;
      smallstr=str1;
   }
   else
   {
      isequal=true;
   }

   return (count_diffs(bigstr, smallstr, isequal));
}

void main()
{
   char first[30];
   char second[30];
   printf("\nEnter two strings : \n");
   scanf("%s %s",&first,&second);
   printf("\n First and second strings : %s & %s are edit away : %d\n",first,second,edit_away(first,second));
}



