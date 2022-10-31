// Find Header Files and Put them here
// For example, #include <stdio.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

// Please Add your remark at the ends of lines, line by line

int sock;                    // default declaration of client socket
char message[BUF_SIZE];      // default declaration of message to be sent
int str_len;                 // default declaration of size of message
struct sockaddr_in serv_adr; // create structure for server address

sock = socket(PF_INET, SOCK_STREAM, 0); // create TCP socket with domain IPv4 and default protocol

memset(&serv_adr, 0, sizeof(serv_adr));        // fill memory with server address info
serv_adr.sin_family = AF_INET;                 // fill domain info
serv_adr.sin_addr.s_addr = inet_addr(argv[1]); // fill server address
serv_adr.sin_port = htons(atoi(argv[2]));      // fill server port

connect(sock, (struct sockaddr *)&serv_adr, sizeof(serv_adr)) // client socket connects to server

    write(sock, message, strlen(message));   // client writes message to server
str_len = read(sock, message, BUF_SIZE - 1); // client reads message sent back from server and stores into str_len

close(sock); // client socket closed
