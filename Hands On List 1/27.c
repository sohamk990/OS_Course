// Program Number: 27
// Student Name: SOHAM KOLHE 
// Register Number: IMT2018073
// Date: 25 FEBRUARY 2021

// Description: execute ls -Rl using diffrent system calls

#include <stdio.h>
#include <unistd.h>

int main(void)
{
    char *env[] = { NULL };
    char *const options[] = {"ls","-Rl",NULL};

    execl("/bin/ls","ls","-Rl",NULL);
    
    execlp("/bin/ls","ls", "-Rl" ,NULL);
    
    execle("/bin/ls","ls","-Rl",NULL, env);
    
    execv("/bin/ls",options);
    
    execvp("/bin/ls",options);
    
    return 0;
}