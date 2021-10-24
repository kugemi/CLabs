
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <locale.h>
#include <conio.h>


void main()
{
	int min = 0;
	int number;
	char answer = 'a';
	int attempt = 1;
	int variant = 0;
	setlocale(LC_ALL, "Russian");
	printf("Я хочу сыграть с тобой в игру, хочешь ли ты этого? (y/n):");
	  do {
		answer = getchar();
		if ((answer != 'y') && (answer != 'n')) { printf(" Сейчас не понял\n"); }
		while (getchar() != '\n');
	 } while ((answer != 'y') && (answer != 'n'));

	 while (answer == 'y') {
		 srand(time(0));
		 number = min + rand() % (100+1);
		 printf("Чисто по секрету загаданное число( %i)\n", number);
		 for (attempt = 1; attempt < 11; attempt++) {
			 printf("%i: Введите число: ", attempt);
			 scanf_s("%i", &variant);
			 if (number > variant) { printf("Загаданное число побольше\n"); }
			 if (number < variant) { printf("Загаданное число поменьше\n"); }
			 if (number == variant) { printf("Ты угадал\nПопыток использовано: %i\n ", attempt); break; }
			 if (number != variant && attempt == 10) { printf("Неудачник, твои попытки кончились.Загаданное число= %i\n", number); }
		 }
		 printf("Продолжим нашу игру?(y/n):");
		 do {
			 scanf_s(" %c", &answer);
			 if ((answer != 'y') && (answer != 'n')) { printf(" Сейчас не понял\n"); }
			 while (getchar() != '\n');
		 } while ((answer != 'y') && (answer != 'n'));

	 }
	 
	 _getch();
}
