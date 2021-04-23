// Program Number: 5
// Student Name: SOHAM KOLHE 
// Register Number: IMT2018073
// Date: 25 FEBRUARY 2021

// Description: create five files in infinite loop

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(void)
{
    char *names[5] = {"tmp/f1.txt","tmp/f2.txt","tmp/f3.txt","tmp/f4.txt","tmp/f5.txt"};

    while(1)
    {
        for(int i=0;i<5;i++)
        {
            creat(names[i],0666);
        }
    }
    
    return 0;
}