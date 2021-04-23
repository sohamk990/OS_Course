// Program Number: 9
// Student Name: SOHAM KOLHE 
// Register Number: IMT2018073
// Date: 25 FEBRUARY 2021

// Description: printing file information as asked

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

    // printf("ID of containing device:  [%lx,%lx]\n", (long) major(sb.st_dev), (long) minor(sb.st_dev));    
    // printf("Mode:                     %lo (octal)\n",(unsigned long) sb.st_mode);

    printf("inode:                    %ld\n", (long) sb.st_ino);
    printf("number of hard links:     %ld\n", (long) sb.st_nlink);
    printf("UID:                      %ld\n",(long) sb.st_uid);
    printf("GID:                      %ld\n",(long) sb.st_gid);
    
    printf("File size:                %lld bytes\n",(long long) sb.st_size);
    printf("Block size:               %ld bytes\n",(long) sb.st_blksize);
    printf("Number of blocks:         %lld\n",(long long) sb.st_blocks);
    
    printf("Last file access:         %s", ctime(&sb.st_atime));
    printf("Last file modification:   %s", ctime(&sb.st_mtime));
    printf("Last file change:         %s", ctime(&sb.st_ctime));

    close(fd);
    perror("");
    return 0;
}