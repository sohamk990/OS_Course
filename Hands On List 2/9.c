#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    int pid;
    pid = fork();

    //parent
    if(pid != 0)
    {        
        sleep(1);
        // so that signal(SIGINT, SIG_IGN) gets executed before this 
        printf("Sending the first SIGINT signal which wiil be ignored \n");
        // a signal is sent to terminate the child process
        kill(pid, SIGINT);

        // sleeps for 2 seconds to observe the bhavior of the child process
        sleep(2);
        printf("Sending the second SIGINT signal which will be executed default \n"); 
        // sends another signal to terminate the child process
        kill(pid, SIGINT);

    }
    else
    {
        int i = 0;
        // this gets executed before the parent process and will ignore first SIGINT
        signal(SIGINT, SIG_IGN);
        
        while(1)
        {
            sleep(1);
            // to display the current status of the child process
            printf("The child process is alive!\n");
            i++;
            if(i&1)
            {
                // restoring the signal's behavior to default, this occurs before the second signal is sent from the parent process
                signal(SIGINT, SIG_DFL); 
            }
        }
    }
    return 0;
}