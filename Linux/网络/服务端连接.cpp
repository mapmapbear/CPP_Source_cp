#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <strings.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdio.h>

int main(){
    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8080);
    inet_pton(AF_INET, "192.168.1.246", &addr.sin_addr.s_addr);
    int ret = bind(sock_fd, (struct sockaddr*)&addr, sizeof(addr));
    if(ret < 0){
        perror("");
        exit(0);
    }
    listen(sock_fd, 128);
    struct sockaddr_in cliaddr;
    socklen_t len = sizeof(cliaddr);
    int cfd = accept(sock_fd, (struct sockaddr*)&cliaddr, &len);
    char ip[16]="";
    printf("new clien ip= %s port=%hu\n",inet_ntop(AF_INET,&cliaddr.sin_addr.s_addr,ip,16),ntohs(cliaddr.sin_port));

    char buf[1024] = "";
    while(1){
        bzero(buf, sizeof(buf));
        int n = 0;
        n = read(cfd,buf,sizeof(buf));
		if(n ==0 )//如果read返回等于0,代表对方关闭 
		{
			printf("client close\n");
			break;
		}
        printf("%s\n",buf);
    }
    close(sock_fd);
    close(cfd);
    return 0;
}