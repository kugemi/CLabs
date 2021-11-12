#include <iostream>
#include <locale.h>
#include <conio.h>
#define IN 1
#define OUT 0
int main()
{
	setlocale(LC_ALL, "Russian");
	int symbol = 0;
	int numbOfSymbols = 0;
	int state = OUT;
	int numbOfSymbolsInWord[100] = {0};
	int numbOfWordsInSent[100] = {0};
	int numbOfWords = -1;
	int numbOfSent = 0;
	int wordsOfSent = 0;
	printf("Enter your text. At the end of the input, press Ctrl + Z\n");
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
				wordsOfSent += 1;
			}
		}
		if (symbol == '.' || symbol == '!' || symbol == '?')
		{
			numbOfWordsInSent[numbOfSent] = wordsOfSent;
			numbOfSent += 1;
			wordsOfSent = 0;
		}

	}
	printf("There is(are) %d word(s) in the text\n", numbOfWords + 1);
	for (int i = 0; i < numbOfWords + 1; i++)
	{
		for (int k = 0; k < numbOfSymbolsInWord[i]; k++)
		{
			printf("*");
		}
		printf("\n");
	}
	printf("\nThere is(are) %d sentence(s) in the text\n", numbOfSent);
	for (int j = 0; j < numbOfSent; j++)
	{
		printf("In %d sentence - %d word(s). ", j + 1, numbOfWordsInSent[j]);
	}
	printf("\n");
	printf("\n");
	int maxElem = 0;
	for (int t = 0; t < numbOfWords  + 1; t++)
	{
		if (numbOfWordsInSent[t] > maxElem)
		{
			maxElem = numbOfWordsInSent[t];
		}
	}
	int forCounter = maxElem;
	for (int n = 0; n < forCounter; n++)
	{
		for (int elem = 0; elem < numbOfSent; elem++)
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