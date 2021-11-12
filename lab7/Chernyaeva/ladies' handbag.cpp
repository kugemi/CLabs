#include<stdio.h>
#include<conio.h>
#include<locale.h>

int main()
{
	setlocale(LC_ALL, "Rus");
	const char* object[8] = { "резинка","гигиеничка","пленочный фотоаппарат","студенческий","ежедневник","маска","зарядка","наушники" };
	unsigned int weight[8] = { 0 };
	unsigned int significance[8] = { 0 };
	int numberOfObjects = 0;
	unsigned int capacity, maxSumSignificance, sumWeight, sumSignificance, objectIndexes, maxSumWeight;
	int mask = 1;
	capacity = maxSumSignificance = sumWeight = sumSignificance = objectIndexes = maxSumWeight = 0;
	printf("Сколько предметов поместится в вашу сумочку? --> ");
	while ((scanf_s("%d", &numberOfObjects) != 1) || (numberOfObjects <= 0) || (numberOfObjects > 8)) {
		printf("!Проверьте корректность введенных данных и попробуйте снова!");
		while (getchar() != '\n');
	}
	printf("\nвведите вес и ценность предметов:\n");
	for (int i = 0; i < numberOfObjects; i++) {
		printf("%d)%s", i + 1, object[i]);
		printf("\nвес:");
		while ((scanf_s("%d", &weight[i]) != 1)) {
			printf("!Проверьте корректность введенных данных и попробуйте снова!");
			while (getchar() != '\n');
		}
		printf("ценность:");
		while ((scanf_s("%d", &significance[i]) != 1)) {
			printf("!Проверьте корректность введенных данных и попробуйте снова!");
			while (getchar() != '\n');
		}
		printf("\n");
	}
	printf("Какова вместимость вашей сумочки? --> ");
	while ((scanf_s("%d", &capacity) != 1) || (capacity <= 0)) {
		printf("!Проверьте корректность введенных данных и попробуйте снова!");
		while (getchar() != '\n');
	}
	printf("--------------------------------");
	for (int i = 1; i < (1<< numberOfObjects); i++) {
		for (int b = 0; b <numberOfObjects; b++) {
			if (i & mask) {
				sumWeight += weight[b];
				sumSignificance += significance[b];
			}
			mask <<= 1;
		}
		if (sumWeight <= capacity)
			if (sumSignificance > maxSumSignificance) {
				maxSumSignificance = sumSignificance;
				objectIndexes = i;
				maxSumWeight = sumWeight;
			}
		sumWeight = 0;
		sumSignificance = 0;
		mask = 1;
	}
	printf("\nПредметы,которые вам следует взять с собой:\n\n");
	mask = 1;
	for (int i = 7; i >= 0; i--)
		if (objectIndexes & (mask << i)) printf("\x03%s\n\n", object[i]);
	printf("------------------------\n");
	printf("суммарная ценность: %d", maxSumSignificance);
	printf("\nсуммарный вес: %d", maxSumWeight);
	_getch();
}