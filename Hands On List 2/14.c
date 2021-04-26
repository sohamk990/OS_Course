#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int pipefd[2];
    int result;
    char *str = "Hello! How are you ?";
    size_t message_size = strlen(str);
    char* buffer = (char*) calloc (message_size, sizeof(char));
    
    printf(" Creating a pipe! \n");
    result=pipe(pipefd);
    if(result == 0)
    {
        printf(" Pipe created successfully! \n");
    }
    else
    {
        printf(" Pipe cannot be created successfully! \n");
        return 0;
    }
    
    printf(" Writing to the pipe!\n");
    result = write(pipefd[1], str, message_size);
    if(result > 0)
    {
        printf(" Written to the pipe successfully! \n");
    }

    printf(" Reading from the pipe! \n");
    result = read(pipefd[0], buffer, message_size);
    if(result > 0)
    {
        printf(" Read from the pipe successfully! \n");
        printf(" The data read is: %s \n", buffer);
    }
    
    return 0;
}