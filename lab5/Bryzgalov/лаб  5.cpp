#include<stdio.h>
#include<conio.h>
#include<locale.h>
#define OUT 0
#define IN 1

int main(void) {
	setlocale(LC_ALL,"");

	char text = 0;
	int status = OUT;
	int quantityOfWords[1000];
	int quantityOfSymbols[1000];
	int quantOfProposal = 0;
	int wordCount = 0;
	int max = 0;

	for (int index = 0; index < 1000; index++) {
		quantityOfSymbols[index] = 0;
		quantityOfWords[index] = 0;
	}
	printf_s("Введите текст (По окончанию ввода нажмите CTRL+Z): ");
	while ((text = getchar()) != EOF) {
		if ((text == ' ') || (text == '\n') || (text == '\t') || (text == ',') || (text == ':') || (text == ';')) status = OUT;
		else if ((text == '.') || (text == '?') || (text == '!')) {
			status = OUT;
			quantOfProposal++;
		}
		else if (status == OUT) {
			status = IN;
			quantityOfWords[quantOfProposal]++;
			wordCount++;
		}
		if (status == IN) {
			quantityOfSymbols[wordCount]++;
		}
	}
	printf_s("\n\n");
	printf_s("Количество слов - %d\n", wordCount);
	for (int numberOfWord= 1; numberOfWord <= wordCount; numberOfWord++) {
		for (int numberOfSymbol = 1; numberOfSymbol <= quantityOfSymbols[numberOfWord]; numberOfSymbol++) {
			printf_s("*");
		}
			printf_s("\n");
	}
	printf_s("\n\n");
	printf_s("Количество предложений - %d. ", quantOfProposal);
	for (int numberOfProposal = 1; numberOfProposal <= quantOfProposal; numberOfProposal++) {
		printf_s("В %d-м предложении %d слов. ", numberOfProposal, quantityOfWords[numberOfProposal]);
	}
	for (int index = 1; index <= quantOfProposal; index++) {
		if (quantityOfWords[index] > max) max = quantityOfWords[index];
	}
	printf_s("\n\n");
	for (int i = max; i > 0; i--) {
		for (int numberOfProposal=1; numberOfProposal <= quantOfProposal; numberOfProposal++) {
			if (quantityOfWords[numberOfProposal] >= i) printf_s("*");
			else printf_s(" ");
		}
		printf_s("\n");
	}
	return 0;
}