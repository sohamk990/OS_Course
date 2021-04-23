// Program Number: 2
// Student Name: SOHAM KOLHE 
// Register Number: IMT2018073
// Date: 25 FEBRUARY 2021

// Description: infinite loop in background
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
    //Infinite loop in background
    int i=0;
    while(1)
    {
        i=~i;
    }

    // Identify all process related information
    // ls -l /proc 
    return 0;
}