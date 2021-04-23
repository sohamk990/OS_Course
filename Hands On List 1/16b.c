// Program Number: 16b
// Student Name: SOHAM KOLHE 
// Register Number: IMT2018073
// Date: 25 FEBRUARY 2021

// Description: implement read lock

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
    fd = open(argv[1], O_RDONLY | O_CREAT ,0666);
    struct flock mylock;
    
    mylock.l_whence = SEEK_SET;
    mylock.l_len = 0;    
    mylock.l_start = 0;
    mylock.l_pid = getpid();

    mylock.l_type = F_RDLCK;
    int read_lock = fcntl(fd, F_SETLKW, &mylock);
    printf("Read Lock: %d\n",read_lock);
    
    mylock.l_type = F_UNLCK;
    int read_unlock = fcntl(fd, F_SETLKW, &mylock);
    printf("Read Unlock: %d\n", read_unlock);
    close(fd);

    perror("");
    return 0;
}