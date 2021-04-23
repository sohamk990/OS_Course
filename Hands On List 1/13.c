// Program Number: 13
// Student Name: SOHAM KOLHE 
// Register Number: IMT2018073
// Date: 25 FEBRUARY 2021

// Description: wait 10 seconds for input
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
    struct timeval time;
    int output,value;
    fd_set fd;

    FD_ZERO(&fd);
    FD_SET(0, &fd);

    time.tv_sec = 10;
    time.tv_usec = 0;

    output = select(FD_SETSIZE, &fd, NULL, NULL, &time);
    if (output == -1)
    {
        perror("Error");
    }
    else if (output == 0)
    {
        printf("No data avaible within 10s.\n");        
    }
    else
    {
        printf("Data available\n");
        scanf("%d", &value);
    }
    return 0;
}