#include <stdio.h>
#include <stdlib.h>

#define DATATYPE int
#define ERROR -1000000 // 状态值
#define MAXSIZE 100

//顺序队列类型说明
typedef struct
{
  DATATYPE a[MAXSIZE]; //数组
  int front, rear;     //队头队尾数组下标
} SeqQueue;

// 操作
// 初始化空的顺序循环队列
void init(SeqQueue *q);
// 顺序循环队列的入队列操作
void push(SeqQueue *q, DATATYPE data);
// 顺序队列的出队列操作
DATATYPE pop(SeqQueue *q);
// 顺序循环队列的遍历操作
void print(SeqQueue *q);
// 判断是否为空队列，1为空队列，0不是空队列
int isEmpty(SeqQueue *q);
// 判断队列是否满，1为满，0不满
int isFull(SeqQueue *q);
//取队头元素的值
DATATYPE getFront(SeqQueue *q);
//取队尾元素的值
DATATYPE getRear(SeqQueue *q);
//得到队列的长度
int getLength(SeqQueue *q);

int main(int argc, char const *argv[])
{
  /* 测试队列的常规操作*/
  SeqQueue *q = (SeqQueue *)malloc(sizeof(SeqQueue));
  init(q);
  int i;
  for (i = 0; i < 10; i++)
  {
    push(q, i + 1);
  }
  printf("入队列之后队列的长度为：%d，队列中的元素为：",getLength(q));
  print(q);
  printf("队头元素为：%d，队尾元素为：%d\n",getFront(q),getRear(q));
  printf("出队列元素为：%d\n",pop(q));
  printf("出队列之后队列的长度为：%d，队列中的元素为：",getLength(q));
  print(q);

  return 0;
}

void init(SeqQueue *q)
{
  q->front = q->rear = 0;
}

void push(SeqQueue *q, DATATYPE data)
{  
  if(isFull(q)){
    printf("队列已满，不能入队列\n");
    return;
  }
  q->a[q->rear] = data;
  q->rear = q->rear + 1;
  
}

DATATYPE pop(SeqQueue *q)
{
  if(isEmpty(q)){
    printf("队列为空，不能出队列，如果出队列元素值为：%d，表示是状态值----",ERROR);
    return ERROR;
  }
  int e = q->a[q->front];
  q->front = q->front + 1;
  return e;
}

void print(SeqQueue *q)
{
  int _front = q->front;
  int _rear = q->rear;
  for(int i = _front; i <= _rear; i++)
    printf("%d  ",q->a[i]);

  printf("\n");
}

int isEmpty(SeqQueue *q)
{
  return q->front == q->rear ? 1 : 0;
}

int isFull(SeqQueue *q)
{
  return q->front == MAXSIZE-1 ? 1 : 0; 
}

DATATYPE getFront(SeqQueue *q)
{
  return q->a[q->front];
}

DATATYPE getRear(SeqQueue *q)
{
  return q->a[q->rear];
}

int getLength(SeqQueue *q){
  int len = 0;
  int _front = q->front;
  int _rear = q->rear;
  for(int i = _front; i <= _rear; i++)
    len++;
  return len;
}

