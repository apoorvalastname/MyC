#include <stdio.h>
#include <inttypes.h>
#include <sys/time.h>
#include <time.h>

void main()
{
   long ms;  // milliseconds
   time_t s; // seconds
   struct timespec clocktime;
   clock_gettime(CLOCK_REALTIME,&clocktime);
   s=clocktime.tv_sec;
   ms = clocktime.tv_nsec/1.0e6;
   while (ms>999)
   {
      s++;
      ms-=999;
   }   
   struct tm *timenow=localtime(&s);
   printf("\n Apoorva -- time : %s %ld:%03ld\n",asctime(timenow),s,ms);
   printf("\n Apoorva -- _TIMESTAMP_ : %s\n",__TIMESTAMP__);
   printf("\n Apoorva -- __TIME__ : %s\n",__TIME__);
}
