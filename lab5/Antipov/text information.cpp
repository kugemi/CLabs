﻿#include <iostream>
#include <conio.h>
#include<time.h>
#include <stdlib.h>
#include <locale.h>
#define OUT 0
#define IN 1
int main() {
	setlocale(LC_ALL, "Russian");
	int symvol = 0;
	int polozhenie = OUT;
	int nomerSlova = 0;
	int kolvoSymvolovVSlove[100];
	int nomerPredlozhenia = 0;
	int kolvoSlovVPredlozhenii[100];
	int max = 0;
	int constmax = 0;
	int slovo=0;
	for (int index = 0; index < 100; index++) { kolvoSymvolovVSlove[index] = 0; }
	for (int index = 0; index < 100; index++) { kolvoSlovVPredlozhenii[index] = 0; }
	printf("Введите текст\n");
	while ((symvol = getchar()) != EOF)
	{
		if (symvol == '\t' || symvol == '\n' || symvol == ' ')
			polozhenie = OUT;
		else if (symvol == '?' || symvol == '!' || symvol == '.')
		{
			polozhenie = OUT;
			nomerPredlozhenia += 1;
		}
		else if (polozhenie == OUT) {
			polozhenie = IN;
			slovo = nomerSlova;
			nomerSlova = nomerSlova + 1;;
			kolvoSlovVPredlozhenii[nomerPredlozhenia]++;
		}
		if (polozhenie == IN) { kolvoSymvolovVSlove[slovo]++; }
	}
	printf("Количество слов: %d", nomerSlova);
	for (int kindex = 0; kindex <= nomerSlova; kindex++)
	{
		printf("\n");
		for (int zindex = 1; zindex <= kolvoSymvolovVSlove[kindex]; zindex++)
		{
			printf("*");
		}
	}
		printf("Количество предложений: %d\n", nomerPredlozhenia);
		for (int index = 0; index < nomerPredlozhenia; index++) 
			printf("Количетсво слов в предложении %d = %d\n", index + 1, kolvoSlovVPredlozhenii[index]);
		
		for (int index = 0; index < nomerPredlozhenia; index++)
			if (kolvoSlovVPredlozhenii[index] > max)
				max = kolvoSlovVPredlozhenii[index];
		constmax = max;
		for (int index = 1; index <= constmax; index++) {
			for (int zindex = 0; zindex < nomerPredlozhenia; zindex++) {
				if (max <= kolvoSlovVPredlozhenii[zindex]) {
					printf("*");
				}
				else
					printf(" ");
			}
			printf("\n");
			max = max - 1;
		}
}