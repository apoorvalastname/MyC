#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <pthread.h>

// pthread_create(&pid_of_child,NULL,child_func,(void *)list_of_args_to_child_thread)
// pthread_join (pid_of_child, NULL); //join is in the main thread to join the child thread after it exits, waits for the child to exit
// pthread_detach (pthread_self()); // detach is in the child function, to detach itself from the main thread
// pthread_exit (NULL); //exit itself

#define MAX_THREADS 25
#define MAX_BUFF 500

typedef struct _sharedmemory{
   char buff[MAX_BUFF];
   size_t len;
   pthread_mutex_t mymutex;
}shared_memory;
typedef struct _thread_data
{
   int thread_number;
   bool isreadthread;
}thread_data;
typedef struct _mythread
{
   pthread_t thread_id;
   thread_data *thread_data;
}mythread;

shared_memory sharedmemory; // global shared memory of the threads

void clear_buffer()
{
   memset(sharedmemory.buff,0,MAX_BUFF);
   sharedmemory.len=0;
}
void write_buffer(int num)
{
   sharedmemory.len+=snprintf(sharedmemory.buff+sharedmemory.len,MAX_BUFF,"HELLO%d ",num);
   printf("\n Writing to buffer : Thread%d\n",num);
   //sleep(1);
}
void read_buffer(int num)
{
   printf("\n Reading from buffer : Thread%d\n",num);
   printf("\nBUFFER CONTENTS : %s\n",sharedmemory.buff);
   //sleep(1);
}
void *child_thread(void *data)
{
   thread_data *mydata = (thread_data *)data;
   printf("\n New thread : thread%d, my pid: %u",mydata->thread_number,pthread_self());
   if (mydata->isreadthread)
      read_buffer(mydata->thread_number);
   else
      write_buffer(mydata->thread_number);
   printf("\n Thread : thread%d Exiting \n",mydata->thread_number);
   free(mydata);
   pthread_exit(NULL);
   return NULL;
}

void main()
{
   mythread newthread[MAX_THREADS];
   clear_buffer();
   int i;
   for (i=0;i<MAX_THREADS;i++)
   {
      thread_data *new_data=calloc(1,sizeof(thread_data));
      new_data->thread_number=i;
      new_data->isreadthread=i%2;
      newthread[i].thread_data=new_data;
      pthread_create(&newthread[i].thread_id,NULL,child_thread,(void *)((newthread[i].thread_data)));
      printf("\n Am the main thread : I created child thread %d : with thread_id : %u\n",newthread[i].thread_data->thread_number,newthread[i].thread_id); 
   }
   for (i=0;i<MAX_THREADS;i++)
      pthread_join(newthread[i].thread_id,NULL);
   
   printf("\nAll my child threads exited... AM EXITING TOO!!\n");
   printf("\nOh btw.. in case you want to know... the sharedmemory contents are : \n\t%s\n",sharedmemory.buff);
}

