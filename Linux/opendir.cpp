#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include <unistd.h>
#include <dirent.h>

int main(){
    // DIR *dir = NULL;
    // struct dirent *d = NULL;
    // dir = opendir("/home/mapmap/Downloads");
    // if(NULL == dir){
    //     perror("opendir:");
    //     return 1;
    // }
    // printf("Open dir Successful!\n");
    // while(1){
    //     d = readdir(dir);
    //     if(d == NULL){
    //         perror("readdir:");
    //         break;
    //     }
    //     printf("d_type:%hu  d_name:%s\n",d->d_type,d->d_name);
    // }
    // closedir(dir);

    printf("进程号为:%d, 父进程号:%d,组进程号:%d",getpid(),getppid(),getpgid(getpid()));

    return 0;
}