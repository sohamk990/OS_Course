// Program Number: 17a
// Student Name: SOHAM KOLHE 
// Register Number: IMT2018073
// Date: 25 FEBRUARY 2021

// Description: open and store ticket

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
    fd = open("tmp/ticket.txt", O_WRONLY | O_CREAT | O_TRUNC, 0777);
    char num[] = "9211";
	write(fd,num,sizeof(num));
    close(fd);    
    return 0;
}