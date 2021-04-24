#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

int main()
{
    int pipefd[2];
    int pid,result;

    char *str = "Hello! How are you ?";
    size_t message_size = strlen(str);
    char* buffer = (char*) calloc (message_size, sizeof(char));

    printf("Creating a pipe!\n");
    result=pipe(pipefd);
    if(result == 0)
    {
        printf("Pipe created successfully!\n");
    }    
    pid = fork();
    
    if(pid != 0)
    {        
        printf("Sending the message from the parent process!\n");
        result = write(pipefd[1], str, message_size);
        if(result>0)
        {
            printf("Data sent successfully from parent \n");
        }

        while(1)
        {
            sleep(1);
        };
    }
    else
    {
        // sleeping for two seconds so data can be sent to the child process
        sleep(2);
        printf("Reading the message from the child process!\n");
        result = read(pipefd[0],buffer,message_size);
        if(result>0)
        {
            printf("Data read successfully from parent \n");
            printf("Data is : %s \n", buffer);
        }
        kill(getppid(), SIGKILL);
    }
    return 0;
}