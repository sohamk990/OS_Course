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
    int semid;

    // Creating tw0 semophores binary and counting
    semid = semget( key, 1, IPC_CREAT | 0666 );

    printf("Making the Semaphore Binary\n");
    arg.val = 1;
    semctl(semid, 0, SETVAL, arg);

    printf("Making the Semaphore Counting\n");
    arg.val = 2;
    semctl(semid, 0, SETVAL, arg);

    return 0;
}