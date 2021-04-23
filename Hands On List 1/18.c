// Program Number: 18
// Student Name: SOHAM KOLHE 
// Register Number: IMT2018073
// Date: 25 FEBRUARY 2021

// Description:  Implment read and write lock

#include <time.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/sysmacros.h>

typedef struct record
{
    int age;
    int height;
    int weight;
} person;

//creating a file with three record
int generateFile(void)
{
    person p1,p2,p3;

    p1.age = 30; 
    p1.height = 150;
    p1.weight = 50;
    
    p2.age = 25;
    p2.height = 161;
    p2.weight = 61;

    p3.age = 35;
    p3.height = 154;
    p3.weight = 54;

    int fd = open("record.imt", O_RDWR | O_CREAT, 0666);

    lseek(fd, 0, SEEK_SET);

    write(fd, &p1, sizeof(p1));
    write(fd, &p2, sizeof(p2));
    write(fd, &p3, sizeof(p3));
    
    close(fd);
}

int writeLock(int lock_record)
{
	int fd = open("record.imt", O_RDWR);

    struct flock mylock;

    mylock.l_type = F_WRLCK;
    mylock.l_whence = SEEK_SET;
    mylock.l_start = 0;    
    mylock.l_len = sizeof(person);
    mylock.l_pid = getpid();

	printf("Locking Record number %d\n", lock_record);
    mylock.l_start = (lock_record-1)*sizeof(person);
    int ret = fcntl(fd, F_SETLKW, &mylock);

	if(ret == -1)
    {
		printf("Failed to lock record for writing\n");
	}
	else
    {
		printf("Record Locked for writing. \nPress Enter key to unlock\n");
		getchar();
		mylock.l_type = F_UNLCK;
		ret = fcntl(fd, F_SETLK, &mylock);
	}
	return 0;
}

//readlock
int readLock(int lock_record)
{
	int fd = open("record.imt", O_RDWR, 0666);

    struct flock mylock;

    mylock.l_type = F_RDLCK;
    mylock.l_whence = SEEK_SET;
    mylock.l_start = (lock_record-1) * sizeof(person) ;
    mylock.l_len = sizeof(person);
    mylock.l_pid = getpid();

	printf("Locking Record number %d\n", lock_record);	

    int ret = fcntl(fd, F_SETLK, &mylock);

	if(ret == -1)
    {
		printf("Failed to lock record for reading\n");
	}
	else
    {
		printf("Record Locked for reading. \nPress Enter key to unlock\n");
		getchar();
		mylock.l_type = F_UNLCK;
		ret = fcntl(fd, F_SETLK, &mylock);
	}
	return 0;
}

//printing record
void print(int id)
{
    int fd = open("record.imt", O_RDWR | O_CREAT, 0666);
    lseek(fd, (id-1) * sizeof(person) , SEEK_SET);
    person *p = malloc(sizeof(person));    
    
    writeLock(id);
    readLock(id);
    read(fd,p,sizeof(person));
    printf(" Age: %d \n Height: %d \n Weight: %d \n",p->age,p->height,p->weight);

}
int main(int argc, char *argv[])
{    
    generateFile();

    print(1);
    print(2);
    print(3);

    // writeLock(1);
    // readLock(1);
    
    // writeLock(2);
    // readLock(2);

    return 0;
}