#include <stdio.h>
#include <conio.h>
#define IN 1
#define OUT 0
int main()
{
	int currentSymbol = 0;

	int numSymbols = 0;
	int numWords = 0;
	int numLines = 0;
	int numWordsInsentence = 0;
	int numSentence = 1;
	int numWords1 = 0; // ����� �� ������ ���������� ����


	int symbolsInword[100] = { 0 };
	int sentenceIntext[100] = { 0 };

	int state = OUT; //������� ��� �����
	int indexWord = 0;

	printf("Wrtie text for stop press CTRL / Z \n");
	while ((currentSymbol = getchar()) != EOF)
	{
		numSymbols++; //������� �������

		if (currentSymbol == '\n')
			numLines++; //������� ������



		if (currentSymbol == ' ' || currentSymbol == '\n' || currentSymbol == 'n')
		{
			state = OUT;
			numSymbols--;
			symbolsInword[numWords] = numSymbols;
			numSymbols = 0;
		}
		else
			if (state == OUT)
			{
				state = IN; //�������� �����
				numWords++; //������� �����
				numWords1++;
			}

		if (currentSymbol == '.' || currentSymbol == '!' || currentSymbol == '?')
		{
			sentenceIntext[numSentence] = numWords1;
			numSentence++;
			numWords1 = 0;
		}

	}
	
	printf("\nnumber of words = %d", numWords);

	for (int i = 0; i <= numWords; i++)
	{
		for (int j = 0; j < symbolsInword[i]; j++)
			printf("*");
		printf("\n");
	}

	printf("-----------\n");


	int max = sentenceIntext[1], k = 0;
	for (int i = 1; i <=numSentence; i++)
		if (sentenceIntext[i] > max)
		{	
			k = i;
		max = sentenceIntext[i];
		}
	

	for (int j = max; j > 0; j--)
	{
		printf(" ");
		for (int i = 1; i <= numSentence; i++)
		{
			if (sentenceIntext[i] == j)
			{
				printf(" *");
				sentenceIntext[i]--;
			}
			else printf("  ");
		}
		printf("\n");
	}

	getchar();
	return;
}