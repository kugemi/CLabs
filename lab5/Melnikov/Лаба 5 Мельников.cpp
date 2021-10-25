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
	int numbOfSymbolsInWord[100] = { 0 };
	int numbOfWordsInSent[100] = { 0 };
	int numbOfWords = 0;
	int numbOfWords_1 = 0;
	int numbOfSent = 0;
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
			}
		}
		if (symbol == '.' || symbol == '!' || symbol == '?')
		{
			numbOfSent += 1;
			numbOfWordsInSent[numbOfSent] = numbOfWords - numbOfWords_1;
			numbOfWords_1 = numbOfWords;
		}

	}
	printf("There is(are) %d word(s) in the text\n", numbOfWords);
	for (int i = 1; i < numbOfWords + 1; i++)
	{
		for (int k = 1; k < numbOfSymbolsInWord[i] + 1; k++)
		{
			printf("*");
		}
		printf("\n");
	}
	printf("\nThere is(are) %d sentence(s) in the text\n", numbOfSent);
	for (int j = 1; j < numbOfSent + 1; j++)
	{
		printf("In %d sentence - %d word(s). ", j, numbOfWordsInSent[j]);
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
	int forCounter = maxElem;
	for (int n = 1; n <= forCounter; n++)
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