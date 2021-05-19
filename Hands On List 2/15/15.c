// Program Number:  
// Student Name: SOHAM KOLHE 
// Register Number: IMT2018073
// Date: 19 MAY 2021

// Description:

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

int main()
{
    int pipefd[2];
    int pid,result;

    char *str = "Hello. How are you ?";
    size_t message_size = strlen(str);
    char* buffer = (char*) calloc (message_size, sizeof(char));

    printf("Creating a pipe \n");
    result=pipe(pipefd);
    if(result == 0)
    {
        printf("Pipe created successfully \n");
    }    
    else
    {
        printf(" Pipe cannot be created successfully! \n");
        return 0;
    }

    pid = fork();
    
    if(pid != 0)
    {        
        printf("Sending the message from the parent process to pipe \n");
        result = write(pipefd[1], str, message_size);
        if(result>0)
        {
            printf("Data sent successfully from parent \n");
        }
        sleep(3);
    }
    else
    {
        // sleeping for one seconds so data can be sent to the child process
        sleep(1);
        printf("Reading the message from the child process from pipe \n");
        result = read(pipefd[0],buffer,message_size);
        if(result>0)
        {
            printf("Data read successfully from parent \n");
            printf("Data is : %s \n", buffer);
        }
    }

    return 0;
}