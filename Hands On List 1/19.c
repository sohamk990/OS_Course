// Program Number: 19
// Student Name: SOHAM KOLHE 
// Register Number: IMT2018073
// Date: 25 FEBRUARY 2021

// Description: time taken to execute getpid()

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>


static __inline__ unsigned long long rdtsc(void)
{
  unsigned hi, lo;
  __asm__ __volatile__ ("rdtsc" : "=a"(lo), "=d"(hi));
  return ( (unsigned long long)lo)|( ((unsigned long long)hi)<<32 );
}

int main(void)
{
	pid_t pid;
  	unsigned long long a,b;

	a = rdtsc();
	pid = getpid();
	b = rdtsc();

	printf("The PID of this process is : %d \n",pid);
	printf("Time taken to find PID is : %llu timer cycles\n",b-a);	

	return 0;
}