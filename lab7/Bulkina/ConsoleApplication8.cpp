#include<stdio.h>
#include<conio.h>
#include<locale.h>

int main()
{
	setlocale(LC_ALL, "Russian");
	unsigned int capacity, itemNumber, mask, sumWeight, sumValue, maxSumValue, maxSumWeight;
	unsigned int weight[100] = { 0 };
	unsigned int value[100] = { 0 };
	int index, index2, quantity;
	maxSumValue = maxSumWeight = sumWeight = sumValue = quantity = capacity = itemNumber = 0;
	mask = 1;
	
	printf("Введите вместимость ранца: ");
	scanf_s("%d", &capacity);
	printf("Введите количество предметов: ");
	scanf_s("%d", &quantity);
	printf("---------------------------------\n");
	for (index = 1; index <= quantity; index++)
	{	
		printf("\n");
		printf("Введите вес %d предмета: ", index);
		scanf_s("%d", &weight[index]);
		printf("Введите его ценность: ");
		scanf_s("%d", &value[index]);
	}
	printf("\n---------------------------------\n");

	for (index = 1; index < (1 << quantity); index++)
	{
		for (index2 = 1; index2 <= quantity; index2++)
		{
			if (index & mask)
			{
				sumWeight += weight[index2];
				sumValue += value[index2];
			}
			mask = mask << 1;
		}
		if (sumWeight <= capacity)
			if (sumValue > maxSumValue)
			{
				maxSumValue = sumValue;
				itemNumber = index;
				maxSumWeight = sumWeight;
			}
		sumWeight = 0;
		sumValue = 0;
		mask = 1;
	}
	printf("Положить в ранец следует предметы: ");
	mask = 1;
	for (index = 1; index <= quantity; index++)
	{
		if (itemNumber & mask)
			printf("%d ", index);
		mask = mask << 1;
	}
		
	printf("\nСуммарный вес предметов: %d", maxSumWeight);
	printf("\nСуммарная ценность предметов: %d", maxSumValue);
	_getch();
}