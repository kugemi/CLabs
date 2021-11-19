#include <iostream>
#include <locale.h>
#include <conio.h>
#include <stdio.h>

int main()
{
	setlocale(LC_ALL, "russian");
	int inputArray[100][100] = { 0 };
	int size = 0;
	int trigger = 0;
	printf("Введите размер таблицы, размер должен быть нечетным:");
	scanf_s("%d", &size);
	printf("В каждой строке чисел:%d\n", size);
	for (int i = 0; i < size; i++)
	{
		printf("Введите %d-ую строку:", i + 1);
		for (int j = 0; j < size; j++)
		{
			scanf_s("%d", &inputArray[i][j]);
		}
	}

	for (int i = 0; i < size / 2; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (inputArray[size - 1 - i][j] != inputArray[i][j]) trigger = 1;
		}
	}
	if (trigger == 0) printf("Матрица симметрична относительно горизонтали\n");
	else if (trigger == 1) printf("Матрица не симметрична относительно горизонтали\n");
	trigger = 0;

	for (int i = 0; i < size / 2; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (inputArray[i][size - 1 - j] != inputArray[i][j]) trigger = 1;
		}
	}
	if (trigger == 0) printf("Матрица симметрична относительно вертикали\n");
	else if (trigger == 1) printf("Матрица не симметрична относительно вертикали\n");
	for (int i = 0; i < size / 2; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (inputArray[size - 1 - i][size - 1 - j] != inputArray[i][j]) trigger = 1;
		}
	}
	if (trigger == 0) printf("Матрица симметрична относительно центра");
	else if (trigger == 1) printf("Матрица не симметрична относительно центра");
}