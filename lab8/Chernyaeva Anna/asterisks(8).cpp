#include<stdio.h>
#include<conio.h>
#include<locale.h>
int main() {
	setlocale(LC_ALL, "Rus");
	int size = 0;
	int matrix[10][10] = { 0 };
	int horizontal, vertical, centre;
	horizontal = vertical = centre = 0;
	const char* check[3] = { "симметрична","НЕ симметрична" };
	printf("Соблаговалите ,сударь,ввести размер вашей матрици: ");
	while (((scanf_s("%d", &size)) == 0) || (size % 2 == 0)) {
		printf("Скорее всего вы не смогли найти цифры на клавиатуе или же попали не по тем цифрам, попробуйте снова: ");
		while (getchar() != '\n');
	}
	printf("Введите элементы матрицы(1-9)\n");
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++) {
			printf("matrix[%d][%d]=", i, j);
			while (scanf_s("%d", &matrix[i][j]) == 0) {
				printf("Вы ошиблись,сударь\nmatrix[%d][%d]=", i, j);
				while (getchar() != '\n');
			}
		}
	printf("\nВаша матрица,сударь:\n\n");
	for (int i = 0; i < size; i++) {
		printf("|");
		for (int j = 0; j < size; j++)
			printf("%d", matrix[i][j]);
		printf("|");
		printf("\n");
	}
	for (int i = 0; i < size; i++)
		for (int j = 0; j < (size / 2); j++) {
			if (matrix[j][i] != matrix[size - 1 - j][i])
				horizontal = 1;
			if (matrix[i][j] != matrix[i][size - 1 - j])
				vertical = 1;
			if ((matrix[j][i] != matrix[size - 1 - j][size - 1 - i]) || (matrix[j][size - 1 - i] != matrix[size - 1 - j][i]))
				centre = 1;
		}
	printf("\n\x03матрица %s относительно горизонтали", check[horizontal]);
	printf("\n\x03матрица %s относительно вертикали", check[vertical]);
	printf("\n\x03матрица %s относительно центра", check[centre]);
	_getche();
}
