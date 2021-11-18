#include<stdio.h>
#include<conio.h>
#include<locale.h>

int main(void) {
	setlocale(LC_ALL, "");

	int itemsWeight[30] = {0};
	int itemsValue[30] = {0};
	int capacity = 0;
	int num = 0;
	int maxValue = 0;
	int maxWeight = 0;
	int sumWeight = 0;
	int sumValue=0;
	int quant = 0;
	int mask = 1;
	int opimalMask = 1;
	int flag = 1;

	do {
		flag = 1;
		printf_s("Введите количество предметов : ");
		if (!scanf_s("%d", &quant)) {
			flag = 0;
			printf_s("Вы ввели не число! ");
			while ((getchar()) != '\n');
		}
	} while ((quant <= 0) || (flag == 0)||(quant>30));
	for (num = 0; num < quant; num++) {
		do {
			flag = 1;
			printf_s("Введите вес %d-го предмета: ", num + 1);
			if (!scanf_s("%d", &itemsWeight[num])) {
				flag = 0;
				printf_s("Вы ввели не число! ");
				while ((getchar()) != '\n');
			}
		} while ((itemsWeight[num] <= 0) || (flag == 0));
		do {
			flag = 1;
			printf_s("Введите полезность %d-го предмета: ", num + 1);
			if (!scanf_s("%d", &itemsValue[num])) {
				flag = 0;
				printf_s("Вы ввели не число! ");
				while ((getchar()) != '\n');
			}
		} while ((itemsValue[num] <= 0) || (flag == 0));
		printf_s("\n");
	}
	do {
		flag = 1;
		printf_s("Введите вместимость рюкзака: ");
		if (!scanf_s("%d", &capacity)) {
			flag = 0;
			printf_s("Вы ввели не число! ");
			while ((getchar()) != '\n');
		}
	} while ((capacity < 1) | (flag == 0));
	printf_s("________________________________\n");

	printf_s("Ваши предметы: \n");
	for (num = 0; num < quant; num++) {
		printf_s("Предмет %d: вес - %d    полезность - %d\n", num+1, itemsWeight[num], itemsValue[num]);
	}
	printf_s("________________________________\n");

	for (int i = 0; i < (1 << quant); i++) {
		for (num = 0; num < quant; num++) {
			if (i & mask) {
				sumWeight += itemsWeight[num];
				sumValue += itemsValue[num];
			}
			mask <<= 1;
		}
		if ((sumWeight <= capacity)&&(sumValue>maxValue)) {
			maxValue = sumValue;
			maxWeight = sumWeight;
			opimalMask = i;
		}
		sumValue = 0;
		sumWeight = 0;
		mask = 1;
	}

	printf_s("Оптимальнее всего взять предметы: ");
	for (int i = 0; i <capacity; i++) {
		if (opimalMask & (mask << i)) printf_s("%d, ", i+1);
	}
	printf_s("\nЦенность: %d\nВес: %d",maxValue,maxWeight);
	}