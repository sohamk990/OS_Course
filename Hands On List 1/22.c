// Program Number: 22
// Student Name: SOHAM KOLHE 
// Register Number: IMT2018073
// Date: 25 FEBRUARY 2021

// Description: write to file using fork parent and child

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(void)
{
	int fd;
	pid_t fork_pid;
	char data[] = " This is a test string \n" ;

	fd = open("trial.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);	
	fork_pid = fork();

	// child Process
	if(fork_pid==0)
	{
		sleep(3);
		if(fd >= 0)
		{
			ssize_t write_ret;
			write_ret = write(fd, data, sizeof(data));
		}
		else
		{
			printf("Error creating file");
		}
	}
	//parent process
	else
	{
		sleep(3);
		if(fd >= 0)
		{
			ssize_t write_ret;
			write_ret = write(fd, data, sizeof(data));
		}
		else
		{
			printf("Error creating file");
		}
	}
	
}