#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include<ctype.h>


int main()
{
	int min = 0;
	int number;
	char answer = 'Y';
	int attempt;
	int index;
	int variant = 0;
	setlocale(LC_ALL, "Russian");
	printf("Я хочу сыграть с тобой в игру, хочешь ли ты этого? (y/n):");
	do {
		answer = getchar();
		if (((answer != 'Y') && (answer != 'N')) && ((answer != 'y') && (answer != 'n'))) { printf(" Сейчас не понял\n"); }
		while (getchar() != '\n');
	} while (((answer != 'Y') && (answer != 'N')) && ((answer != 'y') && (answer != 'n')));

	while ((answer == 'Y') || (answer == 'y')) {
		printf("Введите количество попыток = ");
		scanf_s("%i", &attempt);
		srand(time(0));
		number = min + rand() % (100 + 1);
		printf("Чисто по секрету загаданное число( %i)\n", number);
		for (index = 1; index < attempt + 1; index++) {
			printf("%i: Введите число: ", index);
			scanf_s("%i", &variant);
			if (number > variant) { printf("Загаданное число побольше\n"); }
			if (number < variant) { printf("Загаданное число поменьше\n"); }
			if (number == variant) { printf("Ты угадал\nПопыток использовано: %i\n ", index); break; }
			if (number != variant && index == attempt) { printf("Неудачник, твои попытки кончились.Загаданное число =  %i\n", number); }
		}
		printf("Продолжим нашу игру?(y/n):");
		do {
			scanf_s(" %c", &answer);
			if (((answer != 'Y') && (answer != 'N')) && ((answer != 'y') && (answer != 'n'))) { printf(" Сейчас не понял\n"); }
			while (getchar() != '\n');
		} while (((answer != 'Y') && (answer != 'N')) && ((answer != 'y') && (answer != 'n')));

	}
	_getch();
}