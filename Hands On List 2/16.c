#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

int main()
{
    // we will be using two pipes to perform two way communication
    int pipefd1[2];
    int pipefd2[2];
    int pid,result;

    char *str1 = "Message from parent to child";
    char *str2 = "Message from child to parent";
    size_t message_size = strlen(str1);

    result=pipe(pipefd1);
    if(result == 0)
    {
        printf("Pipe 1 created successfully!\n");
    }
    else
    {
        printf(" Pipe 1 cannot be created successfully! \n");
        return 0;
    }

    result=pipe(pipefd2);
    if(result == 0)
    {
        printf("Pipe 2 created successfully!\n");
    }
    else
    {
        printf(" Pipe 2 cannot be created successfully! \n");
        return 0;
    }

    pid = fork();

    if(pid != 0)
    {
        result = write(pipefd1[1],str1,message_size);
        if(result>0)
        {
            printf("Data sent from parent!\n");
        }
        sleep(1);

        char* buffer = (char*)calloc(message_size, sizeof(char));
        result = read(pipefd2[0],buffer,message_size);
        if(result>0)
        {
            printf("Data read in parent: %s\n", buffer);
        }
        sleep(1);
    }
    else
    {   
        sleep(1);     
        char* buffer = (char*)calloc(message_size, sizeof(char));
        result = read(pipefd1[0],buffer,message_size);
        if(result>0)
        {   
            printf("Data read in child: %s\n", buffer);
        }

        result = write(pipefd2[1],str2,message_size);
        if(result>0)
        {
            printf("Data sent from child!\n");
        }
        sleep(1);
    }
    return 0;
}