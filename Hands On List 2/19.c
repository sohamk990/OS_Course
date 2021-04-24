#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int mode,result;
    system("mknod mypipe_mknod p");
    system("mkfifo mypipe_mkfifo");

    system("strace -c mknod ");
    system("strace -c mkfifo");
    
    system("echo Running the strace commands shows that  mkfifio is better than mknod as it takes lesser time to execute.");
    

    printf("Mode \n 1) mknod \n 2) mkfifo \n Select: ");
    scanf("%d",&mode);

    if(mode == 1)
    {
	    result = mknod("myfifo_mknod", S_IFIFO, 0);
        if(result != 0)
        {
            printf("Failed to execute mknod!\n");
        }
    }
    else if (mode == 2)
    {
	    result = mkfifo("myfifo_mkfifo", 0);
        if(result != 0)
        {
            printf("Failed to execute mknod!\n");
        }
    }
    else
    {
        printf(" Invalid Mode \n");
    }
    return 0;
}