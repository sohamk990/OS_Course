// Program Number: 8
// Student Name: SOHAM KOLHE 
// Register Number: IMT2018073
// Date: 25 FEBRUARY 2021

// Description: read file and print it
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    int fd,count=0;
    char c;
    fd = open(argv[1],O_RDONLY);
 
    while( read(fd,&c,1) != 0)
    {
        printf("%c",c);
        if(c=='\n')
        {
            count++;
        }
    }
    printf("\nNumber of Lines: %d \n",count);
    close(fd);
    return 0;
}