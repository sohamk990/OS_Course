#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/time.h>

int main()
{
    int pipe_1[2],result,pid;

    result = pipe(pipe_1);
    if(result == 0)
    {
        printf("First pipe created successfully!\n");
    }
    else
    {
        printf("First pipe created unsuccessfully!\n");
        exit(0);
    }

    pid = fork();    
    if(pid != 0)
    {
        close(pipe_1[0]);
        dup2(pipe_1[1], 1);
        char* argv[] = {"/bin/ls", "-l", 0};
        execve("/bin/ls", argv, NULL);
    }
    else
    {
        close(pipe_1[1]);
        dup2(pipe_1[0], 0);

        int pipe_2[2];
        result = pipe(pipe_2);
        if(result == 0)
        {
            printf("Second pipe created successfully!\n");
        }
        else
        {
            printf("Second pipe created unsuccessfully!\n");
            exit(0);
        }

        int pid_2 = fork();
        if(pid_2 != 0)
        {
            close(pipe_2[0]);
            dup2(pipe_2[1], 1);
            char* argv_2[] = {"/bin/grep", "^d", 0};
            execve("/bin/grep", argv_2, NULL);
        }
        else
        {
            close(pipe_2[1]);
            dup2(pipe_2[0], 0);
            char* argv_2[] = {"/usr/bin/wc", 0};
            execve("/usr/bin/wc", argv_2, NULL);
            printf("execve failed!\n");
        }
    }
}