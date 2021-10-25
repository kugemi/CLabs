#include <iostream>
#include <locale.h>
#include <conio.h>
#include<time.h>
#include <stdlib.h>
#define IN 1
#define OUT 0
int main()
{
	int check;//вводимый символ
	int state = OUT;//статус
	int wordNumber=0; // номер слова
	int symbolsOfTheWord[100];//кол-во символов в слове
	int i, k,s;// ЭТО ДЛЯ ЦИКЛОВ, МОЕЙ ФАНТАЗИИ НЕ ХВАТИЛО ИХ НАЗВАТЬ!
	int numberOfSentences=0;//номер предложения
	int theNumberOfWordsInASentence[100];// колическво слов в предложениии
	int max;
	int constmax;
	for (s = 0; s < 100; s++) { symbolsOfTheWord[s] = 0;  }
	for (s = 0; s < 100; s++) { theNumberOfWordsInASentence[s] = 0; }
	printf("Enter the text \n");
	while ((check = getchar()) != EOF)
	{
		if (check == ' ' || check == '\n' || check == '\t')
		state = OUT;
		else if(check=='!'|| check=='?' || check == '.')
		{
			state = OUT;
			numberOfSentences+=1;
		}
		else if (state==OUT)
		{
			state = IN;
			wordNumber = wordNumber + 1;  
			theNumberOfWordsInASentence[numberOfSentences ]++;
		}
		if (state == IN) { symbolsOfTheWord[wordNumber-1]++; }
	}
	
	printf("Number of words: %i", wordNumber);
	
	for (k = 0; k <= wordNumber; k++) 
	{
		printf("\n");
		for (i = 1; i <= symbolsOfTheWord[k-1]; i++) {printf("*"); }
	}
	printf("Number of sentences: %i\n", numberOfSentences);
	for (i = 0; i < numberOfSentences; i++)
		printf("in %i sentences %i words\n", i+1, theNumberOfWordsInASentence[i]);

	
	max = 0;
	for (i = 0; i < numberOfSentences; i++)
		if (theNumberOfWordsInASentence[i] > max)
			max = theNumberOfWordsInASentence[i];
	constmax = max;
	for (i = 1; i <= constmax; i++) {
		for (s = 0; s < numberOfSentences; s++) {
			if (max <= theNumberOfWordsInASentence[s] ) {
				printf("*");
			}
			else
				printf(" ");
		}
		printf("\n");
		max = max - 1;
	}
}

