// Program Number: 7
// Student Name: SOHAM KOLHE 
// Register Number: IMT2018073
// Date: 25 FEBRUARY 2021

// Description: copy one file to another

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) 
{
    int fd1,fd2;
    char c[2];

    fd1=open(argv[1],O_RDONLY);

    fd2=open(argv[2],O_WRONLY | O_CREAT | O_TRUNC,0644);
    
    while(read(fd1,c,1)!=0)
    {
        write(fd2,c,1);
    }
    
    close(fd1);
    close(fd2);

    perror("");
    return 0;
}