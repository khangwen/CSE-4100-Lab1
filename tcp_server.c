// Find Header Files and Put them here
// For example, #include <stdio.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

// Please Add your remark at the ends of lines, line by line

int serv_sock, clnt_sock;    // default declaration of welcoming socket and client socket
char message[BUF_SIZE];      // default declaration of message to be sent
int str_len, i;              // default declaration of size of message
struct sockaddr_in serv_adr; // create structure for server address
struct sockaddr_in clnt_adr; // create structure for client address
socklen_t clnt_adr_sz;       // default declaration for client address size

serv_sock = socket(PF_INET, SOCK_STREAM, 0);                               // create TCP socket with domain IPv4 and default protocol
memset(&serv_adr, 0, sizeof(serv_adr));                                    // fill memory with server address info
serv_adr.sin_family = AF_INET;                                             // fill domain info
serv_adr.sin_addr.s_addr = htonl(INADDR_ANY);                              // fill server address
serv_adr.sin_port = htons(atoi(argv[1]));                                  // fill server port
bind(serv_sock, (struct sockaddr *)&serv_adr, sizeof(serv_adr));           // bind welcoming socket to server address
listen(serv_sock, 5);                                                      // server put in waiting state until connection with client established
clnt_adr_sz = sizeof(clnt_adr);                                            // client address assigned value
clnt_sock = accept(serv_sock, (struct sockaddr *)&clnt_adr, &clnt_adr_sz); // data packet is accepted

str_len = read(clnt_sock, message, BUF_SIZE) // message read and stored in str_len
    write(clnt_sock, message, str_len);      // send message back to client

close(clnt_sock); // close client socket
close(serv_sock); // close welcoming socket
