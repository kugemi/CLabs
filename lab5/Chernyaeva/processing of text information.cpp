#include<stdio.h>
#include<conio.h>
#include<locale.h>
#define IN 1
#define OUT 0

int main()
{
	setlocale(LC_ALL, "Russian");
	int text, proposal, words, state = OUT;
	proposal = words = 0;
	int wordNumber, symbol, index, element;
	int max,maxx;
	int numberOfCharacters[100], compositionOfTheOffer[100];
	for (index = 0; index < 100; index++) {
		numberOfCharacters[index] = 0;
		compositionOfTheOffer[index] = 0;
	}
	printf("                               Введите текст.\n                      По окончании ввода нажмите CTRL/Z\n");
	printf("                      ---------------------------------\n\n");
	while ((text = getchar()) != EOF)
	{
		if ((text == ' ') || (text == '\n') || (text == '\t')||(text==',')||(text=='-'))
			state = OUT;
		else if ((text == '.') || (text == '!') || (text == '?')) {
			state = OUT;
			proposal += 1;
		}
		else if (state == OUT)
		{
			state = IN;
			words += 1;
			compositionOfTheOffer[proposal + 1]++;
		}
		if(state==IN)
			numberOfCharacters[words]++;
	}
	printf("\n                        -----------------------------\n");
	printf("                        количество слов в тексте - %d", words);
	printf("\n                        -----------------------------\n");
	printf("\n                             Гистограмма текста:\n");
	for (wordNumber= 1; wordNumber <= words; wordNumber++) {
		printf("\n");
		for (symbol = 1; symbol <= numberOfCharacters[wordNumber]; symbol++)
			printf("\x03");// вместо * печатает ♥
	}
	printf("\n                    ------------------------------------\n");
	printf("                    количество предложений в тексте - %d", proposal);
	printf("\n                    ------------------------------------\n\n");
	printf(" ");
	for (index = 1; index <= proposal; index++) {
		printf("в %d предложении - %d сл ; ", index, compositionOfTheOffer[index]);
		if (index % 3 == 0)
			printf("\n ");
	}
	printf("\n\n                             Диаграмма текста:\n");
	max = compositionOfTheOffer[0];
	for (index = 1; index <= proposal; index++)
		if (compositionOfTheOffer[index] > max)
			max = compositionOfTheOffer[index];
	maxx = max;
	for (index = 1; index <= maxx; index++) {
		for (element = 1;  element <= proposal; element++) {
			if (compositionOfTheOffer[element] >= max) {
				printf("\x03");
			}
			else
				printf(" ");
		}
		printf("\n");
		max = max - 1;
		if (max == 0)
			break;
	}
	_getch();
	return 0;
}