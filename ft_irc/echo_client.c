#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 1024
void error_handling(char *message);

int main(int argc, char* argv[])
{
	int sock;
	char message[BUF_SIZE];
	struct sockaddr_in serv_addr;
	int str_len = 0;
	int recv_len, recv_cnt; // 추가

	if (argc != 3)
	{
		printf("Usage : %s <IP> <port>\n", argv[0]);
		exit(1);
	}

	sock = socket(PF_INET, SOCK_STREAM, 0);
	if (sock == -1)
		error_handling("socket() error");

	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
	serv_addr.sin_port = htons(atoi(argv[2]));

	if (connect(sock, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) == -1)
		error_handling("connect() error!");
	else
		puts("Connected................");

	while (1)
	{
		fputs("Input message(Q to quit): ", stdout);
		fgets(message, BUF_SIZE, stdin);

		if (!strcmp(message, "q\n") || !strcmp(message, "Q\n"))
			break;

		// write(sock, message, strlen(message));
		// str_len = read(sock, message, BUF_SIZE - 1);
		str_len =  write(sock, message, strlen(message));
		while (recv_len < str_len)
		{
			recv_cnt = read(sock, &message[recv_len], BUF_SIZE - 1);
			if (recv_cnt == -1)
				error_handling("read() error!");
			recv_len += recv_cnt;
		}
		message[str_len] = 0;
		printf("Message from server : %s", message);
	}
	close(sock); // EOF 가 전달됨
	return 0;
}

void error_handling(char *message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}

// ./client 127.0.0.1 9000
