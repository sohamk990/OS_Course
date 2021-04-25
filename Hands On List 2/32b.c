#include<sys/types.h>
#include<sys/sem.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    int key =  ftok(".",'a');
    int semaphore_id = semget(key, 1, 0);
    struct sembuf buf={0,-1,0}; 

    semop(semaphore_id, &buf, 1); 
    printf("Entering critical section...\n");

    int shmem_id = shmget(key,1024,IPC_CREAT|0744);
    printf("Shared memory ID = %d\n", shmem_id);

    char *ptr = shmat(shmem_id, NULL, 0); 
	printf("Enter data to write in shared memory\n");
    scanf( "%s",ptr); 

    printf("Enter to unlock.\n");
    getchar();
    getchar();

    buf.sem_op = 1;	
    semop(semaphore_id,&buf,1);

    return 0;
}