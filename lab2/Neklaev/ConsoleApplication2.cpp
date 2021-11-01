#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include<ctype.h>


int main()
{
	char otvet = 'Y';
	int popitka, chislo, index, variant;
	setlocale(LC_ALL, "Russian");
	printf("Игра начинается\n");
	while ((otvet == 'Y') || (otvet == 'y')) {
		printf("Введите количество попыток = ");
		scanf_s("%i", &popitka);
		srand(time(0));
		chislo = 0 + rand() % (100 + 1);
		for (index = 1; index < popitka + 1; index++) {
			printf("%i: Угадайте число: ", index);
			scanf_s("%i", &variant);
			if (chislo > variant) { printf("Загаданное число больше введённого\n"); }
			if (chislo < variant) { printf("Загаданное число меньше введённого\n"); }
			if (chislo == variant) { printf("Ты угадал\nПопыток использовано: %i\n ", index); break; }
			if (chislo != variant && index == popitka) { printf("Попытки закончились. Загаданное число =  %i\n", chislo); }
		}
	printf("Сыграем ещё раз?(y/n):");
	do {
		scanf_s(" %i", &otvet);
		otvet = getchar();
		if ((otvet != 'Y') && (otvet != 'N') && (otvet != 'y') && (otvet != 'n')) { printf(" Недопустимый ответ\n"); }
		while (getchar() != '\n');
	} while (((otvet != 'Y') && (otvet != 'N')) && ((otvet != 'y') && (otvet != 'n')));
	

	}
	_getch();
}