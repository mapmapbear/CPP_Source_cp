#include <stdio.h>
#include <stdlib.h>

#define N 10
//函数声明
int bSearch(int *a, int x, int low, int high);

int main(int argc, char const *argv[])
{
	/* code */
	int a[N], result, x, i; //result代表查找的结果，x代表查找的数
	printf("请输入%d个数（从小到大）：\n", N);
	for (i = 0; i < N; i++)
	{
		scanf("%d", &a[i]);
	}
	printf("请输入要查找的数：");
	scanf("%d", &x);
	result = bSearch(a, x, 0, 9);
	if (result == -1)
	{
		printf("%d不在上述数中", x);
	}
	else
	{
		printf("%d在上述数中，是第%d个数\n", x, result + 1);
	}
	return 0;
}
/*拆半查找，a代表数组，x代表要查找的数，low和high分别是低位和高位下标
查找不成功返回-1，成功返回此值所对应的下标
*/
int bSearch(int *a, int x, int low, int high)
{
	if(low > high)
		return -1;
	else{
		int idx = (low + high) / 2;
		if(x == a[idx])
			return a[idx];
		else if(x < a[idx])
			return bSearch(a, x, low, idx-1);
		else
			return bSearch(a, x, idx+1, high);
	}
	return -1;
}
