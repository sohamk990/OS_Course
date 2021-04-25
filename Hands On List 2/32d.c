#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<stdio.h>

union semun
{
	int val;
	struct semid_ds *buf;
	unsigned short int * array;
};

int main()
{
    key_t key;
    key = ftok(".", 'a');
    int semid,result;
    
    semid = semget(key, 1, 0);
    printf("Got semaphore with id: %d\n", semid);

    result = semctl(semid, 0, IPC_RMID);
    if( result == 0)
    {
        printf("Successfully removed the semaphore!\n");
    }
    
    return 0; 
}
