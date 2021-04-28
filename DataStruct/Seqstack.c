#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DATATYPE int
#define MAXSIZE 100
typedef struct
{
  DATATYPE a[MAXSIZE];
  int top;
  /* data */
} SeqStack;

// 操作
// 初始化空的顺序栈
void init(SeqStack *s);
// 顺序栈的入栈操作
void push(SeqStack *s, DATATYPE data);
// 顺序栈的出栈操作
DATATYPE pop(SeqStack *s);
// 顺序栈的遍历操作
void print(SeqStack *s);
// 判断是否为空栈，1为空栈，0不是空栈
int isEmpty(SeqStack *s);
// 判断栈是否满，1为满，0不满
int isFull(SeqStack *s);
//取栈顶元素的值
DATATYPE getTop(SeqStack *s);

//利用栈把n转换为d进制，转换后的结果保存在ch数组中
void conversion(SeqStack *s,int n,int d,char ch[100]);

//利用栈判断一个字符串是否为回文字符串，返回1代表是，0代表不是
int isHuiWenString(SeqStack *s,char *ch){
  char *p= ch;
  char *ss = ch;
  int len = 0;
  while(p != NULL){
    if(*p == '\0')
      break;
    push(s,(*p));
    p++;
    len++;
  }
  int c_len = 0;
  while(ss != NULL){
    if(*ss == '\0')
      break;
    if(pop(s) == (int)(*ss))
      c_len++;
    ss++;
  }
  if(c_len == len)
    return 1;
  else
    return 0;
}

int main(int argc, char const *argv[])
{
  /* 测试栈的常规操作*/
  SeqStack *s = (SeqStack *)malloc(sizeof(SeqStack));
  init(s);
  int i;
  for (i = 0; i < 10; i++)
  {
    push(s, i + 1);
  }
  printf("入栈之后栈的长度为：%d，元素为：",s->top);
  print(s);
  printf("栈顶元素为：%d\n",getTop(s));
  printf("出栈元素为：%d,之后栈的长度为：%d，元素为：",pop(s),s->top);
  print(s);
  

  /*测试十进制转换为2进制、8进制或16进制*/
  char ch[100];
  init(s);//重新初始化栈
  conversion(s,1000,16,ch);
  puts(ch);

  /*测试是否是回文字符串*/
  char *str = "abcdcba";//可更改字符串中的值
  char *str1 = "abc&cba@";
  init(s);
  isHuiWenString(s,str);
  init(s);
  isHuiwenString2(s,str1);  
  if(isHuiWenString(s,str)){
    printf("是回文字符串\n");
  }else{
    printf("不是回文字符串\n");
  }
  /* code */
  return 0;
}
//以下分别是操作（函数）的实现
void init(SeqStack *s){
  s->top = 0;
}

void push(SeqStack *s, DATATYPE data){
  if(isFull(s)){
    printf("栈已满\n");
    return;
  }
  s->a[s->top] = data;
  s->top++;
}

DATATYPE pop(SeqStack *s){
  if(isEmpty(s)){
    printf("栈为空\n");
    return 0;//此处应该是超出栈的值范围的值
  }
  s->top--;
  return s->a[s->top];
}

DATATYPE getTop(SeqStack *s){

  return s->a[s->top-1];
}

int isEmpty(SeqStack *s){
  return s->top == 0?1:0;
}

int isFull(SeqStack *s){
  return s->top == MAXSIZE?1:0;
}
void print(SeqStack *s){
  int i;
  for(i=s->top-1;i>=0;i--){
    printf("%d   ",s->a[i]);
  }
  printf("\n");
}

void conversion(SeqStack *s,int n,int d,char ch[100]){
  int i=0;
  while(n){
    push(s,n%d);
    n = n/d;    
  }
  // 按照进制的通用表示方法：八进制以”0“开始，十六进制以”0X“开始
  if(d==8){
    ch[0] = '0';
    i=1;
  }else if(d==16){
    ch[0]='0';
    ch[1]='X';
    i=2;
  }
  while(!isEmpty(s)){
    DATATYPE a =  pop(s);
    if(a >= 0 && a <= 9){
         ch[i] = a + '0';//把数字转换为数字字符
    }else{
      switch (a)
      {
        case 10: ch[i] = 'A';break;
        case 11: ch[i] = 'B';break;
        case 12: ch[i] = 'C';break;
        case 13: ch[i] = 'D';break;
        case 14: ch[i] = 'E';break;
        case 15: ch[i] = 'F';break;
      }
    }    
    i++;
  }
  ch[i]='\0';//字符串结束标记符
}






