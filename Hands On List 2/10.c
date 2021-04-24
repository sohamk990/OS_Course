#include <stdio.h>
#include <unistd.h>
#include <signal.h> 
#include <stdlib.h>

void general_purpose_signal_catcher(int signal_name)
{
    printf("The custom signal_name handler got invoked!\n");
    if(signal_name == SIGSEGV)
    {
        printf("Caught SIGSEGV!\n");
    }
    else if(signal_name == SIGINT)
    {
        printf("Caught SIGINT!\n");
    }
    else if(signal_name == SIGFPE)
    {
        printf("Caught SIGFPE!\n");
    }
    else
    {
        printf("Did not catch either of the three signals as defined above.\n");
    }

    return;
}

int main()
{
    int pid;
    pid = fork();

    // we are in the parent process
    if(pid != 0)
    {
        sleep(2);
        printf("Sending SIGSEGV signal_name to child!\n");
        kill(pid, SIGSEGV);
        sleep(1);
        printf("Sending SIGINT signal_name to child!\n");
        kill(pid, SIGINT);
        sleep(1);
        printf("Sending SIGFPE signal_name to child!\n");
        kill(pid, SIGFPE);
        sleep(1);
        kill(pid, SIGKILL);
    }
    else
    {
        struct sigaction* myaction = (struct sigaction*)calloc(1, sizeof(struct sigaction));
        myaction->sa_handler = general_purpose_signal_catcher;
        myaction->sa_flags = 0;

        int success;
        success = sigaction(SIGSEGV, myaction, NULL);
        success += sigaction(SIGINT, myaction, NULL);
        success += sigaction(SIGFPE, myaction, NULL);

        if(success == 0)
        {
            printf("All signal_name actions changed successfully!\n");
        }

        while(1)
        {

        }
    }
    return 0;
}