// Program Number: 21
// Student Name: SOHAM KOLHE 
// Register Number: IMT2018073
// Date: 25 FEBRUARY 2021

// Description: fork and print child and parent process

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h> 

int main(void)
{
	int pid,forkpid,ppid;
	pid = fork();

	// pid=0 then it's child process
	if(pid==0)
	{
		sleep(2);
		printf("-----------------------------------\n");
		printf(" This is child process \n");
		printf(" child --> pid = %d \n parent --> pid = %d \n",getpid(), getppid());
	}
	else
	{
		sleep(2);
		printf("-----------------------------------\n");
		printf(" This is Parent process \n");
		printf(" parent --> pid = %d \n", getpid()); 
	}	
	return 0;
}	