// Program Number:  
// Student Name: SOHAM KOLHE 
// Register Number: IMT2018073
// Date: 19 MAY 2021

// Description:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <unistd.h>

union semun
{
    int val;
    struct semid_ds *buf;
    unsigned short int* array;
};

int main()
{
    key_t key, key1, key2, key3;
    int semid,shmid1,shmid2,shmid3,size,number_0f_semaphore,ndata1,ndata2,ndata3,result;
    union semun arg;
    char c;

    //creating semaphore
    key = ftok(".",'a');
    number_0f_semaphore = 3;
    semid = semget( key, number_0f_semaphore , 0644| IPC_CREAT );
    
    printf("Making the Semaphore Binary\n");    
    arg.val = 1;
    semctl(semid, 0, SETVAL, arg);
    printf("Semaphore Id: %d\n",semid);

    printf("Making the Semaphore Counting\n");
    arg.val = 2;
    semctl(semid, 1, SETVAL, arg);
    semctl(semid, 2, SETVAL, arg);
    printf("Semaphore Id: %d\n",semid);

    
    //creating shared memory
    key1 = key + 1;
    key2 = key + 2; 
    key3 = key + 3;
    
    size = 1024;
    shmid1 = shmget(key1,size,0666|IPC_CREAT);
    shmid2 = shmget(key2,size,0666|IPC_CREAT);
    shmid3 = shmget(key3,size,0666|IPC_CREAT); 
    
    printf("ID for the shared memory is: %d\n", shmid1);
    printf("ID for the shared memory is: %d\n", shmid2);
    printf("ID for the shared memory is: %d\n", shmid3);
    
    char *data1  = (char*) shmat(shmid1,(void*)0,0); 
    char *data2  = (char*) shmat(shmid2,(void*)0,0); 
    char *data3  = (char*) shmat(shmid3,(void*)0,0); 


    // locking buffer
    struct sembuf buffer = {0, -1, 0};

    printf("Enter the data: \n");
    printf("Data1: ");
    scanf(" %[^\n]",data1);

    printf("Data2: ");
    scanf(" %[^\n]",data2);

    printf("Data3: ");
    scanf(" %[^\n]",data3);

    
    printf("Initial data: \n");
    printf("Data1: %s\n", data1);
    printf("Data2: %s\n", data2);
    printf("Data3: %s\n", data3);


    getchar();
    // writing the data1 (binary semaphore)
    buffer.sem_num = 0;
    buffer.sem_op = -1;
    semop(semid, &buffer, 1);    
    
    ndata1 = atoi(data1);
    ndata1++;
    sprintf(data1, "%d", ndata1);
    
    printf("Press to unlock Data 1\n");
    getchar();
    // putchar(c);
    
    buffer.sem_num = 0;
    buffer.sem_op = 1;
    semop(semid, &buffer, 1);
    
    
    // writing the data2 (counting semaphore)
    buffer.sem_num = 1;
    buffer.sem_op = -1; 
    semop(semid, &buffer, 1);


    ndata2 = atoi(data2);
    ndata2++;
    sprintf(data2, "%d", ndata2);
    printf("Press to unlock Data 2\n");
    getchar();
    // putchar(c);

    buffer.sem_num = 1;
    buffer.sem_op = 1;
    semop(semid, &buffer, 1);

    // writing the data3 (counting semaphore)
    buffer.sem_num = 2;
    buffer.sem_op = -1; 
    semop(semid, &buffer, 1);


    ndata3 = atoi(data3);
    ndata3++;
    sprintf(data3, "%d", ndata3);
    printf("Press to unlock Data 3\n");
    getchar();
    // putchar(c);

    buffer.sem_num = 1;
    buffer.sem_op = 1;
    semop(semid, &buffer, 1);

    printf("Final data: \n");
    printf("Data1: %s\n", data1);
    printf("Data2: %s\n", data2);
    printf("Data3: %s\n", data3);

    printf("Removing the semaphore!\n");
    result = semctl(semid, 0, IPC_RMID);
    if( result == 0)
    {
        printf("Semaphore removed succesfully. \n");
    }
    else
    {
        printf("Semaphore can't be removed. \n");
    }

    return 0;
}