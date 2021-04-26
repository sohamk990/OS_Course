#include <stdio.h> 
#include <sys/ipc.h> 
#include <sys/msg.h> 
#include <stdlib.h>

struct message_buffer
{
    // message type, must be > 0
    long message_type;

    //message data
    char message_text[100];
};

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

    printf("Key for the message queue: %d\n", key);
    printf("Id of the message queue: %d\n", msgid);
    
    result = msgctl(msgid, IPC_RMID,NULL);
    if(result == -1)
    {
        printf("Message Queu can't be removed");
    }

    return 0;   
}