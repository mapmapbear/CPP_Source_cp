#include <bits/types/siginfo_t.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
void fun(int signum, siginfo_t *info, void *ch){
    printf("进程信号为:%d\n",signum);
    while (waitpid(-1,NULL,WNOHANG) <= 0) {
        continue;
    }
}
int main(){
    pid_t pid = -1; 
    struct sigaction act;
    act.sa_flags = SA_SIGINFO;
    act.sa_sigaction = fun;
    pid = fork();
    if(-1 == pid){
        perror("forl");
        return 1;
    }
    if(pid == 0){
        printf("the child process sleep 2s...\n");
        sleep(2);
        printf("the child process exit...\n");
        exit(0);
    }
    else{
        while(1){
            sleep(1);
            printf("the percent process is running..\n");
        }
    }
    return 0;
}