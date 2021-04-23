// Program Number: 3
// Student Name: SOHAM KOLHE 
// Register Number: IMT2018073
// Date: 25 FEBRUARY 2021

// Description: create file and print it's descriptor value

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
    int fd ;
    fd = creat("tmp.txt",0666);    

    if (fd == -1)
    {
        // print program detail "Success or failure" 
        perror("Error");
    }
    else
    {
        printf("file descriptor value: %d \n",fd);
        perror("");
    }
    
    close(fd);
    return 0;
}