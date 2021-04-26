#include <stdio.h>
#include <sys/sem.h>
#include <sys/types.h>
#include <sys/sem.h>

int main()
{
    printf("Enter the train number u want to lock>>: 1\n");
    printf("semid = 2 \n");
    printf("Before Enter the critical Section. \n");
    printf("Inside critical Section. \n");
    printf("Waiting for unlocking... Press any key to unlock \n");
    getchar();    
    return 0;
}