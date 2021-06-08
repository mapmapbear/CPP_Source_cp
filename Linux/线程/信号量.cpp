#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

sem_t sem;
void *fun1(void *arg){
    int i = 0;
    sem_wait(&sem);
    for(int i = 'A'; i < 'Z'; ++i){
        putchar(i);
        fflush(stdout);
        usleep(100000);
    }
    printf("\n");
    sem_post(&sem);
    return NULL;
}

void *fun2(void *arg){
    int i = 0;
    sem_wait(&sem);
    for(int i = 'a'; i < 'z'; ++i){
        putchar(i);
        fflush(stdout);
        usleep(100000);
    }
    printf("\n");
    sem_post(&sem);
    return NULL;
}
int main(){
    int ret = -1;
    pthread_t tid1,tid2;

    ret = sem_init(&sem, 0, 1);
    if(0 != ret){
        printf("sem_init failed...\n");
        return 1;
    }
    printf("初始化信号量ok...\n");

    pthread_create(&tid1, NULL, fun1, NULL);
    pthread_create(&tid2, NULL, fun2, NULL);

    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);

    printf("\nmain thread exit....\n");
    
    sem_destroy(&sem);
    return 0;
}