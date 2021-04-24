#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    int pipefd[2], result, pid, method;

    printf(" Choose method \n 1) dup \n 2) dup2 \n 3) fcnlt \n Select: ");
    scanf("%d",&method);
    // printf("%d",method);

    if(method!=1 && method!=2 && method!=3)
    {
        printf("Wrong Choice!!");
        return 0;
    }

    result = pipe(pipefd);
    if( result == 0)
    {
        printf("Pipe created successfully!\n");
    }

    pid = fork();    
    if(pid != 0)
    {
        // closing the read end of the pipe
        close(pipefd[0]);
        //closing normal stdout
        close(1);

        if(method == 1)
        {
            dup(pipefd[1]);
        }
        else if(method == 2)
        {
            dup2(pipefd[1],1);
        }
        else if(method == 3)
        {
            fcntl(pipefd[1],F_DUPFD,1);
        }
        
        char *argv[] = {"/bin/ls", "-l",0};
        execve("/bin/ls", argv, NULL);        
        printf("execve failed!\n");
    }
    else
    {
        // closing the write end of the file
        close(pipefd[1]);
        //closing normal stdin
        close(0);
        
        if(method == 1)
        {
            dup(pipefd[0]);
        }
        else if(method == 2)
        {
            dup2(pipefd[0],0);
        }
        else if(method == 3)
        {
            fcntl(pipefd[0],F_DUPFD,0);
        }

        char* argv[] = {"/usr/bin/wc", 0};
        execve("/usr/bin/wc", argv, NULL);        
        printf("execve failed!\n");
    }

    return 0;
}