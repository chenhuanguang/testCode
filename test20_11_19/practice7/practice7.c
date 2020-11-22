#include<stdio.h>
#include<malloc.h>


#define LOW 3
#define COL 3

int* spiralOrder(int (*arr)[COL], int* returnSize){

	//计算数组的个数，也就是列表的长度
	*returnSize = COL*LOW;

	int* val = (int*)malloc(sizeof(int)*(*returnSize));
	//分别定义 左 右 上 下 的边界 
	int l = 0, r = COL - 1, t = 0, b = LOW - 1, x = 0;

	while (1)
	{
		// left to right.
		for (int i = l; i <= r; i++)	//从左到右，i就等于左，i<=右
		{
			val[x++] = arr[t][i]; //在最上一行输出，变化的是列，所以列标=i
		}

		if (++t > b) break;	//下面要走的是从上到下，所以先判断上边界+1是否比下边界大，如果大说明已经打印完全。
		// top to bottom.
		for (int i = t; i <= b; i++)	//从上到下，i就等于上，i<=下
		{
			val[x++] = arr[i][r]; //在最右一列输出，变化的是行，所以行标=i
		}

		if (l > --r) break;	//下面要走的是从右到左，所以先判断左边界是否比右边界-1大，如果大说明已经打印完全。
		// right to left.
		for (int i = r; i >= l; i--)	//从右到左，i就等于右，i>=左
		{
			val[x++] = arr[b][i];	//在最后一行输出,变化的是列标,所以列表=i
		}

		if (t > --b) break;	//下面要走的是从下到上，所以先判断上边界是否比下边界-1大，如果大说明已经打印完全。
		// bottom to top.
		for (int i = b; i >= t; i--)	//从下到上，i就等于下，i>=上
		{
			val[x++] = arr[i][l];	//在最左一列输出,变化的是行标,所以行表=i
		}
		if (++l > r) break;	 //下面要走的是从左到右，所以先判断左边界+1是否比右边界大，如果大说明已经打印完全。
	}
	return val;
}

int main()
{
	//定义二维数组
	int arr[][COL] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 }; 

	//用于接收val的列表的长度
	int returnSize;

	//定义arr2用来接收val的首地址
	int *arr2 = spiralOrder(arr, &returnSize);

	//打印列表val
	for (int i = 0; i < returnSize; i++)
	{
		printf("%d ", arr2[i]);
	}
	printf("\n");

	return 0;
}
