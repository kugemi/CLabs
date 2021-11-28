//Матрица симметрия
#include<stdio.h>
#include<conio.h>
#include<locale.h>
#include<stdlib.h>
#include<malloc.h>

int main()
{
	setlocale(LC_ALL, "Russian");
	int line, column, arraySize, flag;
	int **array;

	do
	{
		printf("Введите размер матрицы (нечётное число): ");
		scanf_s("%d", &arraySize);
	} while (arraySize % 2 == 0);

	array = (int**)malloc(arraySize * sizeof(int));
	for (line = 0; line < arraySize; line++)
	{
		array[line] = (int*)malloc(arraySize * sizeof(int));
		for (column = 0; column < arraySize; column++)
		{
			printf("Введите элемент матрицы [%d][%d]: ", line, column);
			scanf_s("%d", &array[line][column]);
		}
	}
	printf("Матрица:\n");
	for (line = 0; line < arraySize; line++)
	{
		for (column = 0; column < arraySize; column++)
		{
			printf("%5d", array[line][column]);
		}
		printf("\n");
	}

	flag = 1;
	for (line = 0; line < arraySize / 2; line++)
	{
		for (column = 0; column < arraySize; column++)
		{
			if (array[line][column] != array[arraySize - 1 - line][column])
			{
				flag = 0;
				break;
			}
			if (flag == 0)
				break;
		}
	}
	if (flag == 1)
		printf("Матрица симметрична относительно горизонтали\n");
	else
		printf("Матрица не симметрична относительно горизонтали\n");

	flag = 1;
	for (line = 0; line < arraySize; line++)
	{
		for (column = 0; column < arraySize / 2; column++)
		{
			if (array[line][column] != array[line][arraySize - 1 - column])
			{
				flag = 0;
				break;
			}
			if (flag == 0)
				break;
		}
	}
	if (flag == 1)
		printf("Матрица симметрична относительно вертикали\n");
	else
		printf("Матрица не симметрична относительно вертикали\n");

	flag = 1;
	for (line = 0; line < arraySize / 2; line++)
	{
		for (column = 0; column < arraySize / 2; column++)
		{
			if (array[line][column] != array[arraySize - 1 - line][arraySize - 1 - column])
			{
				flag = 0;
				break;
			}
			if (flag == 0)
				break;
		}
	}
	if (flag == 1)
		printf("Матрица симметрична относительно центра\n");
	else
		printf("Матрица не симметрична относительно центра\n");
	_getch();
}