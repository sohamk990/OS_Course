// Program Number: 15
// Student Name: SOHAM KOLHE 
// Register Number: IMT2018073
// Date: 25 FEBRUARY 2021

// Description: Display enviornment variables

#include <time.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/sysmacros.h>

int main(int argc, char *argv[], char * envp[]) 
{ 
    int i; 
    for (i = 0; envp[i] != NULL; i++) 
    {
        printf(" %s \n", envp[i]);
    }
    return 0; 
} 