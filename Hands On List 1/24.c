// Program Number: 24
// Student Name: SOHAM KOLHE 
// Register Number: IMT2018073
// Date: 25 FEBRUARY 2021

// Description: create orphan state

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>


int main() 
{     
    int fork_pid = fork(); 
  
    if (fork_pid == 0)
    { 
        printf("Child process put to sleep 5 seconds \n");
        sleep(10); 
        printf("Parent Process terminated before the child prcoess exits\n"); 
    }
    else
    {
        printf("Parent Process finished Execution\n"); 
    }
    return 0; 
} 