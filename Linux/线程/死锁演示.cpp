#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

pthread_mutex_t mutex1,mutex2;

void *fun1(void *arg){
    pthread_mutex_lock(&mutex1);
    printf("mutex1....\n");
    pthread_mutex_lock(&mutex2);
    printf("mutex2....\n");

    printf("线程1执行临界区代码...\n");

    pthread_mutex_unlock(&mutex1);
    pthread_mutex_unlock(&mutex2);
    return NULL;
}

void *fun2(void *arg){
    pthread_mutex_lock(&mutex2);
    printf("mutex1....\n");
    pthread_mutex_lock(&mutex1);
    printf("mutex2....\n");

    printf("线程2执行临界区代码...\n");

    pthread_mutex_unlock(&mutex2);
    pthread_mutex_unlock(&mutex1);
    return NULL;
}

int main(){
    int ret = -1;
    pthread_t tid1,tid2;

    pthread_mutex_init(&mutex1, NULL);
    pthread_mutex_init(&mutex2, NULL);

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
}