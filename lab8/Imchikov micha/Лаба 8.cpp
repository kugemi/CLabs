#include <iostream>
#include <locale.h>
#include <conio.h>
#include<time.h>
#include <stdlib.h>
int main()
{
	int matrix[100][100] = { 0 };
	int length=0;// длинна 
	int size=0;// вспомогательная переменная
	int check=0;// проверка на совпадаемость значений
	int coincidence=0;// необходимое кол-во совпадений
	do{
	printf("Enter the size of the square matrix= ");
	scanf_s("%i", &length);
	} while (length % 2 == 0);
	for (int s = 0; s < length; s++)
	{
		for (int t = 0; t < length; t++)
		{
			do {
				printf("matrix[%i][%i]= ", s, t);
				scanf_s("%i", &matrix[s][t]);
			} while (matrix[s][t]>32767 || matrix[s][t] <-32767);
		}
	}
	size = length - 1;
	coincidence = length * length;

	for (int s = 0; s < length; s++)
	{
		for (int t = 0; t < length; t++)
		{
			if(matrix[s][t]==matrix[size-s][t])
			{
				check++;
			}
		}
	}
	if (check == coincidence) { printf("The matrix is symmetrical horizontally\n");}
	else { printf("The matrix is NOT symmetrical horizontally\n"); }

	check = 0;
	for (int s = 0; s < length; s++)
	{
		for (int t = 0; t < length; t++)
		{
			if (matrix[s][t] == matrix[s][size-t])
			{
				check++;
			}
		}
	}
	if (check == coincidence) { printf("The matrix is symmetrical vertically\n"); }
	else { printf("The matrix is NOT symmetrical vertically\n"); }

	check = 0;
	for (int s = 0; s < length; s++)
	{
		for (int t = 0; t < length; t++)
		{
			if (matrix[s][t] == matrix[size - s][size-t])
			{
				check++;
			}
		}
	}
	if (check == coincidence) { printf("The matrix is symmetrical in the center \n"); }
	else { printf("The matrix is NOT symmetrical in the center\n"); }
}