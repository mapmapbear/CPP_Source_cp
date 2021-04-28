#include <stdio.h>
#include <stdlib.h>

#define N 10
//函数声明
int maxOfArray(int a[],int n);

int main(int argc, char const *argv[])
{
  /* code */
  int a[N], max, i;
  srand((unsigned int)time(0)); //设置随机数种子
  // rand()函数默认产生 0 到 32767 之间的随机数
  printf("随机产生%d个数(1到100之间)：\n", N);
  for (i = 0; i < N; i++)
  {
    a[i] = rand() % 100 + 1;
    printf("%-5d", a[i]);
  }
  max = maxOfArray(a, N);
  printf("\n上述数的最大值为：%d\n", max);

  return 0;
}

int maxOfArray(int a[],int n)
{		
  if(n == 1){
    return a[0];
  }
  else{
    int max = maxOfArray(a, n-1);
    return a[n-1] > max ? a[n-1] : max;
  }
  return 0;
}
