#include <iostream>
#include <locale.h>
#include <conio.h>
#include<time.h>
#include <stdlib.h>
int main()
{
	setlocale(LC_ALL, "Russian");
	int dlina = 0;
	int proverPeremen = 0;
	int proverka = 0;
	int sovpodenia = 0;
	int matrica[100][100] = { 0 };
	do {
		printf("Введите размер матрицы= ");
		scanf_s("%i", &dlina);
	} while (dlina % 2 == 0);
	for (int x = 1; x <= dlina; x++)
	{
		for (int y = 1; y <= dlina; y++)
		{
			printf("matrix[%i][%i]= ", x, y);
			scanf_s("%i", &matrica[x][y]);
		}
	}
	proverPeremen = dlina+1;
	sovpodenia = dlina * dlina;

	for (int x = 1; x <= dlina; x++)
	{
		for (int y = 1; y <= dlina; y++)
		{
			if (matrica[x][y] == matrica[proverPeremen - x][y])
			{
				proverka++;
			}
		}
	}
	if (proverka == sovpodenia) { printf("Матрица симметрична по горизонтали\n"); }
	else { printf("Матрица несимметрична по горизонтали\n"); }

	proverka = 0;
	for (int x = 1; x <= dlina; x++)
	{
		for (int y = 1; y <= dlina; y++)
		{
			if (matrica[x][y] == matrica[x][proverPeremen - y])
			{
				proverka++;
			}
		}
	}
	if (proverka == sovpodenia) { printf("Матрица симметрична по вертикали\n"); }
	else { printf("Матрица несимметрична по вертикали\n"); }

	proverka = 0;
	for (int x = 1; x <= dlina; x++)
	{
		for (int y = 1; y <= dlina; y++)
		{
			if (matrica[x][y] == matrica[proverPeremen - x][proverPeremen - y])
			{
				proverka++;
			}
		}
	}
	if (proverka == sovpodenia) { printf("Матрица симметрична относительно центра \n"); }
	else { printf("Матрица несимметрична относительно центра\n"); }
}