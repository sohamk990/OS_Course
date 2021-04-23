// Program Number: 14
// Student Name: SOHAM KOLHE 
// Register Number: IMT2018073
// Date: 25 FEBRUARY 2021

// Description: print file type

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
    struct stat sb;
    int fd;
    fd = open(argv[1],O_RDONLY);
    fstat(fd,&sb);

    switch (sb.st_mode & S_IFMT)
    {
        case S_IFBLK:
            printf("Block device \n");
            break;

        case S_IFCHR:
            printf("Character device \n");
            break;

        case S_IFDIR:
            printf("Directory\n");
            break;

        case S_IFIFO:
            printf("FIFO pipe \n");
            break;

        case S_IFLNK:
            printf("Symlink \n");
            break;

        case S_IFREG:
            printf("Regular file \n");
            break;

        case S_IFSOCK:
            printf("Socket \n");
            break;

        default:
            printf("Unknown \n");
            break;
    }

    close(fd);
    return 0;
}