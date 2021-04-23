// Program Number: 10
// Student Name: SOHAM KOLHE 
// Register Number: IMT2018073
// Date: 25 FEBRUARY 2021

// Description: open file write 10 bytes then seek 10 bytes then write 10 bytes

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
    fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
    
    write(fd, "0123456789", 10);
    lseek(fd, 10, SEEK_CUR);
    write(fd, "9876543210", 10);

    printf("lseek at %ld\n", lseek(fd,0, SEEK_CUR));
    
    close(fd);

    // od -c tmp/tmp.txt

    return 0;
}