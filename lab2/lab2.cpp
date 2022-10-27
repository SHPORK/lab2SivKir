#include "stdio.h"
#include "stdlib.h"
#include "time.h"


void shell(int* items, int count)
{
	int i, j, gap, k;
	int x, a[5];

	a[0] = 9; a[1] = 5; a[2] = 3; a[3] = 2; a[4] = 1;

	for (k = 0; k < 5; k++) {
		gap = a[k];
		for (i = gap; i < count; ++i) {
			x = items[i];
			for (j = i - gap; (x < items[j]) && (j >= 0); j = j - gap)
				items[j + gap] = items[j];
			items[j + gap] = x;
		}
	}
}

void qs(int* items, int left, int right) //вызов функции: qs(items, 0, count-1);
{
	int i, j;
	int x, y;

	i = left; j = right;

	/* выбор компаранда */
	x = items[(left + right) / 2];

	do {
		while ((items[i] < x) && (i < right)) i++;
		while ((x < items[j]) && (j > left)) j--;

		if (i <= j) {
			y = items[i];
			items[i] = items[j];
			items[j] = y;
			i++; j--;
		}
	} while (i <= j);

	if (left < j) qs(items, left, j);
	if (i < right) qs(items, i, right);
}

int compare(const void* x1, const void* x2)   // функция сравнения элементов массива
{
	return (*(int*)x1 - *(int*)x2);              // если результат вычитания равен 0, то числа равны, < 0: x1 < x2; > 0: x1 > x2
}

int main(void) {
	const int size = 55000;
	int i = 0;
	clock_t start, end; // объявляем переменные для определения времени выполнения


	int* M_rand_shell = (int*)malloc(size * sizeof(int));
	int* M_rand_qs = (int*)malloc(size * sizeof(int));
	int* M_rand_qsort = (int*)malloc(size * sizeof(int));
	int* M_increase_shell = (int*)malloc(size * sizeof(int));
	int* M_increase_qs = (int*)malloc(size * sizeof(int));
	int* M_increase_qsort = (int*)malloc(size * sizeof(int));
	int* M_decrease_shell = (int*)malloc(size * sizeof(int));
	int* M_decrease_qs = (int*)malloc(size * sizeof(int));
	int* M_decrease_qsort = (int*)malloc(size * sizeof(int));
	int* M_increase_decrease_shell = (int*)malloc(size * sizeof(int));
	int* M_increase_decrease_qs = (int*)malloc(size * sizeof(int));
	int* M_increase_decrease_qsort = (int*)malloc(size * sizeof(int));

	srand(time(NULL)); // инициализируем параметры генератора случайных чисел
	// заполнение массивов
	while (i < size)
	{
		if (M_rand_shell && M_rand_qs && M_rand_qsort) {
			M_rand_shell[i] = M_rand_qs[i] = M_rand_qsort[i] = rand() % 100 + 1; // заполняем массив случайными числами
			i++;
		}
	}
	i = 0;
	while (i < size)
	{
		if (M_increase_shell && M_increase_qs && M_increase_qsort) {
			M_increase_shell[i] = M_increase_qs[i] = M_increase_qsort[i] = i; // заполняем массив возрастающими числами
			i++;
		}
	}
	i = 0;
	while (i < size)
	{
		if (M_decrease_shell && M_decrease_qs && M_decrease_qsort) {
			M_decrease_shell[i] = M_decrease_qs[i] = M_decrease_qsort[i] = size - i - 1; // заполняем массив убывающими числами
			i++;
		}
	}
	i = 0;
	while (i < (size / 2))
	{
		if (M_increase_decrease_shell && M_increase_decrease_qs && M_increase_decrease_qsort) {
			M_increase_decrease_shell[i] = M_increase_decrease_qs[i] = M_increase_decrease_qsort[i] = i; // заполняем массив возр числами
			i++;
		}
	}
	while (i < size)
	{
		if (M_increase_decrease_shell && M_increase_decrease_qs && M_increase_decrease_qsort) {
			M_increase_decrease_shell[i] = M_increase_decrease_qs[i] = M_increase_decrease_qsort[i] = size - i; // заполняем массив убывающими числами
			i++;
		}
	}
	//----------------------
	//рандомныый массив
	printf("Rand\n");
	start = clock();
	shell(M_rand_shell, size);
	end = clock();
	printf("Shell - %f\n", (double)(end - start) / CLOCKS_PER_SEC);
	free(M_rand_shell);

	start = clock();
	qs(M_rand_qs, 0, size - 1);
	end = clock();
	printf("qs - %f\n", (double)(end - start) / CLOCKS_PER_SEC);
	free(M_rand_qs);

	start = clock();
	qsort(M_rand_qsort, size, sizeof(int), compare);
	end = clock();
	printf("qsort - %f\n\n", (double)(end - start) / CLOCKS_PER_SEC);
	free(M_rand_qsort);
	//-------------------------
	//возрастающий массив
	printf("Increase\n");
	start = clock();
	shell(M_increase_shell, size);
	end = clock();
	printf("Shell - %f\n", (double)(end - start) / CLOCKS_PER_SEC);
	free(M_increase_shell);

	start = clock();
	qs(M_increase_qs, 0, size - 1);
	end = clock();
	printf("qs - %f\n", (double)(end - start) / CLOCKS_PER_SEC);
	free(M_increase_qs);

	start = clock();
	qsort(M_increase_qsort, size, sizeof(int), compare);
	end = clock();
	printf("qsort - %f\n\n", (double)(end - start) / CLOCKS_PER_SEC);
	free(M_increase_qsort);
	//-------------------------
	//убывающий массив
	printf("Decrease\n");
	start = clock();
	shell(M_decrease_shell, size);
	end = clock();
	printf("Shell - %f\n", (double)(end - start) / CLOCKS_PER_SEC);
	free(M_decrease_shell);

	start = clock();
	qs(M_decrease_qs, 0, size - 1);
	end = clock();
	printf("qs - %f\n", (double)(end - start) / CLOCKS_PER_SEC);
	free(M_decrease_qs);

	start = clock();
	qsort(M_decrease_qsort, size, sizeof(int), compare);
	end = clock();
	printf("qsort - %f\n\n", (double)(end - start) / CLOCKS_PER_SEC);
	free(M_decrease_qsort);
	//-------------------------
	//возрастающий-убывающий массив
	printf("Increase-decrease\n");
	start = clock();
	shell(M_increase_decrease_shell, size);
	end = clock();
	printf("Shell - %f\n", (double)(end - start) / CLOCKS_PER_SEC);
	free(M_increase_decrease_shell);

	
	start = clock();
	qsort(M_increase_decrease_qsort, size, sizeof(int), compare);
	end = clock();
	printf("qsort - %f\n", (double)(end - start) / CLOCKS_PER_SEC);
	//-------------------------


	getchar();
	return(0);
}
