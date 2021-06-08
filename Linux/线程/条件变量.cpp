#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t mutex;//互斥量
pthread_cond_t cond; //条件变量
int flag = 0;

void *fun1(void *arg){
    while(1){
        pthread_mutex_lock(&mutex);
        flag = 1;
        pthread_mutex_unlock(&mutex);

        pthread_cond_signal(&cond);
        //线程1已经改变条件

        sleep(2);
    }
    return NULL;
}

void *fun2(void *arg){
    while(1){
        pthread_mutex_lock(&mutex);
        if(0 == flag){
            pthread_cond_wait(&cond, &mutex);
        }
        printf("线程2因为条件满足开始运行...\n");
        flag = 0;

        pthread_mutex_unlock(&mutex);

        pthread_cond_signal(&cond);

        sleep(2);
    }
    return NULL;
}

int main(){
    int ret = -1;
    pthread_t tid1,tid2;
    
    ret = pthread_cond_init(&cond,NULL);
    if(ret != 0){
        printf("pthread_cond_init failed...\n");
        return 1;
    }

    ret = pthread_mutex_init(&mutex, NULL);
    if(ret != 0){
        printf("pthread_mutex_init failed...\n");
        return 1;
    }

    pthread_create(&tid1, NULL, fun1, NULL);
    pthread_create(&tid2, NULL, fun2, NULL);

    ret = pthread_join(tid1, NULL);
    if(0 != ret){
        printf("pthread_join failed...\n");
        return 1;
    }
    ret = pthread_join(tid2, NULL);
    if(0 != ret){
        printf("pthread_join failed...\n");
        return 1;
    }
    
    return 0;
}