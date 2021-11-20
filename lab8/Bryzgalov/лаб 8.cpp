#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<locale.h>

int main(void) {
	setlocale(LC_ALL, "");

	int **matrix=NULL;
	int string = 0;
	int column = 0;
	int size = 5;
	int status = 1;
	int flag = 1;

	do{
		flag = 1;
		printf_s("Введите размер матрицы (NxN)(N-нечётное): ");
		if (!scanf_s("%d", &size)) {
			flag = 0;
			printf_s("Вы ввели не число! ");
			while ((getchar()) != '\n');
		}
	} while ((size <= 1) || (flag == 0) || (size % 2 == 0));
	matrix = (int**)malloc(size * sizeof(int));
	for (string = 0; string < size; string++) {
		matrix[string] = (int*)malloc(size * sizeof(int));
	}
	for (string = 0; string < size; string++) {
		for (column = 0; column < size; column++) {
			do {
				flag = 1;
				printf_s("Введите элемент матрицы(%d-я строка, %d-й столбец): ",string+1,column+1);
				if (!scanf_s("%d", &matrix[string][column])) {
					flag = 0;
					printf_s("Вы ввели не число! ");
					while ((getchar()) != '\n');
				}
			} while ((flag == 0) || (matrix[string][column] <= 0));
		}
	}
	printf_s("_______________________________\n");


	printf_s("Ваша матрица:\n");
	for (string = 0; string < size; string++) {
		for (column = 0; column < size; column++) {
			if (column % size == 0) printf("\n\n");
			printf_s("%-3d  ", matrix[string][column]);
		}
	}
	printf_s("\n_______________________________\n");


	for (string = 0; string <=size / 2; string++) {
		for (column = 0; column < size; column++) {
			if (matrix[string][column] != matrix[size - string-1][column]){
				status = 0;
				break;
			}
		}
		if (status == 0) break;
	}
	if (status != 0) {
		printf_s("Горизонтальная симметрия: да\n");
	}
	else {
		printf_s("Горизонтальная симметрия: нет\n");
	}
	status=1;


	for (column = 0; column < size / 2; column++) {
		for (string = 0; string < size; string++) {
			if (matrix[string][column] != matrix[string][size - column - 1]) {
				status = 0;
				break;
			}
		}
		if (status == 0) break;
	}
	if (status != 0) {
		printf_s("Вертикальная симметрия: да\n");
	}
	else {
		printf_s("Вертикальная симметрия: нет\n");
	}
	status = 1;


	for (string = 0; string <= size / 2; string++) {
		for (column = 0; column <= size / 2; column++) {
			if (matrix[string][column] != matrix[size - string - 1][size - column - 1]) {
				status = 0;
				break;
			}
		}
		if (status == 0) break;
	}
	if (status != 0) {
		printf_s("Центральная симметрия: да\n");
	}
	else {
		printf_s("Центральная симметрия: нет\n");
	}
}