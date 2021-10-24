#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<locale.h>
#include<time.h>

int main (void){
	setlocale(LC_ALL,"");

	int num, yournum, attemps,countatt;
	char answ;

	for (;;) {
		fflush(stdin);
		do {
			printf_s("Введите количество попыток: ");
			if (!scanf_s("%d", &attemps)) {
				printf_s("Вы ввели не число! ");
				attemps = getchar() == '\0';
			}
		} while ((attemps <= 0) || (attemps == '\0'));
		srand(time(0));
		num = rand() % 101;
		for (countatt = 1; countatt <= attemps; countatt++) {
			do {
				printf("Угадайте число: ");
				if (!scanf_s("%d", &yournum)) {
					printf_s("Вы ввели не число! ");
					yournum = getchar() == '\0';
				}
			} while ((yournum<0)||(yournum>100)||(yournum=='\0'));
			if (yournum == num) {
				printf_s("Вы угадали число %d с %d-ой попытки!\n", num, countatt);
				break;
			}
			if (countatt == attemps) {
				printf_s("Вы не уложились в %d попыток! Число %d\n", attemps, num);
				break;
			}
			else if (yournum < num) {
				printf_s("У вас осталось %d попыток. Попробуйте ещё раз. Ваше число меньше загаданного!\n", attemps - countatt);
			}
			else if (yournum > num) {
				printf_s("У вас осталось %d попыток. Попробуйте ещё раз. Ваше число больше загаданного!\n", attemps - countatt);
			}
		}
		printf_s("Продолжить игру? Y/N: ");
		answ = _getch();
		printf_s("\n\n");
		if ((answ == 'n') || (answ == 'N')) {
			break;
		}
		else if ((answ == 'Y') || (answ == 'y')) {
			continue;
		}
		return 0;
	}
}