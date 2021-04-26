#include <stdio.h>
#include <unistd.h>
#include <sys/sem.h>
#include <sys/ipc.h>


union semun
{
    int val;
    struct semid_ds *buf;
    unsigned short int* array;
};

// struct sembuf
// {
//     //semaphore number 0 means first
//     short sem_num;

//     //semaphore operation lock/unlock
//     short sem_op;

//     //operation flag: 0,SEM_UNDO,IPS_NOWAIT
//     short sem_flg;
// };

int main()
{
    key_t key;
    key = ftok(".",'a');
    struct sembuf buf ={0,-1,0};
    int semid = semget( key, 1, IPC_CREAT | 0644 );

    printf("Before\n");
    semop(semid,&buf,1);
    
    printf("Inside\n");    
    printf("Enter to unlock\n");
    getchar();

    //unlocking
    buf.sem_op=1;
    semop(semid,&buf,1);
    return 0;
}