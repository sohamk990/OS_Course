// Program Number:  
// Student Name: SOHAM KOLHE 
// Register Number: IMT2018073
// Date: 19 MAY 2021

// Description:

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

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
    int msgid,method,value,result; 
    struct message_buffer msg;

    // ftok to generate unique key
    key = ftok(".", 'a'); 

    // msgget creates a message queue and returns identifier
    msgid = msgget(key, 0666 | IPC_CREAT); 
    if(msgid == -1)
    {
        printf("Message Queue can't be created");
        return 0;
    }    

    printf(" Select Method \n 1) With 0 as flag \n 2) With IPC_NOWAIT as flag\n Choose: ");
    scanf("%d",&method);

    if (method == 1)
    {
        printf("This will wait for the message. \n");
        msgrcv(msgid, &msg, sizeof(struct message_buffer), 0, 0);
        printf("%s\n", msg.message_text);
        result = msgctl(msgid, IPC_RMID,NULL);
        if(result == -1)
        {
            printf("Message Queu can't be removed");
        }
    }
    else if(method==2)
    {
        printf(" This will not wait for the message. \n");
        msgrcv(msgid, &msg, sizeof(struct message_buffer), 0, IPC_NOWAIT);
        printf("%s\n", msg.message_text);
        result = msgctl(msgid, IPC_RMID,NULL);
        if(result == -1)
        {
            printf("Message Queu can't be removed");
        }
    }
    else
    {
        printf("Invalid Choice");
    }
    return 0;
}