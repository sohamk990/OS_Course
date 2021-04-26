#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <unistd.h>
#include <fcntl.h>

union semun
{
    int val;
    // struct semid_ds *buf;
    unsigned short int* array;
};

int main()
{
    key_t key, key1, key2, key3;
    int semid,size,number_0f_semaphore,result,id,fd;
    union semun arg;
    char c;
    
    //creating semaphore
    key = ftok(".",'a');
    printf("Key: %d \n",key);
    number_0f_semaphore = 3;
    semid = semget( key, number_0f_semaphore , IPC_CREAT | 0666);

    printf("Making all the Semaphore Binary. \n");
    arg.val = 1;
    semctl(semid, 0, SETVAL, arg);    
    semctl(semid, 1, SETVAL, arg);
    semctl(semid, 2, SETVAL, arg);

    printf("Enter the train number u want to lock>>: ");
    scanf("%d",&id);
    printf("Train id: %d \n",id);
    getchar();
    
    if(id==1)
    {
        printf("Semaphore Id: %d\n",semid);
        printf("Before Enter the critical Section. \n");

        struct sembuf buffer = {0, -1, SEM_UNDO};
        buffer.sem_num = 0;
        buffer.sem_op = -1;
        semop(semid, &buffer, 1);

        printf("Inside critical Section. \n");
        fd = open("tmp/ticket1.txt", O_WRONLY | O_CREAT | O_TRUNC, 0777);
        char num[] = "9211";
	    write(fd,num,sizeof(num));
        
        printf("Waiting for unlocking... Press any key to unlock \n");
        getchar();

        buffer.sem_num = 0;
        buffer.sem_op = 1;
        semop(semid, &buffer, 1);
    }
    else if(id==2)
    {
        printf("Semaphore Id: %d\n",semid);
        printf("Before Enter the critical Section. \n");
        struct sembuf buffer = {0, -1, };
        buffer.sem_num = 1;
        buffer.sem_op = -1;
        semop(semid, &buffer, 1);
        
        printf("Inside critical Section. \n");
        fd = open("tmp/ticket2.txt", O_WRONLY | O_CREAT | O_TRUNC, 0777);
        char num[] = "9211";
	    write(fd,num,sizeof(num));
        
        printf("Waiting for unlocking... Press any key to unlock \n");
        getchar();

        buffer.sem_num = 1;
        buffer.sem_op = 1;
        semop(semid, &buffer, 1);
    }
    else if(id==3)
    {
        printf("Semaphore Id: %d\n",semid);
        printf("Before Enter the critical Section. \n");
        struct sembuf buffer = {0, -1, SEM_UNDO};
        buffer.sem_num = 2;
        buffer.sem_op = -1;
        semop(semid, &buffer, 1);
        
        printf("Inside critical Section. \n");
        fd = open("tmp/ticket3.txt", O_WRONLY | O_CREAT | O_TRUNC, 0777);
        char num[] = "9211";
	    write(fd,num,sizeof(num));
        
        printf("Waiting for unlocking... Press any key to unlock \n");
        getchar();

        buffer.sem_num = 2;
        buffer.sem_op = 1;
        semop(semid, &buffer, 1);
    }

    // printf("Removing the semaphore!\n");
    // result = semctl(semid, 0, IPC_RMID);
    // if( result == 0)
    // {
    //     printf("Semaphore removed succesfully. \n");
    // }
    // else
    // {
    //     printf("Semaphore can't be removed. \n");
    // }

    return 0;
}