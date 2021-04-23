// Program Number:  1
// Student Name: SOHAM KOLHE 
// Register Number: IMT2018073
// Date: 25 FEBRUARY 2021

// Description: create hard soft and fifo link

#include <time.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/sysmacros.h>

int main(int argc, char *argv[])
{
    //softlink
    symlink("1.c","1_softlink");
    perror("Softlink Status");

    //hardlink
    link("1.c","1_hardlink");
    perror("Harlink Status");
    
    //fifo
    mkfifo("fifo",0666);
    perror("Fifo Status");

    return 0;
}