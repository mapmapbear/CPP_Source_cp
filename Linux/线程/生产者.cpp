#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
typedef struct _node_t{
    int data;
    struct _node_t *next;
}node_t;

node_t *head = NULL;

pthread_cond_t cond;
pthread_mutex_t mutex;

void *producer(void *arg){
    while(1){
        pthread_mutex_lock(&mutex);
        node_t *new = malloc(sizeof(node_t));
        if(NULL == new){
            printf("malloc failed...\n");
            break;
        }
        memset(new, 0, sizeof(node_t));

        new->data = (random() % 100) +1;
        new->next = NULL;
        
        new->next = head;
        head = new;
        printf("生产者生产产品：%d\n",new->data);
        pthread_mutex_unlock(&mutex);
        pthread_cond_signal(&cond);
        sleep(random() % 3 + 1);
    }
    pthread_exit(NULL);
}

void *customer(void *arg){
    node_t *tmp = NULL;
    while(1){
        pthread_mutex_lock(&mutex);
        if(NULL == head){
            printf("产品为空 wait 2 sec...\n");
            pthread_cond_wait(&cond, &mutex);
            //sleep(2);
        }
        else{
            tmp = head;
            head = head->next;

            printf("消费者消费：%d\n",tmp->data);
            free(tmp);
            pthread_mutex_unlock(&mutex);
            pthread_cond_signal(&cond);
            sleep(random() % 3 + 1);
        }
    }
    pthread_exit(NULL);
}
int main(){
    int ret = -1;
    pthread_t tid1 = -1, tid2 = -1;
    srandom(getpid());
    ret = pthread_cond_init(&cond, NULL);
    if(0 != ret){
        printf("pthread_cond_init failed...\n");
        return 1;
    }

    ret = pthread_mutex_init(&mutex, NULL);
    if(0 != ret){
        printf("pthread_mutex_init failed...\n");
        return 1;
    }

    pthread_create(&tid1, NULL, producer, NULL);
    pthread_create(&tid2, NULL, customer, NULL);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    pthread_cond_destroy(&cond);
    pthread_mutex_destroy(&mutex);

    return 0;
}