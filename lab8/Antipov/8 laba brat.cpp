#include <locale.h>
#include <conio.h>
#include <stdio.h>
int main()
{
	setlocale(LC_ALL, "Russian");
	int matrix[10][10] = { 0 };
	int dlina = 0;
	int k = 0;
	int check = 0;
	int sovpadenie = 0;
	do {
		printf("Введи размеры матрицы, брат ");
		scanf_s("%в", &dlina);
	} while (dlina % 2 == 0);
	for (int s = 0; s < dlina; s++)
	{
		for (int t = 0; t < dlina; t++)
		{
			do {
				printf("матрица[%i][%i]= ", s, t);
				scanf_s("%d", &matrix[s][t]);
			} while (matrix[s][t] > 32767 || matrix[s][t] < -32767);
		}
	}
	printf("\nТвоя матрица, брат\n\n");
	for (int i = 0; i < dlina; i++) {
		for (int j = 0; j < dlina; j++)
			printf("%d", matrix[i][j]);
		printf("\n");
	}
	k = dlina - 1;
	sovpadenie = dlina * dlina;

	for (int s = 0; s < dlina; s++)
	{
		for (int t = 0; t < dlina; t++)
		{
			if (matrix[s][t] == matrix[k - s][t])
			{
				check++;
			}
		}
	}
	if (check == sovpadenie) { printf("\nМатрица симметрична по горизонтали, брат\n"); }
	else { printf("\nМатрица не симметрична по горизонтали, брат\n"); }

	check = 0;
	for (int s = 0; s < dlina; s++)
	{
		for (int t = 0; t < dlina; t++)
		{
			if (matrix[s][t] == matrix[s][k - t])
			{
				check++;
			}
		}
	}
	if (check == sovpadenie) { printf("Матрица симметрична по вертикали, брат\n"); }
	else { printf("Матрица не симметрична по вертикали, брат\n"); }

	check = 0;
	for (int s = 0; s < dlina; s++)
	{
		for (int t = 0; t < dlina; t++)
		{
			if (matrix[s][t] == matrix[k - s][k - t])
			{
				check++;
			}
		}
	}
	if (check == sovpadenie) { printf("Матрица симметрична по центру, брат \n"); }
	else { printf("Матрица не симметрична по центру, брат\n"); }
}