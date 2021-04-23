// Program Number: 4
// Student Name: SOHAM KOLHE 
// Register Number: IMT2018073
// Date: 25 FEBRUARY 2021

// Description: open exsisting file in read write mode using O_EXCL
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
    int fd;

    // if file does not have in directory  
    // then file tmp.txt is created.
    fd = open(argv[1], O_RDWR | O_EXCL | O_CREAT,0666);
    
    //read only
    //open("tmp.txt",O_RDONLY);

    //read write
    // open("tmp.txt",O_RDWR);

    //write only
    // open("tmp.txt",O_WRONLY);    
      
    
    if (fd == -1)
    {
        perror("");
    }
    else
    {
        printf("File descriptor: %d \n", fd);
        // print program detail "Success or failure" 
        perror("");
    }

    
    return 0;
}