#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdio.h>

int main(){
    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8080);
    inet_pton(AF_INET, "192.168.1.246", &addr.sin_addr.s_addr);

    int ret = connect(sock_fd, (struct sockaddr *)&addr, sizeof(addr));
    

    char buf[1024] = "";
    while (1) {
        int n = read(STDIN_FILENO, buf, sizeof(buf));
        write(sock_fd, buf, n);
        n = read(sock_fd,buf,sizeof(buf));
        //write(STDOUT_FILENO, buf, sizeof(buf));
    }


    close(sock_fd);
}