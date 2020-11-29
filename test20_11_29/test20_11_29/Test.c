#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<malloc.h>

#define ROW 5
#define COW 5

int main()
{
	int **par = NULL;
	par = (int**)malloc(sizeof(int*)*ROW);
	if (NULL == par)
	{
		return;
	}
	for (int i = 0; i < ROW; i++)
	{
		*(par+i) = (int*)malloc(sizeof(int)*COW);
		if (NULL == *(par + i))
		{
			return;
		}
	}

	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COW; j++)
		{
			par[i][j] = i * j;
		}
	}

	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COW; j++)
		{
			printf("%d \n", par[i][j]);
		}
	}

	for (int i = 0; i < ROW; i++)
	{
		free(*(par + i));
	}
	free(par);

	return 0;
}

/*
int main()
{
	int *ar = (int *)malloc(sizeof(int) * 5);


	return 0;
}
*/
/*
int main()
{
	int input, n;
	int count = 0;
	int* numbers = NULL;
	int* more_numbers = NULL;

	do {
		printf("Enter an integer value (0 to end): ");
		scanf_s("%d", &input);
		count++;

		more_numbers = (int*)realloc(numbers, count * sizeof(int));

		if (more_numbers != NULL) {
			numbers = more_numbers;
			numbers[count - 1] = input;
		}
		else {
			free(numbers);
			puts("Error (re)allocating memory");
			exit(1);
		}
	} while (input != 0);

	printf("Numbers entered: ");
	for (n = 0; n < count; n++) printf("%d ", numbers[n]);
	free(numbers);

	return 0;
}
*/