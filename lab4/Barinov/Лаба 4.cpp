#include<stdio.h>
#include<conio.h>
#include<locale.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	setlocale(LC_ALL, "Rus");
	int randomNum, NumTries, enteredNum, index;
	char answer;
	srand(time(NULL));
	
	do
	{
		randomNum = 0 + rand() % (100 - 0 + 1);
		printf("Компьютер загадал число от 0 до 100\n");
		printf("Начнем игру\n");
		printf("Введите количество попыток: ");
		scanf_s("%d", &NumTries);
		
		for (index = 1; index <= NumTries; index++)
		{
			printf("Введите число: ");
			scanf_s("%d", &enteredNum);
			if (enteredNum == randomNum)
			{
				printf("Поздравляю! %d  - загаданное число\n", randomNum);
				printf("Вам понадобилось попыток: %d\n", index);
				break;
			}
			else
			{
				printf("Подсказка: ");
				if (enteredNum > randomNum)
					printf("Загаданное число меньше, попробуй снова\n");
				else
					printf("Загаданное число больше, попробуй снова\n");
			}
		}

		if (enteredNum != randomNum)
			printf("Компьютер загадал: %d\n", randomNum);

		printf("Продолжить игру Yes/No?\n");
		answer = _getche();
		printf("\n");
		if (answer == 'y' || answer == 'Y')
			printf("Новая игра\n");
		else
		{
			if (enteredNum == randomNum)
				printf("Число угадано\n");
			else
				printf("Ваши попытки закончились\n");
		}
	} while (answer != 'n' && answer != 'N');
}