#include <iostream>
#include <conio.h>
#include<time.h>
#include <stdlib.h>
#include <locale.h>
#define OUT 0
#define IN 1



int main() {
	setlocale(LC_ALL, "Russian");
	int Polojenie = OUT;
	int symvol = 0;
	int NomerSlova = 0;
	int NomerPredloj = 0;
	int max = 0;
	int constmax = 0;
	int Slovo = 0;
	int SymvoliVSlove[100];
	int SlovaVPredloj[100];
	for (int index = 0; index < 100; index++) { SymvoliVSlove[index] = 0; }
	for (int index = 0; index < 100; index++) { SlovaVPredloj[index] = 0; }
	printf("Введите текст\n");
	while ((symvol = getchar()) != EOF)
	{
		if (symvol == '\t' || symvol == '\n' || symvol == ' ')
			Polojenie = OUT;
		else if (symvol == '?' || symvol == '!' || symvol == '.')
		{
			Polojenie = OUT;
			NomerPredloj += 1;
		}
		else if (Polojenie == OUT) {
			Polojenie = IN;
			Slovo = NomerSlova;
			NomerSlova = NomerSlova + 1;;
			SlovaVPredloj[NomerPredloj]++;
		}
		if (Polojenie == IN) { SymvoliVSlove[Slovo]++; }
	}
	printf("Количество слов: %d", NomerSlova);
	for (int index2 = 0; index2 <= NomerSlova; index2++)
	{
		printf("\n");
		for (int index3 = 1; index3 <= SymvoliVSlove[index2]; index3++) { printf("*"); }
	}
	printf("Количество предложений: %d\n", NomerPredloj);
	for (int index = 0; index < NomerPredloj; index++)
		printf("Количетсво слов в предложении %d = %d\n", index + 1, SlovaVPredloj[index]);

	for (int index = 0; index < NomerPredloj; index++)
		if (SlovaVPredloj[index] > max)
			max = SlovaVPredloj[index];
	constmax = max;
	for (int index = 1; index <= constmax; index++)
	{
		for (int index3 = 0; index3 < NomerPredloj; index3++) 
		{
			if (max <= SlovaVPredloj[index3]) { printf("*"); }
			else { printf(" "); }
		}
		printf("\n");
		max = max - 1;
	}
}