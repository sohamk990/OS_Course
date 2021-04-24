#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *myThread(void *thread_id) 
{
   sleep(1);
   long tid;
   tid = (long)thread_id;
   printf(" Thread ID is: %ld \n", tid);
   sleep(1);
   return NULL;
}

int main()
{
    //creating 3 threads
    pthread_t thread[4];
    int i;
    
    for(i=1;i<=3;i++)
    {
        printf("Creating thread ID: %ld \n", thread[i]);
        pthread_create(&thread[i], NULL, myThread, (void *) (thread[i]));
        pthread_join(thread[i], NULL);
    }
    pthread_exit(NULL);
    return 0;
}