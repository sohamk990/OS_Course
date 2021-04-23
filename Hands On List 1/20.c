// Program Number: 20
// Student Name: SOHAM KOLHE 
// Register Number: IMT2018073
// Date: 25 FEBRUARY 2021

// Description: find priortiy and change the priority

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/resource.h>

int main(void)
{
	int pr,pid;
	int which = PRIO_PROCESS;
	pid = getpid();
	printf("PID: %d \n",pid);
	pr = getpriority(which, pid);
	printf("The Priority of this process is : %i \n",pr);

	printf("Changeing priortiy to 5\n");
	pr = nice(5);	
	pr = getpriority(which,pid);
	printf("The Priority of this process is : %i \n",pr);
	return 0;
}