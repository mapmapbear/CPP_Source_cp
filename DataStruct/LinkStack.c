#include <stdio.h>
#include <stdlib.h>

#define DATATYPE int

struct node
{
  DATATYPE data;     //数据域
  struct node *next; //指针域
};
typedef struct node Node;

// 操作
// 初始化空的链栈
void init(Node *top){
  top = (Node*)malloc(sizeof(Node));
  top->next = NULL;
  top->data = 0;
}
// 链栈的入栈操作
void push(Node *top, DATATYPE data){
  if(top == NULL)
    return ;
  Node *s = (Node*)malloc(sizeof(Node));
  if(s == NULL)
    return;
  s->data = data;
  s->next = top->next;
  top->next = s;
}
// 链栈的出栈操作
DATATYPE pop(Node *top){
  if(top == NULL)
    return 0;
  Node *s = top->next;
  top->next = s->next;
  int x = s->data;
  free(s);
  return x;
}
// 链栈的遍历操作
void print(Node *top){
  Node *p = top->next;
  while(p != NULL){
    printf("%d ",p->data); 
    p = p->next;
  }
}
//取栈顶元素的值
DATATYPE getTop(Node *top){
  return top->next->data;
}
//求链栈的长度
int getLength(Node *top){
  Node *p = top->next;
  int length = 0;
  if(p == NULL)
    return 0;
  while(p != NULL){
    p = p->next;
    length++;
  }
  return length;
}
// 判断是否为空栈，1为空栈，0不是空栈
int isEmpty(Node *top){
  if(top->next == NULL)
    return 1;
  else
    return 0;
}

int main(int argc, char const *argv[])
{
  Node *top = (Node*)malloc(sizeof(Node));
  init(top);
  int i;
  for (i = 0; i < 10; i++)
  {
    push(top, i + 1);
  }
  printf("入栈之后栈的长度为：%d，元素为：",getLength(top));
  print(top);
  printf("栈顶元素为：%d\n",getTop(top));
  printf("\n出栈元素为：%d",pop(top));
  printf(",之后栈的长度为：%d，元素为:",getLength(top));
  print(top);
  

  /* code */
  return 0;
}



