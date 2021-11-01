#include <iostream>
#include <locale.h>
#include <conio.h>
#include<time.h>
#include <stdlib.h>
#define IN 1
#define OUT 0
int main()
{
	setlocale(LC_ALL, "Russian");
	int check;
	int word;
	int state = OUT;
	int WordNumber = 0; 
	int SentenceNum = 0;
	int NumSymb[200];
	int NumWords[200];
	int i, k, s;
	int max;
	int constmax;
	
	for (s = 0; s < 200; s++) { NumSymb[s] = 0; }
	for (s = 0; s < 200; s++) { NumWords[s] = 0; }
	printf("Программа считает кол-во слов и предложений в тексте и выводит гистограмму.\nКогда введете текст, нажмите Enter, затем Ctrl+Z и снова Enter.\nВведите текст: \n");
	while ((check = getchar()) != EOF)
	{
		if (check == ' ' || check == '\n' || check == '\t')
			state = OUT;
		else if (check == '!' || check == '?' || check == '.')
		{
			state = OUT;
			SentenceNum += 1;
		}
		else if (state == OUT)
		{
			state = IN;
			word = WordNumber;
			WordNumber = WordNumber + 1;
			NumWords[SentenceNum]++;
		}
		if (state == IN) {
			NumSymb[word]++;
		}
	}

	printf("Количество слов: %i", WordNumber);

	for (k = 0; k <= WordNumber; k++)
	{
		printf("\n");
		for (i = 1; i <= NumSymb[k]; i++) { printf("*"); }
	}
	printf("Количество предложений: %i\n", SentenceNum);
	for (i = 0; i < SentenceNum; i++)
		printf("В %i предложении %i слов(а)\n", i + 1, NumWords[i]);


	max = 0;
	for (i = 0; i < SentenceNum; i++)
		if (NumWords[i] > max)
			max = NumWords[i];
	constmax = max;
	for (i = 1; i <= constmax; i++) {
		for (s = 0; s < SentenceNum; s++) {
			if (max <= NumWords[s]) {
				printf("*");
			}
			else
				printf(" ");
		}
		printf("\n");
		max = max - 1;
	}
}
