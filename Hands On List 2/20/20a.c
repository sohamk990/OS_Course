// Program Number:  
// Student Name: SOHAM KOLHE 
// Register Number: IMT2018073
// Date: 19 MAY 2021

// Description:

// reader
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    // opening the file for reading
    int fd1;    
    char buffer[100];
    mkfifo("myfifo", 0666);
    fd1 = open("myfifo", O_RDONLY);

    while(1)
    {
        read(fd1, buffer, 100);
        printf("%s", buffer);
    }    
    close(fd1);
    return 0;
}