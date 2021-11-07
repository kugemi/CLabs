//Гистограмма и диаграмма текста
#include<stdio.h>
#include<conio.h>
#include<locale.h>
#define IN 1
#define OUT 0

int main()
{
	setlocale(LC_ALL, "Russian");
	int index, index2, max, max2;
	int numberOfSymbols[100], compositionOfTheSentence[100];
	for (index = 0; index < 100; index++)
	{
		numberOfSymbols[index] = 0;
		compositionOfTheSentence[index] = 0;
	}
	int word, symbol, sentence, text, state = OUT;
	word = sentence = 0;

	printf("Введите текст. По окончании ввода нажмите CTRL/Z\n");
	while ((text = getchar()) != EOF)
	{
		if (text == ' ' || text == '\n' || text == ',' || text == '-')
			state = OUT;
		else
			if (text == '.' || text == '!' || text == '?')
			{
				state = OUT;
				sentence++;
			}
			else
				if (state == OUT)
				{
					state = IN;
					word++;
					compositionOfTheSentence[sentence + 1]++;
				}
		if (state == IN)
			numberOfSymbols[word]++;
	}

	printf("Количество слов в тексте - %d\n", word);
	printf("Гистограмма текста:");

	for (index = 1; index <= word; index++)
	{
		printf("\n");
		for (symbol = 1; symbol <= numberOfSymbols[index]; symbol++)
			printf("*");
	}

	printf("\n");
	printf("Количество предложений в тексте - %d\n", sentence);

	for (index = 1; index <= sentence; index++)
		printf("В %d предложении - %d сл.\n", index, compositionOfTheSentence[index]);

	printf("Диаграмма текста:\n");

	max = compositionOfTheSentence[0];
	for (index = 1; index <= sentence; index++)
		if (compositionOfTheSentence[index] > max)
			max = compositionOfTheSentence[index];
	max2 = max;

	for (index = 1; index <= max2; index++)
	{
		for (index2 = 1; index2 <= max2; index2++)
		{
			if (compositionOfTheSentence[index2] >= max)
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
		max = max - 1;
	}
	_getch();
}