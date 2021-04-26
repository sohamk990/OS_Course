#include <stdio.h>
#include <sys/sem.h>


union semun
{
    int val;
    struct semid_ds *buf;
    unsigned short int* array;
};

int main()
{
    key_t key;
    key = ftok(".",'a');
    union semun arg;
    int semid,number_0f_semaphore=2;

    //creating 2 semaphores
    semid = semget( key, number_0f_semaphore , IPC_CREAT | 0644 );
    
    printf("Semaphore Id: %d\n",semid);
    
    printf("Making the Semaphore Binary\n");    
    arg.val = 1;
    semctl(semid, 0, SETVAL, arg);
    printf("Semaphore Id: %d\n",semid);

    printf("Making the Semaphore Counting\n");
    arg.val = 2;
    semctl(semid, 1, SETVAL, arg);
    printf("Semaphore Id: %d\n",semid);
    return 0;
}