#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

int main()
{
    key_t key;
    int size,shmid,result;

    key = ftok(".",'a');
    size = 1024;
    shmid = shmget(key, size, IPC_CREAT | 0644);
    printf("ID for the shared memory is: %d\n", shmid);

    char *data = (char*) shmat(shmid,(void*)0,0);
    printf("Reading the data before writing anything! \n");
    scanf(" %[^\n]",data);
    printf("Data is: %s \n",data);
        
    printf("Attached with a readonly pointer!\n");
    char* pointer_read_only = (char*)shmat(shmid, (void*)0, SHM_RDONLY);

    // printf("Attempting to overwrite...\n");
    // scanf(" %[^\n]",pointer_read_only);
    // printf("Data is: %s \n",pointer_read_only);   
    // printf("I have commented out the next two lines where we attempt to overwrite using a read_only pointer, which eventually results in a seg fault!\n");
    
    printf("Reading after an overwrite attempt!\n");
    printf("Data is: %s \n",data);
    
    printf("Detaching the memory segments...\n");
    result = shmdt(data);
    if(result != 0)
        printf("Detach failed!\n");
    
    result = shmdt(pointer_read_only);    
    if(result != 0)
        printf("Detach failed!\n");
    
    printf("Removing the shared memory...\n");    
    result = shmctl(shmid,IPC_RMID,NULL);

    if(result==0)
    {
        printf("Shared memory removed sucesfully \n");
    }
    else
    {
        printf("Shared memory can't be removed \n");
    }
    return 0;
}