// Find Header Files and Put them here
// For example, #include <stdio.h>

// Please Add your remark at the ends of lines, line by line


int serv_sock, clnt_sock;
char message[BUF_SIZE];
int str_len, i;
struct sockaddr_in serv_adr;
struct sockaddr_in clnt_adr;
socklen_t clnt_adr_sz;

serv_sock=socket(PF_INET, SOCK_STREAM, 0);   
memset(&serv_adr, 0, sizeof(serv_adr));
serv_adr.sin_family=AF_INET;
serv_adr.sin_addr.s_addr=htonl(INADDR_ANY);
serv_adr.sin_port=htons(atoi(argv[1]));
bind(serv_sock, (struct sockaddr*)&serv_adr, sizeof(serv_adr));
listen(serv_sock, 5); 	
clnt_adr_sz=sizeof(clnt_adr);
clnt_sock=accept(serv_sock, (struct sockaddr*)&clnt_adr, &clnt_adr_sz);
	
str_len=read(clnt_sock, message, BUF_SIZE)
write(clnt_sock, message, str_len);

close(clnt_sock);
close(serv_sock);
