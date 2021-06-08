#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include "wrap.h"
void free_process(int sig){
    pid_t pid;
    while (1) {
        waitpid(-1,NULL,WNOHANG);
        if(pid <= 0)
            break;
        else{
            printf("child pid = %d\n",pid);
        }
    }
}
int main(int argc, char* argv[]){
    //创建套接字
    int lfd = tcp4bind(8000, NULL);
    Listen(lfd, 128);
    struct sockaddr_in cliaddr;
    socklen_t len = sizeof(cliaddr);
    while(1){
        char ip[] = "";
        int cfd = Accept(lfd,(struct sockaddr *)&cliaddr, &len);
        printf("new client ip =%s port =%d\n",inet_ntop(AF_INET, &cliaddr.sin_addr.s_addr, ip, 16),ntohs(cliaddr.sin_port));
        pid_t pid;
        pid = fork();
        if(pid < 0){
            perror("fork failed...\n");
            exit(0);
        }
        else if(pid == 0){
            close(lfd);
            char buf[1024] = "";
            while(1){
                int n = read(cfd, buf, sizeof(buf));
                if(n < 0){
                    perror("");
                    exit(0);
                }
                else if(n == 0){
                printf("client close\n");
                close(cfd);
                exit(0);
                }
                else{
                    printf("%s",buf);
                    write(cfd, buf, n);
                }
            }
        }
        else{
            close(cfd);
            struct sigaction act;
            act.sa_flags = 0;
            act.sa_handler = free_process;
            sigemptyset(&act.sa_mask);
            sigaction(SIGCHLD, &act, NULL);
        }
    }
    return 0;
}

