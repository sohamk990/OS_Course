// Program Number: 12
// Student Name: SOHAM KOLHE 
// Register Number: IMT2018073
// Date: 25 FEBRUARY 2021

// Description: print opening mode of file

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
    int fd,mode;
    
    fd = open(argv[1],O_WRONLY);
    mode = fcntl(fd,F_GETFL);
    printf("The mode of file is %x \n", mode );

    fd = open(argv[1],O_RDONLY );
    mode = fcntl(fd,F_GETFL);
    printf("The mode of file is %x \n", mode );

    fd = open(argv[1],O_RDWR );
    mode = fcntl(fd,F_GETFL);
    printf("The mode of file is %x \n", mode );

    close(fd);
    
    return 0;
}
