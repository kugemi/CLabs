#include <conio.h>
#include <stdio.h>
#include <locale.h>

int main(void) {
	setlocale(LC_ALL, "");

	unsigned short int num = 0;
	int direction = 0;
	int shift = 0;
	int flag = 1;

	do {
		printf_s("Введите ваше чило (положительное и меньше 65535): ");
		flag = 1;
		if (!scanf_s("%hu", &num)) {
			flag = 0;
			printf_s("Введите число ещё раз!");
			while ((getchar()) != '\n');
		}
	} while ((flag == 0) || (num <= 0) || (num > 65535));
	do {
		printf_s("Введите число позиций сдвига: ");
		flag = 1;
		if (!scanf_s("%d", &shift)) {
			flag = 0;
			printf_s("Введите число ещё раз!");
			while ((getchar()) != '\n');
		}
	} while ((flag == 0) || (shift <= 0));
	do {
		printf_s("В какую сторону производить сдвиг?(Право - 1, Лево - 0): ");
		flag = 1;
		if (!scanf_s("%d", &direction)) {
			flag = 0;
			printf_s("Введите ещё раз!");
			while ((getchar()) != '\n');
		}
	} while ((flag == 0) || ((direction != 0) && (direction != 1)));
	printf_s("\n\n");

	printf_s("Исходное число: \nДесятичная запись: %d\nДвоичная запись: ", num);
	for (int index = 15; index >= 0; index--) {
		if ((num >> index) & 1) printf_s("1");
		else printf("0");
	}
	printf_s("\n\n");

	if (direction == 1) {
		for (int i = 0; i < shift; i++) {
			if (num % 2 == 1) {
				num >>= 1;
				num += (1 << 15);
			}
			else num >>= 1;
		}
	}
	else {
		for (int i = 0; i < shift; i++) {
			if (num & 32768) {
				num <<= 1;
				num++;
			}
			else num <<= 1;
		}
	}

	printf_s("Число после сдвига: \nДесятичная запись: %d\nДвоичная запись: ", num);
	for (int index = 15; index >= 0; index--) {
		if ((num >> index) & 1) printf_s("1");
		else printf("0");
	}
	printf_s("\n\n");
	return 0;
}