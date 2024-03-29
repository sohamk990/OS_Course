// Program Number:  
// Student Name: SOHAM KOLHE 
// Register Number: IMT2018073
// Date: 19 MAY 2021

// Description:

#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main()
{
    int p;
    printf("Enter the pid of the process: ");
    scanf("%d",&p);
    printf("Sending SIGSTOP signal to the process!\n");

    if(kill(p, SIGSTOP) == 0)
    {
        printf("Successfully sent the signal!\n");
    }
    else
    {
        printf("Failed to send the signal!\n");
    }
    return 0;
}