/*угадайка:)*/
#include<stdio.h>
#include<conio.h>
#include<locale.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>

void main()
{
	setlocale(LC_ALL, "Russian");
	int enteredNumber;
	int randomNumber;
	int numberOfAttempts;
	int i;
	char n='Y';
	srand(time(0));
	while (n=='Y')
	{
		randomNumber = (rand() % 100) + 1;
		printf("Введите количество попыток: \n");
		while (((scanf_s("%d", &numberOfAttempts)) != 1) || (numberOfAttempts) <= 0)
		{
			printf("неверно введенное число, попробуйте снова: \n");
			while (getchar() != '\n');
		}
		printf("Введите число: ");
		for (i = 0; i < numberOfAttempts; i++)
		{
			while ((scanf_s("%d", &enteredNumber)) == 0) {
				printf("\nНеверно введенное значение, попробуйте снова: ");
				while (getchar() != '\n');
			}
			if (enteredNumber == randomNumber)
			{
				printf("\nВы угадали!\nКоличество использованных попыток: %d", i + 1);
				printf("\n\nХотите продолжить игру(Y/N)?\n");
				n =_getch();
				n = toupper(n);
				printf("\n");
				_getche();
				break;
			}
			if (i == (numberOfAttempts - 1))
			{
				printf("\nПопытки кончились, вы не угадали:(");
				printf("\nЗагаданное число-%d", randomNumber);
				printf("\n\nХотите продолжить игру(Y/N)?\n");
				n = _getch();
				n = toupper(n);
				printf("\n");
				_getche();
				break;
			}
			if (enteredNumber > randomNumber)
				printf("\nВведенное число больше, попробуйте снова:  ");
			if (enteredNumber < randomNumber)
				printf("\nВведенное число меньше, попробуйте снова:  ");


		}
	}
}