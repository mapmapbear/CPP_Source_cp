#include <stdio.h>
#include <stdlib.h>

#define DATATYPE int
#define ERROR -1000000 // 状态值

struct node
{
  DATATYPE data;     //数据域
  struct node *next; //指针域
};
typedef struct node Node;

typedef struct
{
  Node *front,*rear;  //队头和队尾结点
} LinkQueue;

// 操作
// 初始化空的顺序循环队列
void init(LinkQueue *q);
// 顺序循环队列的入队列操作
void push(LinkQueue *q, DATATYPE data);
// 顺序队列的出队列操作
DATATYPE pop(LinkQueue *q);
// 顺序循环队列的遍历操作
void print(LinkQueue *q);
// 判断是否为空队列，1为空队列，0不是空队列
int isEmpty(LinkQueue *q);
//取队头元素的值
DATATYPE getFront(LinkQueue *q);
//取队尾元素的值
DATATYPE getRear(LinkQueue *q);
//得到队列的长度
int getLength(LinkQueue *q);

int main(int argc, char const *argv[])
{
  /* 测试队列的常规操作*/
  LinkQueue *q = (LinkQueue *)malloc(sizeof(LinkQueue));
  init(q);
  int i;
  for (i = 0; i < 10; i++)
  {
    push(q, i + 1);
  }
  printf("入队列之后队列的长度为：%d，队列中的元素为：",getLength(q));
  //q->front  = q->front->next;
  print(q);
  printf("队头元素为：%d，队尾元素为：%d\n",getFront(q),getRear(q));
  printf("出队列元素为：%d\n",pop(q));
  printf("出队列之后队列的长度为：%d，队列中的元素为：",getLength(q));
  print(q);
  /* code */
  return 0;
}

void init(LinkQueue *q)
{
  q->front = q->rear = NULL;  
}

void push(LinkQueue *q, DATATYPE data)
{
  Node *s = (Node*)malloc(sizeof(Node));
  s->data = data;
  
  if(isEmpty(q)){
    q->rear = q->front = s;
    s->next = q->front;
  }
  else{
    s->next = q->front;s->next = q->front;
    q->rear->next = s;
    q->rear = s;
  }
}

DATATYPE pop(LinkQueue *q)
{
  if(isEmpty(q)){
    printf("队列为空，不能出队列，如果出队列元素值为：%d，表示是状态值----",ERROR);
    return ERROR;
  }
  Node *p = q->front;
  if(q->rear == p){
    int e = p->data;
    free(p);
    return e;
  }
  int e = p->data;
  q->front = p->next;
  q->rear->next = q->front;  
  free(p);
  return e;
}

void print(LinkQueue *q)
{
  Node *s = q->front;
  while(s != q->rear){
    printf("%d  ",s->data);
    s = s->next;
  }
  printf("%d  ",s->data);
  printf("\n");
}

int isEmpty(LinkQueue *q)
{
  return (q->front == NULL && q->rear == NULL) ? 1 : 0;
}

DATATYPE getFront(LinkQueue *q)
{
  return q->front->data;
}

DATATYPE getRear(LinkQueue *q)
{
  return q->rear->data;
}

int getLength(LinkQueue *q){
  int len = 0;
  Node *s = q->front;
  while(s != q->rear){
    len++;
    s = s->next;
  }
  return len+1;
}

