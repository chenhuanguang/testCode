#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(int argc, char *argv[])
{
	FILE *fpIn = fopen(argv[1], "rb");
	if (NULL == fpIn)
	{
		printf("Open src File Error.\n");
		return 0;
	}
	FILE *fpOut = fopen(argv[2], "wb");
	if (NULL == fpOut)
	{
		printf("Open dest File Error.\n");
		return 0;
	}

	char buffer[256] = { 0 };

	while (!feof(fpIn))
	{
		size_t sz = fread(buffer, sizeof(char), 256, fpIn);
		if (sz == 0)
			break;
		fwrite(buffer, sizeof(char), sz, fpOut);
	}
	fclose(fpIn);
	fclose(fpOut);

	return 0;
}

/*
int main(int argc,char *argv[])
{
	FILE *fpIn = fopen(argv[1], "r");
	if (NULL == fpIn)
	{
		printf("Open src File Error.\n");
		return 0;
	}
	FILE *fpOut = fopen(argv[2], "w");
	if (NULL == fpOut)
	{
		printf("Open dest File Error.\n");
		return 0;
	}

	while (!feof(fpIn))
	{
		char ch = fgetc(fpIn);
		fputc(ch, fpOut);
	}
	fclose(fpIn);
	fclose(fpOut);

	return 0;
}
*/
/*文件拷贝方式3
int main()
{
	FILE *fpIn = fopen("Test.c", "r");
	if (NULL == fpIn)
	{
		printf("Open Input File Error.\n");
		return 0;
	}
	FILE *fpOut = fopen("my_Test2.c", "w");
	if (NULL == fpOut)
	{
		printf("Open Output File Error.\n");
		return 0;
	}

	char buffer[256] = { 0 };

	while (!feof(fpIn))
	{
		char *res = fgets(buffer, 256, fpIn);
		if (res == NULL)
		{
			break;
		}
		fputs(buffer,fpOut);
	}
	fclose(fpIn);
	fclose(fpOut);

	return 0;
}
*/
/*拷贝方式2
int main()
{
	FILE *fpIn = fopen("Test.c", "r");
	if (NULL == fpIn)
	{
		printf("Open Input File Error.\n");
		return 0;
	}
	FILE *fpOut = fopen("my_Test1.c", "w");
	if (NULL == fpOut)
	{
		printf("Open Output File Error.\n");
		return 0;
	}

	//拷贝过程
	while (!feof(fpIn))
	{
		char ch = fgetc(fpIn);
		fputc(ch, fpOut);
	}
	fclose(fpIn);
	fclose(fpOut);

	return 0;
}
*/
/*文件拷贝方式1
int main()
{
	FILE *fpIn = fopen("Test.c", "r");
	if (NULL == fpIn)
	{
		printf("Open Input File Error.\n");
		return 0;
	}
	FILE *fpOut = fopen("my_Test.c", "w");
	if (NULL == fpOut)
	{
		printf("Open Output File Error.\n");
		return 0;
	}

	//拷贝过程
	char ch = fgetc(fpIn);
	while (ch != EOF) //end of file
	{
		fputc(ch, fpOut);
		ch = fgetc(fpIn);//自动读取下一个字符
	 }
	fputc(ch, fpOut);

	fclose(fpIn);
	fclose(fpOut);

	return 0;
}
*/
/*二进制读入 
int main()
{
	int ar[10];
	FILE *fp = fopen("Test2.txt", "rb");
	if (NULL == fp)
	{
		printf("Open File Error.\n");
		return 0;
	}
	fread(ar, sizeof(int), 10, fp);

	fclose(fp);

	return 0;
}
*/
/*二进制写入
int main()
{

	int ar[] = { 12,23,34,45,56,67,78,89,90,100 };
	int n = sizeof(ar) / sizeof(int);

	FILE *fp = fopen("Test2.txt", "wb");
	if (NULL == fp)
	{
		printf("Open File Error.\n");
		return 0;
	}

	fwrite(ar, sizeof(int), n, fp);

	fclose(fp);

	return 0;
}
*/
/*
int main()
{
	int ar[] = { 1000,2000,3000 };
	FILE *fp = fopen("Test.txt", "a");
	if (NULL == fp)
	{
		printf("Open File Error.\n");
		return 0;
	}
	for (int i = 0; i < 3; i++)
	{
		fprintf(fp, "%d ", ar[i]);
	}

	fclose(fp);

	return 0;
}
*/
/*只读
int main()
{
	int ar[10];
	FILE *fp = fopen("Test.txt", "r");
	if (NULL == fp)
	{
		printf("Open File Error.\n");
		return 0;
	}
	for (int i = 0; i < 10; i++)
	{
		fscanf(fp, "%d ", &ar[i]);
	}

	fclose(fp);

	return 0;
}*/

/*只写
int main()
{

	int ar[] = { 12,23,34,45,56,67,78,89,90,100 };
	int n = sizeof(ar) / sizeof(int);

	FILE *fp = fopen("Test.txt", "w");
	if (NULL == fp)
	{
		printf("Open File Error.\n");
		return 0;
	}

	for (int i = 0; i < n; i++)
	{
		fprintf(fp, "%d ", ar[i]);
	}

	fclose(fp);

	return 0;
}
*/