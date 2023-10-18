#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/select.h>

#define BUF_SIZE 30

int main(int argc, char *argv[])
{
    fd_set reads, temps;
    int result, str_len;
    char buf[BUF_SIZE];
    struct timeval timeout;

    FD_ZERO(&reads);
    FD_SET(0, &reads); // fd 0, 표준입력에 변화가 있는지 보겠다

    timeout.tv_sec = 5;
    timeout.tv_usec = 5000;

    while (1)
    {
        temps = reads; 
        // select 호출이 끝나면 변화가 생긴 나머지 비트 0으로 초기화
        // 원본의 유지를 위해 일반적인 사용방법
        timeout.tv_sec = 5;
        timeout.tv_usec = 0;
        result = select(1, &temps, 0, 0, &timeout);
        if (result == -1)
        {
            puts("select() error!");
            break;
        }
        else if (result == 0)
        {
            puts("Time-out!");
        }
        else
        {
            if (FD_ISSET(0, &temps))
            {
                str_len = read(0, buf, BUF_SIZE);
                buf[str_len] = 0;
                prinf("message from console: %s", buf);
            }
        }
    }
    return 0;
}