// Find Header Files and Put them here
// For example, #include <stdio.h>

// Please Add your remark at the ends of lines, line by line

int sock;
char message[BUF_SIZE];
int str_len;
socklen_t adr_sz;
		
struct sockaddr_in serv_adr, from_adr;

sock=socket(PF_INET, SOCK_DGRAM, 0);   
		
memset(&serv_adr, 0, sizeof(serv_adr));
serv_adr.sin_family=AF_INET;
serv_adr.sin_addr.s_addr=inet_addr(argv[1]);
serv_adr.sin_port=htons(atoi(argv[2]));
		
sendto(sock, message, strlen(message), 0, (struct sockaddr*)&serv_adr, sizeof(serv_adr));
adr_sz=sizeof(from_adr);
str_len=recvfrom(sock, message, BUF_SIZE, 0, (struct sockaddr*)&from_adr, &adr_sz);

close(sock);
