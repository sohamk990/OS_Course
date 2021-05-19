// Program Number:  
// Student Name: SOHAM KOLHE 
// Register Number: IMT2018073
// Date: 19 MAY 2021

// Description:

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    int pid;
    pid = fork();

    //Parent
    if(pid != 0)
    {
        while(1)
        {
            sleep(1);
            printf("Parent process is alive!\n");
        }
    }
    else
    {
        int killed = 0;
        while(killed==0)
        {
            printf("Child process is alive!\n");
            sleep(1);

            if(kill(getppid(), SIGKILL) == 0)
            {
                killed = 1;
                {
                    sleep(1);
                    printf("This is now an orphan process!\n");
                }
            }
        }
    }
}