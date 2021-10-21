#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	setlocale(LC_ALL, "Rus");
	int systemNumber, userNumber, attempt = 10, iTry;
	char exitButton;

	for (iTry = 0; iTry < 33; iTry++) printf(" ");
	printf("Приветствуем!\n");
	for (iTry = 0; iTry < 16; iTry++) printf(" ");
	printf("Это \"Шоу интуиция\", где Вы проверите свои силы\n");
	for (iTry = 0; iTry < 9; iTry++) printf(" ");
	printf("ясновидящего и попробуйте отгадать заданное компьютером число!\n\n");
	for (iTry = 0; iTry < 14; iTry++) printf(" ");
	printf("Вам будет дано всего 10 попыток! Будьте внимательны!\n\n");

	do
	{
		srand(time(0));
		systemNumber = rand() % 100 + 1;

		//printf("Число, заданное системой %d\n\n", systemNumber);

		for (iTry = 1; iTry <= attempt; iTry++)
		{
			printf("\n--- Попытка № %d\n", iTry);
			printf("  Вы думаете, что это число ... ");
			if (scanf_s("%d", &userNumber) == false)
			{
				getchar() != '\0';
				break;
			}

			if (userNumber > systemNumber) printf("\n |Х| Но нет, Ваше число выше заданного\n");
			else if (userNumber < systemNumber) printf("\n |Х| Но к сожалению, ваше число ниже заданного\n");
			else if (userNumber = systemNumber)
			{
				printf("\n |V| И правильно думаете! Это действительно число %d !\n", systemNumber);  
				printf("----------------------------------------------\n");
				if (iTry == 1) printf("  Вы угадали загаданное число за %d попытку!\n", iTry);
				if (iTry >= 2 && iTry <= 4) printf("  Вы угадали загаданное число за %d попытки!\n", iTry);
				if (iTry >= 5 && iTry <= 10) printf("  Вы угадали загаданное число за %d попыток!\n", iTry);
				break;
			}
			if (iTry == attempt)
			{
				printf("---------------------------------------\n");
				printf("\nУпс! Вы потратили все свои попытки :(\n\n");
			}
		}
		printf("|------------------------------------------------------------|\n");
		printf("|                         Продолжить?                        |\n");
		printf("|                                                            |\n");
		printf("|                 | YES |             | NO |                 |\n");
		printf("|                                                            |\n");
		printf("|                                                            |\n");
		printf("|    Для продолжения нажмите на любую клавишу клавиатуры.    |\n");
		printf("|            Введите N или n чтобы покинуть игру.            |\n");
		printf("|------------------------------------------------------------|\n");
		exitButton = _getche();
	} while ((exitButton != 'N') && (exitButton != 'n'));

}