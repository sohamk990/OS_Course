// Program Number:  
// Student Name: SOHAM KOLHE 
// Register Number: IMT2018073
// Date: 19 MAY 2021

// Description:

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/time.h>

void SIGSEGV_Handler(int sig)
{
    printf("Caught SIGSEGV Signal! \n");
    return;
}

void SIGINT_Handler(int sig)
{
    printf("Caught SIGINT Signal! \n");
    return;
}

void SIGFPE_Handler(int sig)
{
    printf("Caught SIGFPE Signal! \n");
    return;
}

void SIGALRM_Handler(int sig)
{
    printf("Caught SIGALRM Signal! \n");
    return;
}

void SIGVTALRM_Handler(int sig)
{
    printf("Caught SIGVTALRM Signal! \n");
    return;
}

void SIGPROF_Handler(int sig)
{
    printf("Caught SIGPROF Signal! \n");
    return;
}

int main() 
{ 
    int pid;
    pid = fork();

    // the child process goes into an infinite loop
    if(pid==0)
    {
        // if the child process receives this signal, it executes the custom signal handler
        signal(SIGSEGV, SIGSEGV_Handler);
        signal(SIGINT, SIGINT_Handler);
        signal(SIGFPE, SIGFPE_Handler);
        signal(SIGALRM, SIGALRM_Handler);
        signal(SIGVTALRM, SIGVTALRM_Handler);
        signal(SIGPROF, SIGPROF_Handler);
        
        // send SIGALRM signal to calling process
        alarm(1);
        sleep(2);

        struct itimerval* timer = (struct itimerval*)calloc(1, sizeof(struct itimerval));

        // setting a single-shot timer of 1 second
        struct timeval *interval = (struct timeval*)calloc(1, sizeof(struct timeval));
        interval->tv_sec = 0;
        interval->tv_usec = 0; 
        
        struct timeval *value = (struct timeval*)calloc(1, sizeof(struct timeval));
        value->tv_sec = 1;
        value->tv_usec = 0;
        timer->it_interval = *interval;
        timer->it_value = *value;

        setitimer(ITIMER_REAL, timer, NULL);
        sleep(2);
        setitimer(ITIMER_VIRTUAL, timer, NULL);
        sleep(2);
        setitimer(ITIMER_PROF, timer, NULL);
        sleep(2);

        while(1)
        {

        };
    }
    else
    {
        // sleeps for 1 second
        sleep(1);
        kill(pid, SIGSEGV);
        
        // sleeps for 1 second
        sleep(1); 
        kill(pid, SIGINT);
        
        // sleeps for 1 second
        sleep(1);
        kill(pid, SIGFPE);
        
        sleep(10);
        kill(pid, SIGKILL);
    }
}