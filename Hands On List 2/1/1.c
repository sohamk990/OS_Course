// Program Number:  
// Student Name: SOHAM KOLHE 
// Register Number: IMT2018073
// Date: 19 MAY 2021

// Description:
 
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <signal.h>

void real()
{
  printf("SIGALRM raised!\n");
  exit(0);
}

void virtual()
{
  printf("SIGVTALRM raised!\n");
  exit(0);
}

void prof()
{
  printf("SIGPROF raised!\n");
  exit(0);
}

int main(void)
{
    signal(SIGALRM,real);
    signal(SIGVTALRM,virtual);
    signal(SIGPROF,prof);

    int timer_type,timer_time,res;
    struct timeval value,interval;
    struct itimerval val;

    interval.tv_sec = 0;
    interval.tv_usec = 0;

    printf("\n Timer time \n 1) 10 second, 2) 10 microsecond \n Select: ");
    scanf("%d", &timer_time);

    if(timer_time == 1)
    {
        value.tv_sec = 10;
        value.tv_usec = 0;
    } 
    else if(timer_time == 2)
    {
        value.tv_sec = 0;
        value.tv_usec = 10;       
    }
    else
    {
        printf(" Wrong Input!! \n");
        return 0;
    }

    val.it_value = value;
    val.it_interval = interval;
    
    printf("\n Timer type \n 1) Real \n 2) Virtual \n 3) Prof \n Select: ");
    scanf("%d",&timer_type);

    if(timer_type == 1)
    {
        res = setitimer(ITIMER_REAL,&val,NULL); 
    }
    else if(timer_type == 2)
    {
        res = setitimer(ITIMER_VIRTUAL,&val,NULL); 
    }
    else if(timer_type == 3)
    {
        res = setitimer(ITIMER_PROF,&val,NULL); 
    }
    else
    {
        printf(" Wrong Input!! \n");
        return 0;
    }

    if(res==-1)
    {
        printf(" Timer Failed!\n");
    }
    else
    {
        printf(" Timer set \n");
        while(1)
        {

        };
    }   
    
    return 0;
}