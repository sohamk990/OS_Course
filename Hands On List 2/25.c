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

    val = msgctl(msgid, IPC_STAT, &info);    
    if(val != 0)
    {
        printf("Message can't be created properly");
        return 0;
    }

    info_ = info.msg_perm;
    printf("Access permissions: %d\n", info_.mode);
    printf("User id: %d\n", info_.uid);
    printf("Group id: %d\n", info_.gid);
    

    printf("Time of last message sent: %ld\n", info.msg_stime);
    printf("Time of last message received: %ld\n", info.msg_rtime);
    printf("Time of last change in the queue: %ld\n", info.msg_ctime);
    
    
    printf("Current size of the queue: %ld\n", info.__msg_cbytes);
    printf("Allowed size of the queue: %ld\n", info.msg_qbytes);
    
    printf("Number of messages in the queue: %ld\n", info.msg_qnum);

    printf("PID of last message sent: %d\n", info.msg_lspid);
    printf("PID of last message received: %d\n", info.msg_lrpid);
    
    return 0;

}