// Program Number: 26
// Student Name: SOHAM KOLHE 
// Register Number: IMT2018073
// Date: 25 FEBRUARY 2021

// Description: create executable program

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    if(argc >= 2)
    {
        char *file = *++argv;
        execv(file, ++argv);
    }
    else
    {
        printf("Wrong parameters\n");
    }
}