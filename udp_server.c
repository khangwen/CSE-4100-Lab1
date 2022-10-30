// Find Header Files and Put them here
// For example, #include <stdio.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

// Please Add your remark at the ends of lines, line by line

int serv_sock;          // to declare some thing
char message[BUF_SIZE]; //
int str_len;
socklen_t clnt_adr_sz;
struct sockaddr_in serv_adr, clnt_adr;

serv_sock = socket(PF_INET, SOCK_DGRAM, 0);

memset(&serv_adr, 0, sizeof(serv_adr));
serv_adr.sin_family = AF_INET;
serv_adr.sin_addr.s_addr = htonl(INADDR_ANY);
serv_adr.sin_port = htons(atoi(argv[1]));

bind(serv_sock, (struct sockaddr *)&serv_adr, sizeof(serv_adr))
    clnt_adr_sz = sizeof(clnt_adr);
str_len = recvfrom(serv_sock, message, BUF_SIZE, 0, (struct sockaddr *)&clnt_adr, &clnt_adr_sz);
sendto(serv_sock, message, str_len, 0, (struct sockaddr *)&clnt_adr, clnt_adr_sz);

close(serv_sock);
