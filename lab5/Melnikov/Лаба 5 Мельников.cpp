#include <iostream>
#include <locale.h>
#include <conio.h>
#define IN 1
#define OUT 0
int main()
{
	setlocale(LC_ALL, "Russian");
	int symbol;
	int numbOfSymbols = 0;
	int state = OUT;
	int numbOfSymbolsInWord[100] = {};
	int numbOfWordsInSent[100] = {};
	int numbOfWords = 0;
	int numbOfWords_1 = 0;
	int numbOfSent = 0;
	printf("Введите ваш текст. По окончании ввода нажмите Ctrl + Z\n");
	while ((symbol = getchar()) != EOF)
	{
		if (symbol == ' ' || symbol == '\t' || symbol == '\n')
		{
			state = OUT;
			numbOfSymbolsInWord[numbOfWords] = numbOfSymbols;
			numbOfSymbols = 0;
		}
		else
		{
			numbOfSymbols += 1;
			if (state == OUT)
			{
				state = IN;
				numbOfWords += 1;
			}
		}
		if (symbol == '.' || symbol == '!' || symbol == '?')
		{
			numbOfSent += 1;
			numbOfWordsInSent[numbOfSent] = numbOfWords - numbOfWords_1;
			numbOfWords_1 = numbOfWords;
		}

	}
	printf("В тексте %d слов(а)\n", numbOfWords);
	for (int i = 1; i < numbOfWords + 1; i++)
	{
		for (int k = 1; k < numbOfSymbolsInWord[i] + 1; k++)
		{
			printf("*");
		}
		printf("\n");
	}
	printf("\nВ тексте %d предложений\n", numbOfSent);
	for (int j = 1; j < numbOfSent + 1; j++)
	{
		printf("В %d предложении - %d слов(а). ", j, numbOfWordsInSent[j]);
	}
	printf("\n");
	printf("\n");
	int maxElem = 0;
	for (int t = 1; t < numbOfWords + 1; t++)
	{
		if (numbOfWordsInSent[t] > maxElem)
		{
			maxElem = numbOfWordsInSent[t];
		}
	}
	int maxxElem = maxElem;
	for (int n = 1; n <= maxxElem; n++)
	{
		for (int elem = 1; elem <= numbOfSent; elem++)
		{
			if (numbOfWordsInSent[elem] >= maxElem)
			{
				printf("*");
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
		maxElem -= 1;
	}
	_getch();
	return 0;
}