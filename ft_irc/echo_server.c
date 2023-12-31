#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 1024
void error_handling(char *message);

int main(int argc, char *argv[])
{
	int serv_sock;
	int clnt_sock;

	char message[BUF_SIZE];
	int str_len, i;

	struct sockaddr_in serv_addr;
	struct sockaddr_in clnt_addr;
	socklen_t clnt_addr_size;

	if (argc != 2)
	{
		printf("Usage : %s <port>\n", argv[0]);
		exit(1);
	}

	serv_sock = socket(PF_INET, SOCK_STREAM, 0);
	if (serv_sock == -1)
		error_handling("socket() error");
	
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr.sin_port = htons(atoi(argv[1]));

	// IP, PORT 번호 할당
	if (bind(serv_sock, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) == -1)
		error_handling("bind() error");

	// 연결요청을 받아들일 수 있는 상태가 됨
	if (listen(serv_sock, 5) == -1)
		error_handling("listen() error");

	// 연결요청의 수락을 위한 함수 (연결요청이 있을 때까지 함수는 반환하지 않음)
	clnt_addr_size = sizeof(clnt_addr);

	// iterative server
	for (i = 0; i < 5; i++)
	{
		clnt_sock = accept(serv_sock, (struct sockaddr *) &clnt_addr, &clnt_addr_size);
		if (clnt_sock == -1)
			error_handling("accept() error");
		else
			printf("Connected client %d \n", i+1);
		
		while ((str_len = read(clnt_sock, message, BUF_SIZE)) != 0)
		{
			write(clnt_sock, message, str_len);
		}
		close(clnt_sock);
	}
	close(serv_sock);
	return 0;
}

void error_handling(char *message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}

// ./server 9000
