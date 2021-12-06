#include<stdio.h>
#include<conio.h>
#include<locale.h>
#include<stdlib.h>
#include <string.h>
#include<iostream>
char* strcpy_my(char* s1, char* s2)
{char* ptrs1 = s1;
while ((*s1++ = *s2++) != 0);
return ptrs1;
}


int strcmp_my(char* str1, char* str2) {
	while (*str1 == *str2)
	{
		str1++;
		str2++;
	}
		if (*str1 > *str2)  return 1;
		if (*str1 <= *str2)  return 0;	
}

char** sort(char** text, int strings) {
	char* str = (char*)malloc(strlen(text[0]) * sizeof(char));


	for (int i = 0; i < strings - 1; i++) {
		for (int k = i + 1; k < strings; k++) {
			if (strcmp_my(text[i], text[k])) {
				str = text[i];
				text[i] = text[k];
				text[k] = str;
			}
		}
	}
	return text;
}


int main()
{
	int string = 0;
	char buf[80] = { 0 };
	char** text;
	text = (char**)malloc(sizeof(char*));
	printf("Enter the text\n");
	do {
		gets_s(buf);
		text[string] = (char*)malloc(sizeof(buf) + 1);
		strcpy_my(text[string], buf);
		string++;
		text = (char**)realloc(text, (string + 1) * sizeof(char*));
	} while (*buf);
	for (int i = 0; i < string; i++) {puts(text[i]); }
	text = sort(text, string);
	for (int i = 0; i < string; i++) {puts(text[i]); }
}