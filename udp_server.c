// Find Header Files and Put them here
// For example, #include <stdio.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

// Please Add your remark at the ends of lines, line by line

int serv_sock;                         // default declaration of socket
char message[BUF_SIZE];                // default declatatin of message to be passed
int str_len;                           // default declaration of size of message
socklen_t clnt_adr_sz;                 // default declaration of client address size
struct sockaddr_in serv_adr, clnt_adr; // create structures for internet addresses

serv_sock = socket(PF_INET, SOCK_DGRAM, 0); // create UDP socket of domain IPv4 and default protocol

memset(&serv_adr, 0, sizeof(serv_adr));       // fill memory with server address info
serv_adr.sin_family = AF_INET;                // fill domain info
serv_adr.sin_addr.s_addr = htonl(INADDR_ANY); // fill server address
serv_adr.sin_port = htons(atoi(argv[1]));     // fill server port

bind(serv_sock, (struct sockaddr *)&serv_adr, sizeof(serv_adr))                                  // address binded to server address
    clnt_adr_sz = sizeof(clnt_adr);                                                              // set client address size
str_len = recvfrom(serv_sock, message, BUF_SIZE, 0, (struct sockaddr *)&clnt_adr, &clnt_adr_sz); // wait for datagram and then assign value
sendto(serv_sock, message, str_len, 0, (struct sockaddr *)&clnt_adr, clnt_adr_sz);               // reply to client sent

close(serv_sock); // close server socket
