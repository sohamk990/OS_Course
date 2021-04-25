/*program to perform Record locking.using write lock*/
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<stdio.h>
#include<string.h>


typedef struct ticket{
	char train_name[80];
	int ticketno;
} ticket;


union semun {
    int val;
    struct semid_ds *buf;
    unsigned short int *array;
};

int generateRecord(void){
    int fd;
    int choice;
    fd=open("record",O_CREAT|O_RDWR,0744);
    choice=1;
    ticket db;

    strcpy(db.train_name,"Abcd");
    db.ticketno = 10;
    write(fd,&db,sizeof(ticket));

    strcpy(db.train_name,"Efgh");
    db.ticketno = 20;
    write(fd,&db,sizeof(ticket));

    strcpy(db.train_name,"Ijkl");
    db.ticketno = 30;
    write(fd,&db,sizeof(ticket));        

    close(fd);
    printf("finished record generation\n");
    return 0;
}


int main(void){

    // generateRecord();
	int fd;
	int recordnum=0;
	
    ticket tk;
	printf("Accessing record 2 \n");
	recordnum = 2;

    fd=open("record",O_RDWR);
	lseek(fd,(recordnum-1)*sizeof(ticket),SEEK_SET);//to seek a position after the start of a file

	read(fd,&tk,sizeof(ticket));
	printf("Ticket number :  %d\n",tk.ticketno);

	int key, semid;
	key=ftok(".",'a');
	
    //locking
	struct sembuf buf={0,-1,0};
	semid=semget(key,1,0);
	semop(semid,&buf,1);

    //critical section
	printf("Entered the critical section\n Modyfing ticket value\n");
	tk.ticketno = tk.ticketno + 1;
	lseek(fd,-sizeof(ticket),SEEK_CUR);// to go to start of the record which should be locked 
	write(fd,&tk,sizeof(ticket));
	printf("train num : %s\n",tk.train_name);
	printf("ticket no: %d\n",tk.ticketno);
	
    getchar();

    //unlocking
    buf.sem_op=1;
	semop(semid,&buf,1);

	close(fd);
 	return 0;
}