#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

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

	//¿½±´¹ý³Ì
	while (!feof(fpIn))
	{
		char ch = fgetc(fpIn);
		fputc(ch, fpOut);
	}
	fclose(fpIn);
	fclose(fpOut);

	return 0;
}

/*ÎÄ¼þ¿½±´1
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

	//¿½±´¹ý³Ì
	char ch = fgetc(fpIn);
	while (ch != EOF) //end of file
	{
		fputc(ch, fpOut);
		ch = fgetc(fpIn);//×Ô¶¯¶ÁÈ¡ÏÂÒ»¸ö×Ö·û
	 }
	fputc(ch, fpOut);

	fclose(fpIn);
	fclose(fpOut);

	return 0;
}
*/
/*¶þ½øÖÆ¶ÁÈë 
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
/*¶þ½øÖÆÐ´Èë
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
/*Ö»¶Á
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

/*Ö»Ð´
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
*/ÿ