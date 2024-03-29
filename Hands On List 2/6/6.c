// Program Number:  
// Student Name: SOHAM KOLHE 
// Register Number: IMT2018073
// Date: 19 MAY 2021

// Description:


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *thread_1_function(void *vargp)
{
    sleep(1);
    printf("Thread 1 is executed! \n");
    sleep(1);
}

void *thread_2_function(void *vargp)
{
    sleep(1);
    printf("Thread 2 is executed! \n");
    sleep(1);
}

void *thread_3_function(void *vargp)
{
    sleep(1);
    printf("Thread 3 is executed! \n");
    sleep(1);
}

int main()
{
    int res;
    pthread_t thread_1,thread_2,thread_3;
    
    printf("This is Main thread! \n");

    //Creating thread 1
    res = pthread_create(&thread_1, NULL, thread_1_function, NULL);
    pthread_join(thread_1, NULL);

    //Creating thread 2
    res = pthread_create(&thread_2, NULL, thread_2_function, NULL);
    pthread_join(thread_2, NULL);
    
    //Creating thread 3
    res = pthread_create(&thread_3, NULL, thread_3_function, NULL);
    pthread_join(thread_3, NULL);
    
    printf("Back to the Main thread!\n");
    
    pthread_exit(NULL);
    return 0;
}

