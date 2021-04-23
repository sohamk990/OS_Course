// Program Number: 17b
// Student Name: SOHAM KOLHE 
// Register Number: IMT2018073
// Date: 25 FEBRUARY 2021

// Description: lock the database increase the value

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
    fd = open("tmp/ticket.txt", O_RDWR);
    struct flock mylock;

    mylock.l_type = F_WRLCK;    
    mylock.l_whence = SEEK_SET;
    mylock.l_start = 0;
    mylock.l_len = 0;
    mylock.l_pid = getpid();

    int write_lock = fcntl(fd, F_SETLKW, &mylock);
    if(write_lock==0)
    {
        printf("Write Lock performed\n");
    }
    else
    {
        printf("Couldn't implement a write lock\n");
    }
    
    char ticket[10];
    int read_ret = read(fd, ticket, 6);

    int fp = lseek(fd, 0, SEEK_SET);
    int ticket_int = atoi(ticket);
    ticket_int = ticket_int + 1;

    char ticket_buf[10];
    sprintf(ticket_buf, "%d", ticket_int);
    int num = write(fd, ticket_buf, 6);
    
    mylock.l_type = F_UNLCK;
    int write_unlock = fcntl(fd, F_SETLKW, &mylock);    
    if(write_unlock==0)
    {
        printf("Write Unlock performed\n");
    }
    else
    {
        printf("Couldn't implement a write Unlock\n");
    }

    close(fd);
    return 0;
}