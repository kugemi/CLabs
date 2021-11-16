#include <conio.h>
#include <stdio.h>
#include <locale.h>

int main(void) {
	setlocale(LC_ALL, "");

	unsigned short int chislo = 0;
	int peremen = 1;
	int Storona = 0;
	int sdvig = 0;

	do 
	{
		printf_s("Введите число от 0 до 65535(включительно):\n");
		if (scanf_s("%hu", &chislo)==0) 
		{
			printf_s("Введён символ!");
			getchar() != '\n';
		}
	} while ((chislo < 0) || (chislo > 65535));
	do 
	{
		printf_s("Введите число позиций сдвига:\n");
		if (!scanf_s("%d", &sdvig)) 
		{
			printf_s("Введён символ!");
			getchar() != '\n';
		}
	} while ((sdvig <= 0));
	do 
	{
		printf_s("Выберите сторону сдвига.(Вправо - 1, Влево - 0):\n");
		peremen = 1;
		if (!scanf_s("%d", &Storona))
		{
			peremen = 0;
			printf_s("Введён символ!");
			getchar() != '\n';
		}
	} while ((peremen == 0) || ((Storona != 0) && (Storona != 1)));
	printf_s("\n");

	printf_s("Исходное число: \nДесятичная запись: %d\nДвоичная запись: ", chislo);
	for (int index = 15; index >= 0; index--) {
		if ((chislo >> index) & 1) printf_s("1");
		else printf("0");
	}
	printf_s("\n\n");

	if (Storona == 1) {
		for (int i = 0; i < sdvig; i++) {
			if (chislo % 2 == 1) {
				chislo >>= 1;
				chislo += (1 << 15);
			}
			else chislo >>= 1;
		}
	}
	else {
		for (int i = 0; i < sdvig; i++) {
			if (chislo & 32768) {
				chislo <<= 1;
				chislo++;
			}
			else chislo <<= 1;
		}
	}

	printf_s("Число после сдвига: \nДесятичная запись: %d\nДвоичная запись: ", chislo);
	for (int index = 15; index >= 0; index--) {
		if ((chislo >> index) & 1) printf_s("1");
		else printf("0");
	}
	printf_s("\n");
	return 0;
}