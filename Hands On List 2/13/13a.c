// Program Number:  
// Student Name: SOHAM KOLHE 
// Register Number: IMT2018073
// Date: 19 MAY 2021

// Description:

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void catch_sigstop(int signum)
{
    if(signum == SIGSTOP)
    {
        printf("Caught SIGSTOP!\n");
        exit(0);
    }
    return ;
}

int main(void)
{
    printf("The process id is: %d\n", getpid());
    
    struct sigaction* myaction = (struct sigaction*)calloc(1, sizeof(struct sigaction));
    myaction->sa_handler = catch_sigstop;
    myaction->sa_flags = 0;
    
    if(sigaction(SIGSTOP, myaction, NULL) == 0)
    {
        printf("Behavior of SIGSTOP succecssfully altered!\n");
    }
    else
    {
        // this happens because SIGSTOP and SIGKILL's responses cannot be altered
        printf("sigaction system call failed!\n"); 
    }

    printf("Going into an infinite loop!\n");
    while(1)
    {

    }
    
    return 0;
}