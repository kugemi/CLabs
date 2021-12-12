#include<conio.h>
#include<stdio.h>
#include <iostream>
#include<locale.h>
#include<string.h>
int strcmp_my(char* string1, char* string2) {
	while (*string1 && *string2)
	{
		if (*string1 == *string2)
		{
			string1++;
			string2++;
			continue;
		}
		if (*string1 < *string2) return 1;
		else return 0;
	}
}
char** sort(char** sortText, int quanityOfString) {
	int maxlen = 0;
	char** additionalText = (char**)malloc((quanityOfString+1) * sizeof(char*));
	char* additionalString = (char*)malloc((strlen(sortText[0])+1)*sizeof(char));
	for (int index = 0; index < quanityOfString; index++) {
		additionalText[index] = (char*)malloc((strlen(sortText[index]+1))*sizeof(char));
		memcpy(additionalText[index], sortText[index], strlen(sortText[index])+1);
	}
	int res = 0;
	for (int sort = 0; sort < quanityOfString-1; sort++) {
		for (int insideSort = sort+1; insideSort < quanityOfString; insideSort++) {
				if (!strcmp_my(additionalText[sort],additionalText[insideSort])) {
					if (strlen(additionalText[sort]) > strlen(additionalText[insideSort])) maxlen = strlen(additionalText[sort]);
					else maxlen = strlen(additionalText[insideSort]);
					additionalString = (char*)malloc((maxlen+1) * sizeof(char));
					additionalString = additionalText[sort];
					additionalText[sort] = additionalText[insideSort];
					additionalText[insideSort] = additionalString;
				}
			}
		}
	return additionalText;
}
int main()
{
	setlocale(LC_ALL, "Russian");
	int quantityString = 0;
	char buf[100];
	char** text = (char**)malloc(sizeof(char*));
	printf("Введите ваш текст:\n");
	while (quantityString > -1) {
		gets_s(buf);
		if (!*buf) break;
		text[quantityString] = (char*)malloc(sizeof(buf)+1);
		memcpy(text[quantityString],buf,strlen(buf)+1);
		quantityString++;
		text = (char**)realloc(text, (quantityString + 1) * sizeof(char*));
	}
	printf("\n");
	printf("Ваш текст:\n");
	for (int indexPuts = 0; indexPuts < quantityString; indexPuts++) {
	puts(text[indexPuts]);
	}
	printf("\n");
	printf("Ваш отсортированный текст:\n");
	for (int indexSort = 0; indexSort < quantityString; indexSort++) {
		text = sort(text, quantityString);
		puts(text[indexSort]);
	}
}

