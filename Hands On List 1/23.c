// Program Number: 23
// Student Name: SOHAM KOLHE 
// Register Number: IMT2018073
// Date: 25 FEBRUARY 2021

// Description: create zombie state of running program

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h> 

int main(void)
{ 
    pid_t fork_pid = fork();
  
    // If fork pid is zero then it's child process
    if(fork_pid == 0)
    {        
        printf("Exiting Child Process \n");
        exit(0);
    }     
    else
    {
        printf("Putting Parent process to sleep for 5 seconds \n");
        sleep(5); 
        printf("Parent process finished execution \n");
    }
    return 0; 
} 