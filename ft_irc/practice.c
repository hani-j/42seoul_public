#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define PORT 9000

char buffer[BUFSIZ] = "hello, world";

main() {
   int c_socket, s_socket;
   struct sockaddr_in s_addr, c_addr;
   int len;
   int n;

   // 1. 소켓 생성
   s_socket = socket(PF_INET, SOCK_STREAM, 0); // socket 의 유형 설정

   // 2. 연결 요청을 수신할 주소 설정
   memset(&s_addr, 0, sizeof(s_addr));
   s_addr.sin_addr.s_addr = htonl(INADDR_ANY);
   s_addr.sin_family = AF_INET;
   s_addr.sin_port - htons(PORT);

   // 3. 소켓을 포트에 연결
   if (bind(s_socket, (struct sockaddr *) &s_addr, sizeof(s_addr)) == -1) {
      printf("Can't Bind\n");
      return -1;
   }

   // 4. 커널에 개통을 요청
   if (listen(s_socket, 5) == -1) {
      printf("listen Fail\n");
      return -1;
   }

   // 5. 연결 요청을 받아 처리하는 작업 반복
   while (1) {

      // 6. 클라이언트로부터 연결 요청을 수신
      len = sizeof(c_addr);
      c_socket = accept(s_socket, (struct sockaddr *) &c_addr, &len);

      // 7. 클라이언트에게 서비스를 제공
      n = strlen(buffer);
      write(c_socket, buffer, n);

      close(c_socket);
   }
   close(s_socket);
}

// telnet 을 사용해서 해보기
// telnet localhost 9000