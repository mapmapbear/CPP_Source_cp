#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>
#include <string.h>

int main(){
    pid_t pid = -1;
    int ret = -1;
    pid = fork();
    if(-1 == pid){
        perror("fork:");
        return 1;
    }

    if(pid > 0){
        exit(0);
    }

    pid = setsid();
    if(-1 == pid){
        perror("setpid:");
        return 1;
    }

    ret = chdir("/");
    if(-1 == ret){
        perror("chdir:");
        return 1;
    }
    time_t t = time(NULL);
    struct tm *pT = NULL;
    pT = localtime(&t);
    char buf[100];
    memset(buf,0,100);
    sprintf(buf,"%s %d%d%d%d%d%d.log", "touch ", pT->tm_year+1990, pT->tm_mon+1, pT->tm_mday, pT->tm_hour, pT->tm_min, pT->tm_sec);
    printf("%s\n",buf);
    umask(0);

    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);
    system(buf);
    // while(1){
    //     system("date >> /tmp/txt.log");
    //     sleep(1);
    // }
}