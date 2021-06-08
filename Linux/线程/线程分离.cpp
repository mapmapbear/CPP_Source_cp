#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

void *fun(void *arg){
    int i = 0;
    for(i = 0; i < 5; ++i){
        printf("pthread do working... %d\n",i);
        sleep(1);
    }

    pthread_exit(NULL);
    //return NULL;
}


int main(){
    int ret = -1;
    pthread_t tid;
    ret = pthread_create(&tid, NULL, fun, NULL);
    if(0 != ret){
        printf("pthread_create failed...\n");
        return 1;
    }
    
    printf("main thread ....tid:%lu\n",pthread_self());


    //设置线程分离
    ret = pthread_detach(tid);
    if(0 != ret){
        printf("pthread_detach failed....\n");
        return 1;
    }

    //设置线程join
    ret = pthread_join(tid, NULL);
    if(0 != ret){
        printf("pthread_join failed...\n");
    }
    else{
        printf("pthread_join is ok...\n");
    }

    printf("按任意键退出...\n");
    getchar();
    return 0;
}