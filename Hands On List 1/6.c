// Program Number: 6
// Student Name: SOHAM KOLHE 
// Register Number: IMT2018073
// Date: 25 FEBRUARY 2021

// Description: read and write using system call 

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(void)
{
    int fd,i=0;
    char buf[500]={};
    char c[2];
    
    fd = 0;
    while( read(fd,c,1) )
    {
        write(fd,c,1);
    }
    perror("");
    return 0;
}   