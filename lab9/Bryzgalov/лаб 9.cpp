#include<stdio.h>
#include<conio.h>
#include<locale.h>
#include<stdlib.h>
#include <string.h>

int strcmp_my(char* str1, char* str2) {
	if (*str1 >= *str2) return 0;
	else return 1;
}

char** sort(char** txt, int quantOfStrings) {
	char** doptxt = (char**)malloc(quantOfStrings*sizeof(char*));
	char* dopstr=(char*)malloc(strlen(txt[0])*sizeof(char));

	for (int a = 0; a < quantOfStrings; a++) {
		doptxt[a] = (char*)malloc(strlen(txt[a]) * sizeof(char));
		strcpy(doptxt[a], txt[a]);
	}
	for (int a = 0; a < quantOfStrings - 1; a++) {
		for (int b = a + 1; b < quantOfStrings; b++) {
			if (!strcmp_my(doptxt[a], doptxt[b])) {
				dopstr = (char*)realloc(dopstr,strlen(txt[a]) * sizeof(char));
				strcpy(dopstr,doptxt[a]);
				strcpy(doptxt[a], doptxt[b]);
				strcpy(doptxt[b], dopstr);
			}
		}
	}
	return doptxt;
}

int main(void) {
	setlocale(LC_ALL, "");

	int i, j, k, len, n = 0;
	char** text = NULL;
	char* buffer = NULL;
	char** dop = NULL;
	char ch = NULL;

	printf_s("Введите ваш текст:\n");
	for (i = 1;; i++) {
		buffer = NULL;
		len = 0;
		k = 2;
		buffer = (char*)malloc(k * sizeof(char));
		while ((ch = getchar()) != '\n') {
			while (k <= len) {
				k++;
				buffer = (char*)realloc(buffer, k * sizeof(char));
			}
			if (buffer!=NULL) {
				buffer[len] = ch;
				len++;
			}
		}
		buffer = (char*)realloc(buffer, (len + 1) * sizeof(char));
		if (buffer!=NULL) buffer[len] = '\0';
		len++;
		if (buffer[0] == '\0') {
			free(buffer);
			break;
		}
		if (i != 1) {
			dop = (char**)malloc(sizeof(char*) * i);
			for (j = 0; j < i; j++) dop[j] = text[j];
			free(text);
			text = dop;
		}
		else text = (char**)malloc(sizeof(char*) * i);
		text[i - 1] = (char*)malloc((len + 1) * sizeof(char));
		strcpy(text[i - 1], buffer);
		free(buffer);
		n = i;
	}


	printf_s("__________________\n\nВаш текст:\n");
	for (i = 0; i < n; i++) printf_s("Строка №%d: %s\n",i+1, text[i]);
	printf_s("__________________\n\nОтсортированный тектст:\n");
	text = sort(text, n);
	for (i = 0; i < n; i++) printf_s("Строка №%d: %s\n", i + 1, text[i]);
}