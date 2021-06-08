#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

typedef struct _node_t{
    int data;
    struct _node_t *next;
}node_t;

node_t *head = NULL;

sem_t sem_producer;
sem_t sem_customer;

void *producer(void *arg){
    while(1){
        sem_wait(&sem_producer);
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
        
        sem_post(&sem_customer);
        sleep(random() % 3 + 1);
    }
    pthread_exit(NULL);
}

void *customer(void *arg){
    node_t *tmp = NULL;
    while(1){
        sem_wait(&sem_customer);
        if(NULL == head){
            printf("产品为空 wait 2 sec...\n");
            //pthread_cond_wait(&cond, &mutex);
            //sleep(2);
        }
        else{
            tmp = head;
            head = head->next;

            printf("消费者消费：%d\n",tmp->data);
            free(tmp);
            sem_post(&sem_producer);            
            sleep(random() % 3 + 1);
        }
    }
    pthread_exit(NULL);
}
int main(){
    int ret = -1;
    pthread_t tid[6];
    srandom(getpid());
    ret = sem_init(&sem_producer, 0, 4);
    if(0 != ret){
        printf("sem_init failed...\n");
        return 1;
    }

    ret = sem_init(&sem_customer, 0, 0);
    if(0 != ret){
        printf("sem_init failed...\n");
        return 1;
    }
    for(int i = 0; i < 6; ++i){
        if(i < 2)
            pthread_create(&tid[i], NULL, producer, NULL);
        else
            pthread_create(&tid[i], NULL, customer, NULL);
    }
    for(int i = 0; i < 6; ++i){
        pthread_join(tid[i], NULL);
    }

    sem_destroy(&sem_producer);
    sem_destroy(&sem_customer);
    
    return 0;
}