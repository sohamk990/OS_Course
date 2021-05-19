// Program Number:  
// Student Name: SOHAM KOLHE 
// Register Number: IMT2018073
// Date: 19 MAY 2021

// Description:

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/time.h>

int main()
{
    int pipe_1[2],result,pid, pipe_2[2];;

    result = pipe(pipe_1);
    if(result == 0)
    {
        printf("First pipe created successfully!\n");
    }
    else
    {
        printf("First pipe cannot be created successfully!\n");
        exit(0);
    }

    
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

    pid = fork();    
    if(pid != 0)
    {
        //closing reading end of the pipe
        close(pipe_1[0]);

        //closing normal stdout
        close(1);

        dup(pipe_1[1]);
        char* argv[] = {"/bin/ls", "-l", 0};
        execve("/bin/ls", argv, NULL);
    }
    else
    {
        //closing writting end of the pipe
        close(pipe_1[1]);

        //closing normal stdin
        close(0);

        dup(pipe_1[0]);        

        int pid_2 = fork();
        if(pid_2 != 0)
        {
            //closing reading end of the pipe
            close(pipe_2[0]);
            
            //closing normal stdout
            close(1);
            
            dup(pipe_2[1]);
            char* argv_2[] = {"/bin/grep", "^d", 0};
            execve("/bin/grep", argv_2, NULL);
        }
        else
        {
            //closing writting end of the pipe
            close(pipe_2[1]);
            
            //closing normal stdin
            close(0);
            
            dup(pipe_2[0]);
            char* argv_2[] = {"/usr/bin/wc", 0};
            execve("/usr/bin/wc", argv_2, NULL);
            printf("execve failed!\n");
        }
    }
}