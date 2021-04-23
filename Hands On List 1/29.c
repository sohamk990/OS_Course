// Program Number: 29
// Student Name: SOHAM KOLHE 
// Register Number: IMT2018073
// Date: 25 FEBRUARY 2021

// Description: get scheduling policy then modify it

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sched.h>

char* schedule(int val)
{
    switch(val)
    {
        case -1:
            return "You don't have permission";
        case 0:
            return "NORMAL";
        case 1:
            return "FIFO";
        case 2:
            return "RR";
        case 3:
            return "BATCH";
        case 5:
            return "IDLE";
        case 6:
            return "DEADLINE";
    }
}

int main(void)
{
    int pid,pol;
    struct sched_param par;

    pid = getpid();
    sched_getparam(pid,&par);
    pol = sched_getscheduler(pid);    
    printf("PID: %d\n",pid);
    printf("Current scheduling policy is %s\n", schedule(pol) );

    printf("Changing scheduling policy to FIFO\n");    
    par.sched_priority = SCHED_FIFO;
    sched_setscheduler(pid,SCHED_FIFO, &par);
    pol = sched_getscheduler(pid);
    printf("Current scheduling policy is %s\n", schedule(pol) );

    printf("Changing scheduling policy to RR\n");
    par.sched_priority = SCHED_RR;
    sched_setscheduler(pid,SCHED_RR, &par);
    pol = sched_getscheduler(pid);
    printf("Current scheduling policy is %s\n", schedule(pol) );

    return 0;
}