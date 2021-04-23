// Program Number: 28
// Student Name: SOHAM KOLHE 
// Register Number: IMT2018073
// Date: 25 FEBRUARY 2021

// Description: get maximum and minimum time priority

#include <stdio.h>
#include <sched.h>

int main(void)
{

    int max_val =  sched_get_priority_max(SCHED_FIFO);
    int min_val = sched_get_priority_min(SCHED_FIFO);

    printf(" Maximum real time priority is: %d \n",max_val);
    printf(" Minimum real time priority is: %d \n",min_val);

    return 0;
}
