// Program Number:  
// Student Name: SOHAM KOLHE 
// Register Number: IMT2018073
// Date: 19 MAY 2021

// Description:


// Writer
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    // opening the file for reading    
    int fd;
    char buffer[100];     
    mkfifo("myfifo", 0666);
    fd = open("myfifo", O_WRONLY | O_TRUNC);

    while(1)
    {
        fgets(buffer, 100, stdin);
        write(fd, buffer, strlen(buffer)+1);        
    }
    close(fd);
    return 0;
}
