#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int num = 1;
pthread_rwlock_t rwlock;

void *fun_read(void *arg){
    int idx = (int)(long)arg;
    while(1){
        pthread_rwlock_rdlock(&rwlock);
        printf("thread %d read_value is:%d\n",idx,num);
        pthread_rwlock_unlock(&rwlock);
        sleep(random() % 3 + 1);
    }

    return NULL;
}

void *fun_write(void *arg){
    int idx = (int)(long)arg;
    while(1){
        pthread_rwlock_wrlock(&rwlock);
        num++;
        printf("thread %d write_value is:%d\n",idx,num);
        pthread_rwlock_unlock(&rwlock);
        sleep(random() % 3 + 1);
    }

    return NULL;
}
int main(){
    int ret = -1;
    int i;
    pthread_t tid[8];
    srandom(getpid());

    ret = pthread_rwlock_init(&rwlock, NULL);
    if(0 != ret){
        printf("pthread_rwlock_init failed...\n");
        return 1;
    }
    //create No.8 thread
    for(i = 0; i < 8; ++i){
        if(i < 5)
            pthread_create(&tid[i], NULL, fun_read, (void*)(long)i);
        else
            pthread_create(&tid[i], NULL, fun_write, (void*)(long)i);
    }


    for(i = 0; i < 8; ++i)
        pthread_join(tid[i], NULL);

    ret = pthread_rwlock_destroy(&rwlock);
    if(0 != ret){
        printf("pthread_rwlock_destroy failed...\n");
        return 1;
    }
}