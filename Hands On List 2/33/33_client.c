// Program Number:  
// Student Name: SOHAM KOLHE 
// Register Number: IMT2018073
// Date: 19 MAY 2021

// Description:

#include <sys/types.h>          
#include <sys/socket.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <errno.h>
#include <string.h>
#include <netinet/in.h>


int main()
{
    char buffer[1024] = {0};

    printf("This is the client program!\n");
    int sd = socket(AF_INET, SOCK_STREAM, 0); // RAW Socket Descriptor
    
    if(sd == -1)
    {
        printf("Failed to initialize a socket!\n");
        exit(-1);
    }
    struct in_addr inadr;
    struct sockaddr_in serv, cli;
    
    serv.sin_family = AF_INET;
    inadr.s_addr = INADDR_ANY;
    serv.sin_addr = (inadr);
    serv.sin_port = htons(5000); // setting the port no. as 5000
    printf("The port is: %d\n", serv.sin_port);

    int val = connect(sd, (void*)&serv, sizeof(serv));
    if(val == -1)
    {
        printf("Failed to connect!\n");
        exit(-1);
    }
    printf("Client is connected to the server...\n");

    char* hello_message = "Hello From Client!\n";
    if(send(sd, hello_message, strlen(hello_message), 0) <= 0)
        printf("Send failed!\n");
    else 
        printf("Hello message sent from client!\n");

    if(recv(sd, buffer, 1024, 0) <= 0)
        printf("Read Failed!\n");
    printf("%s", buffer);
    
    return 0;

}
