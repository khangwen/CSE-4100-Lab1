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

int sock;               // default declaration of socket
char message[BUF_SIZE]; // default declaration of message with size BUF_SIZE
int str_len;            // default declaration of size of message
socklen_t adr_sz;       // default declaration of client address size

struct sockaddr_in serv_adr, from_adr; // create structure for internet addresses

sock = socket(PF_INET, SOCK_DGRAM, 0); // create UDP socket for domain IPv4 with default protocol

memset(&serv_adr, 0, sizeof(serv_adr));        // fill memory with server address info
serv_adr.sin_family = AF_INET;                 // fill domain info
serv_adr.sin_addr.s_addr = inet_addr(argv[1]); // fill server address
serv_adr.sin_port = htons(atoi(argv[2]));      // fill server port

sendto(sock, message, strlen(message), 0, (struct sockaddr *)&serv_adr, sizeof(serv_adr)); // send datagram to server

adr_sz = sizeof(from_adr); // assign address size

str_len = recvfrom(sock, message, BUF_SIZE, 0, (struct sockaddr *)&from_adr, &adr_sz); // assign received message to str_len

close(sock); // close socket
