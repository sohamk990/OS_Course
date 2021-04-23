// Program Number: 30
// Student Name: SOHAM KOLHE 
// Register Number: IMT2018073
// Date: 25 FEBRUARY 2021

// Description: run script using daemon process at particular time

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include<time.h>

int main(int argc, char* argv[])
{
    struct tm* local; 
    
    pid_t pid = 0;
    pid_t sid = 0;
    FILE *fp= NULL;
    int i = 0;
    pid = fork();
    if (pid < 0)
    {
        printf("fork failed!\n");
        exit(1);
    }
    
    if (pid > 0)
    {
        printf("pid of child process %d \n", pid);
        exit(0); 
    }

    umask(0);
    sid = setsid();
    if(sid < 0)
    {
        exit(1);
    }
    
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    int ret = 1;
    char buf[80];
    struct tm *ts = (struct tm *)calloc(1, sizeof(struct tm));
    long int *t = (long int *)calloc(1, sizeof(long int));

    printf("This program executes a specific script after 5 seconds!\n");
    long int to_exec = time(t) + 5;
    ts = localtime(t);

    strftime(buf, sizeof(buf), "%a %Y-%m-%d %H:%M:%S %Z", ts);
    printf("Current time: %s\n", buf);
    while (1)
    {
        if (time(t) == to_exec)
        {
            ts = localtime(t);
            strftime(buf, sizeof(buf), "%a %Y-%m-%d %H:%M:%S %Z", ts);
            printf("Current time: %s\n", buf);
            ret = execve("1.sh",NULL, NULL);
        }
    }
    return (0);
}