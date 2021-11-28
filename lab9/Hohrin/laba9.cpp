#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
int main()
{
	setlocale(LC_ALL, "russian");
	int amount, mini, minj, min, count1, count2, amount2, sum = 0;
	count1 = 0;
	min = 100000;
	int mins[100] = { 0 };
	int matrix[100][2] = {0};
	printf("Введите количество деталей:");
	scanf_s("%d", &amount);
	amount2 = amount;
	for (int i = 0; i < amount; i++)

	{
		printf("Введите время обработки детали на первом и втором станке:");
		for (int j = 0; j < 2; j++)
		{

			scanf_s("%d", &matrix[i][j]);
		}
	}

	count2 = amount;
	for (int a = 0; a < amount; a)
	{
		min = 100000;
		mini = minj = 0;
		for (int i = 0; i < amount; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				if (matrix[i][j] < min)
				{
					min = matrix[i][j];
					mini = i;
					minj = j;

				}
			}
		}
		if (minj == 0)
		{
			mins[count1] = min;
			count1++;
		}
		else if (minj == 1)
		{
			mins[count2 - 1] = min;
			count2--;
		}
		for (int b = mini; b < amount; b++)
		{
			matrix[b][0] = matrix[b + 1][0];
			matrix[b][1] = matrix[b + 1][1];
		}
		amount--;
	}
	for (int i = 0; i < amount2; i++)
	{
		sum += mins[i];
		printf("%d", mins[i]);
	}
	printf("\nОбщее время обработки:%d", sum);

}
