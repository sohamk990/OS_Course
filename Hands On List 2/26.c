#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
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
    int msgid; 
  
    // ftok to generate unique key
    key = ftok(".", 'a'); 

    // msgget creates a message queue and returns identifier
    msgid = msgget(key, 0666 | IPC_CREAT); 
    if(msgid == -1)
    {
        printf("Message Queue can't be created");
        return 0;
    }

    struct message_buffer msg = {1,"This is my message."};
    msgsnd(msgid, &msg, sizeof(msg), 0);


    system("echo CHECKING MESSAGE QUEUE ...");
    system("ipcs -q");
    
    return 0;

}