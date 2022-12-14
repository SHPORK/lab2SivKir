#include "stdio.h"
#include "stdlib.h"
#include "time.h"

int main(void)
{
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);

	clock_t start, end; // объявляем переменные для определения времени выполнения

	const int size = 4000; // размер матрицы size x size
	int i = 0, j = 0, r;
	int elem_c;

	int** a = (int**)malloc(size * sizeof(int*));
	int** b = (int**)malloc(size * sizeof(int*));
	int** c = (int**)malloc(size * sizeof(int*));
	for (int k = 0; k < size; k++) {
		a[k] = (int*)malloc(size * sizeof(int));
		b[k] = (int*)malloc(size * sizeof(int));
		c[k] = (int*)malloc(size * sizeof(int));
	}


	srand(time(NULL)); // инициализируем параметры генератора случайных чисел
	while (i < size)
	{
		while (j < size)
		{
			a[i][j] = rand() % 100 + 1; // заполняем массив случайными числами
			j++;
		}
		i++;
	}
	
	srand(time(NULL)); // инициализируем параметры генератора случайных чисел
	i = 0; j = 0;
	while (i < size)
	{
		while (j < size)
		{
			b[i][j] = rand() % 100 + 1; // заполняем массив случайными числами
			j++;
		}
		i++;
	}
	

	start = clock();
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			elem_c = 0;
			for (r = 0; r < size; r++)
			{
				elem_c = elem_c + a[i][r] * b[r][j];
				c[i][j] = elem_c;
				//printf("%d",elem_c);
			}
		}
	}
	end = clock();
	printf("Time - %f", (double)(end - start) / CLOCKS_PER_SEC);
	getchar();
	return(0);
}