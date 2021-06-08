#include <bits/types/siginfo_t.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void fun(int signum){
    printf("信号捕捉：%d\n",signum);
}

void fun1(int signum, siginfo_t *info, void *context){
    printf("信号捕捉：%d\n",signum);
}
int main(){
    int ret = -1;
    struct sigaction act;
    
    #if 0
    act.sa_handler = fun;
    act.sa_flags = 0;
    #else
    act.sa_sigaction = fun1;
    act.sa_flags = SA_SIGINFO;
    #endif

   
    ret = sigaction(SIGINT,&act,NULL);
    if(-1 == ret){
        perror("sigaction");
        return 1;
    }
    printf("按任意键继续...\n");
    getchar();
    getchar();


    return 0;
}
