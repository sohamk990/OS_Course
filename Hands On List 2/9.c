#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    int pid;
    pid = fork();

    if(pid != 0)
    {
        // we are in the parent process
        
        sleep(1);
        // so that signal(SIGINT, SIG_IGN) gets executed before this 
        printf("Sending the first SIGINT signal!\n");

        // a signal is sent to terminate the child process
        kill(pid, SIGINT);

        // sleeps for 2 seconds to observe the bhavior of the child process
        sleep(2);
        printf("Sending the seconds SIGINT signal!\n"); 
        
        // sends another signal to terminate the child process
        kill(pid, SIGINT);

    }
    else
    {
        int i = 0;
        signal(SIGINT, SIG_IGN); // this gets executed before the parent process
        
        while(1)
        {
            // this is just to ensure that the terminal does not get cluttered with a lot of print statements
            sleep(1);
            // to display the current status of the child process
            printf("The child process is alive!\n");
            i = i + 1;
            if(i == 1)
            {
                // restoring the signal's behavior to default, this occurs before the second signal is sent from the parent process
                signal(SIGINT, SIG_DFL); 
            }
        }
    }
    return 0;
}