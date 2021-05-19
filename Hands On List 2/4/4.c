// Program Number:  
// Student Name: SOHAM KOLHE 
// Register Number: IMT2018073
// Date: 19 MAY 2021

// Description:

#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

unsigned long long rdtsc ()  
{
    unsigned long long time;
    __asm__  __volatile__ ("rdtsc":"=A" (time));
    return time;
}

int main()
{
    unsigned long long start_time, end_time;
    int i;

    start_time = rdtsc();
    for(i = 0; i < 100; i++)
    {
        getppid();
    }
    end_time = rdtsc();

    printf ("Total time taken: %llu \n", end_time - start_time);
    return 0;
}