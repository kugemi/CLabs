#include<stdio.h>
#include<conio.h>
#include<locale.h>
#include<stdlib.h>
int main()
{
	setlocale(LC_ALL, "Rus");
	int kolvoObjectov = 0;
	int* ves;
	int* poleznost;
	unsigned int vmestimost, maxSumPoleznosti, sumVesa, sumPoleznosti, nomerObjecta, maxSumVesa;
	int mask = 1;
	vmestimost = maxSumPoleznosti = sumVesa = sumPoleznosti = nomerObjecta = maxSumVesa = 0;

	printf("Сколько предметов с собой возьмёшь, брат? ");
	while ((scanf_s("%d", &kolvoObjectov) != 1) || (kolvoObjectov <= 0) || (kolvoObjectov > 8)) {
		printf("Вы ввели не число!");
		while (getchar() != '\n');
	}
	ves = (int*)malloc(kolvoObjectov * sizeof(int));
	poleznost = (int*)malloc(kolvoObjectov * sizeof(int));
	printf("Введи вес и полезность, брат:\n");
	for (int index = 0; index < kolvoObjectov; index++) {
		printf("%d", index + 1);
		printf("\nвес, брат:");
		while ((scanf_s("%d", &ves[index]) != 1)) {
			printf("Не огорчай меня, брат, число введи, брат");
			while (getchar() != '\n');
		}
		printf("полезность, брат:");
		while ((scanf_s("%d", &poleznost[index]) != 1)) {
			printf("Не огорчай меня, брат, число введи, брат");
			while (getchar() != '\n');
		}
		printf("\n");
	}
	printf("Сколько вмещает твой ранец, брат? ");
	while ((scanf_s("%d", &vmestimost) != 1) || (vmestimost <= 0)) {
		printf("Неправда, брат, введи число, брат!");
		while (getchar() != '\n');
	}
	for (int index = 1; index < (1 << kolvoObjectov); index++) {
		for (int b = 0; b < kolvoObjectov; b++) {
			if (index & mask) {
				sumVesa += ves[b];
				sumPoleznosti += poleznost[b];
			}
			mask <<= 1;
		}
		if (sumVesa <= vmestimost)
			if (sumPoleznosti > maxSumPoleznosti) {
				maxSumPoleznosti = sumPoleznosti;
				nomerObjecta = index;
				maxSumVesa = sumVesa;
			}
		sumVesa = 0;
		sumPoleznosti = 0;
		mask = 1;
	}
	printf("\nВозьми их с собой, брат:\n\n");
	mask = 1;
	for (int kindex = 0; kindex <= 5; kindex++)
		if (nomerObjecta & (mask << kindex)) printf("%d ", kindex + 1);
	printf("\nсуммарная полезность, брат: %d", maxSumPoleznosti);
	printf("\nсуммарный вес, брат: %d", maxSumVesa);
	free(ves);
	free(poleznost);
	_getch();
}