#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/msg.h>

int main()
{
    key_t key; 
    int msgid,result; 
  
    // ftok to generate unique key
    key = ftok(".", 'a'); 

    // msgget creates a message queue and returns identifier
    msgid = msgget(key, 0666 | IPC_CREAT); 
    if(msgid == -1)
    {
        printf("Message Queue can't be created");
        return 0;
    }    
    
    system("ipcs -q");

    // removing this message queue
    result = msgctl(msgid, IPC_RMID, NULL);
    if(result == -1)
    {
        printf("Message Queu can't be removed");
    }

    system("ipcs -q");
    return 0;
}