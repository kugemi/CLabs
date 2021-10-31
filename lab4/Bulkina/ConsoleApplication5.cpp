//Отгадай число

#include<stdio.h>
#include<conio.h>
#include<locale.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	setlocale(LC_ALL, "Russian");
	int randomNumber, enteredNumber, numberOfAttempts, index;
	char answer;
	srand(time(NULL));

	do
	{
		randomNumber = 0 + rand() % (100 - 0 + 1);
		//printf("%d\n", x);

		printf("Начало игры\n");
		printf("Введите количество попыток: ");
		scanf_s("%d", &numberOfAttempts);

		for (index = 1; index <= numberOfAttempts; index++)
		{
			printf("Введите число: ");
			scanf_s("%d", &enteredNumber);
			if (enteredNumber == randomNumber)
			{
				printf("Правильно! %d  - загаданное число\n", randomNumber);
				printf("Количество попыток, за которoе число было угадно: %d\n", index);
				break;
			}
			else
			{
				printf("Подсказка: ");
				if (enteredNumber > randomNumber)
					printf("Загаданное число меньше, чем введённое\n");
				else
					printf("Загаданное число больше, чем введённое\n");
			}
		}

		if (enteredNumber != randomNumber)
			printf("Загаданным числом было: %d\n", randomNumber);

		printf("Продолжить игру Y/N?\n");
		answer = _getche();
		printf("\n");
		if (answer == 'y' || answer == 'Y')
			printf("Новая игра\n");
		else
		{
			if (enteredNumber == randomNumber)
				printf("Число угадано");
			else
				printf("Количество попыток исчерпано");
		}	
	} 
	while (answer != 'n' && answer != 'N');
}