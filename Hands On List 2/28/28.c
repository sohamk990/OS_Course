#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    key_t key; 
    int msgid,val; 
    struct msqid_ds info;
    struct ipc_perm info_;
    
    // ftok to generate unique key
    key = ftok(".", 'a'); 

    // msgget creates a message queue and returns identifier
    msgid = msgget(key, 0666 | IPC_CREAT); 
    if(msgid == -1)
    {
        printf("Message Queue can't be created");
        return 0;
    }

    //retriving the message details
    val = msgctl(msgid, IPC_STAT, &info);
    if(val != 0)
    {
        printf("Message can't be created properly");
        return 0;
    }

    info_ = info.msg_perm;
    printf("Existing access permissions: %d\n", info_.mode);

    info_.mode ++;
    info.msg_perm = info_;
    
    //Setting the new permission
    val = msgctl(msgid, IPC_SET, &info);
    if(val != 0)
    {
        printf("Message can't be created properly");
        return 0;
    }

    //retriving the message details
    val = msgctl(msgid, IPC_STAT, &info);
    if(val != 0)
    {
        printf("Message can't be created properly");
        return 0;
    }
    info_ = info.msg_perm;
    printf("Changed access permissions: %d\n", info_.mode);

    return 0;

}