#include <iostream>
#include <stdio.h>
#include<conio.h>
#include<locale.h>
#include<cmath>
int main()
{
	setlocale(LC_ALL,"Russian");
	int Number = 0;
	int Tonnage = 0;
	int mask = 1;
	int maxValue = 0;
	int position = 0;
	int indexWeight = 0;
	int indexValue = 0;
	printf("Введите количество предметов и грузоподъемность: ");
	scanf_s("%d %d",&Number,&Tonnage);
	printf("\n");
	int* arrayWeight = new int[Number];
	int* arrayValue = new int[Number];
	for (int index = 0; index < Number; index++) {
		arrayWeight[index] = 0;
		arrayValue[index] = 0;
		printf("Введите вес и полезность %d предмета: ",index+1);
		scanf_s("%d %d", &arrayWeight[index], &arrayValue[index]);
		printf("\n");
	}
	for (int indexMask = 0; indexMask < pow(2, Number); indexMask++) {
		indexValue = 0;
		indexWeight = 0;
		for (int indexNumber = 0; indexNumber < Number; indexNumber++) {
			if (mask & indexMask) {
				indexWeight += arrayWeight[indexNumber];
				indexValue += arrayValue[indexNumber];
			}
			mask <<= 1;
		}
		if ((indexValue > maxValue) && (indexWeight < Tonnage)) {
			maxValue = indexValue;
			position = indexMask;
		}
		mask = 1;
	}
	printf("Вам нужно взять предметы под номерами: ");
	for (int res = 0; res <= Number; res++)
	{
		if (mask & position) printf("%d ", res + 1);
		mask <<= 1;
	}
	printf("\nМаксимальная полезность: %d", maxValue);
}

