// Program Number: 11
// Student Name: SOHAM KOLHE 
// Register Number: IMT2018073
// Date: 25 FEBRUARY 2021

// Description: duplicate file using differnt methods then print the descriptors

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
    fd = open(argv[1],O_RDWR | O_CREAT | O_TRUNC, 0666);
        
    int dupl = dup(fd);
    int dupl2 = dup2(fd, 15);
    int dup_fcntl = fcntl(fd, F_DUPFD);

    printf(" Original File descriptor : %d \n Duplicate File descriptor : %d \n Duplicate 2 File descriptor : %d \n Duplicate fcntl File descriptor  : %d \n", fd, dupl, dupl2, dup_fcntl );
    
    lseek(fd, 0, SEEK_SET);
    write(fd, "Original \n", 10); 
    write(dupl, "Duplicate \n", 11);
    write(dupl2, "Duplicate 2 \n", 13);
    write(dup_fcntl, "Duplicate fcntl \n",17);


    close(fd);
    close(dupl);
    close(dupl2);
    close(dup_fcntl);
    return 0;
}