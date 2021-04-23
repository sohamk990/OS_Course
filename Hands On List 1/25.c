// Program Number: 25
// Student Name: SOHAM KOLHE 
// Register Number: IMT2018073
// Date: 25 FEBRUARY 2021

// Description: crate three child process wait for particular child

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{ 
    int pid, pid1, pid2; 
    pid = fork();
    
    if (pid == 0)
    { 
        printf("Child 1 PID = %d and Parent PID = %d\n", getpid(), getppid()); 
    }
    else
    { 
        pid1 = fork(); 
        if (pid1 == 0)
        {
            printf("Child 2 PID = %d and Parent PID = %d\n", getpid(), getppid()); 
        } 
        else
        { 
            pid2 = fork(); 
            if (pid2 == 0)
            { 
                printf("Child 3 PID = %d and Parent PID = %d\n", getpid(), getppid()); 
            } 
            else
            { 
                waitpid(pid2,NULL,WUNTRACED);
                printf("Main Parent PID %d\n", getpid()); 
            }
        }
    }  
    return 0; 
} 