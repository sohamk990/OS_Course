/*program to perform Record locking.using write lock*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>


typedef struct ticket{
	char train_name[80];
	int ticketno;
} ticket;

union semun
{
    int val; 
    struct semid_ds *buf;
    unsigned short int *array; 
};

int main(void){

	int fd;
	int recordnum=2;
	ticket tk;
	printf("Accessing record 2\n");

	fd=open("record",O_RDWR);
	
    lseek(fd,(recordnum-1)*sizeof(ticket),SEEK_SET);//to seek a position after the start of a file
	read(fd,&tk,sizeof(ticket));
	printf("Ticket number :  %d\n",tk.ticketno);

	int key, semid;
	key=ftok(".",'b');
	
	struct sembuf buf[2]= {{0, -1, 0}, {0, -1, 0}};//-1+previous value
	semid=semget(key,2,0);
    semop(semid,&buf[0],1);
	
    
    printf("Entered the critical section\n");
	tk.ticketno++;
	lseek(fd,-sizeof(ticket),SEEK_CUR);// to go to start of the record which should be locked 
	write(fd,&tk,sizeof(ticket));
	printf("train num : %s\n",tk.train_name);
	printf("ticket no: %d\n",tk.ticketno);
	getchar();
    getchar();
	
    buf[0].sem_op=1;
	semop(semid,&buf[0],1);



    semop(semid,&buf[1],1);
    printf("Entered the critical section\n");
	tk.ticketno++;
	lseek(fd,-sizeof(ticket),SEEK_CUR);// to go to start of the record which should be locked 
	write(fd,&tk,sizeof(ticket));
	printf("train num : %s\n",tk.train_name);
	printf("ticket no: %d\n",tk.ticketno);
	getchar();
    getchar();
	
    buf[1].sem_op=1;
	semop(semid,&buf[0],1);

	close(fd);
 	return 0;
}