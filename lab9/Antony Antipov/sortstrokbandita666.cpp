#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>

int stcmp_my(char* pervayaya, char* vtorayaya) {
	int max = 0;
	char* pervaya, * vtoraya;
	pervaya = pervayaya;
	vtoraya = vtorayaya;

	if (strlen(pervaya) >= strlen(vtoraya))
		max = strlen(pervaya);
	else
		max = strlen(vtoraya);

	for (int index = 0; index <= max; index++)
	{
		if ((*pervaya - *vtoraya) < 0)
			return 0;
		else if ((*pervaya - *vtoraya) > 0)
			return 1;
		pervaya++;
		vtoraya++;
	}
	return 0;
}
char** sort(char** a, int n)
{
	char* t = NULL;
	for (int index = 0; index < n; index++) {
		for (int kindex = 0; kindex < n - 1; kindex++) {
			if (stcmp_my(a[kindex],a[kindex+1])) {
				t = a[kindex]; 
				a[kindex] = a[kindex + 1]; 
				a[kindex + 1] = t; 
			}
		}
	}

	return a;
}
char* strcpy_my(char* plagiat, char* original) {
	char* save = plagiat;
	while ((*plagiat++ = *original++) != 0);
	return save;
}
int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	char** masStr;
	int kolvoStrok = 0;
	char buf[100];
	masStr = (char**)malloc(sizeof(char*));
	printf("Введи текст, бандит\n");
	for (int index = 0; index < 100; index++) {
		gets_s(buf);
		if (!*buf) break;
		masStr = (char**)realloc(masStr,(index+1)*sizeof(char*));
		masStr[index] = (char*)malloc((strlen(buf) + 1)*sizeof(char));
		strcpy_my(masStr[index], buf);
		kolvoStrok++;
	}
	masStr = sort(masStr, kolvoStrok);
	for (int index = 0; index < kolvoStrok; index++)
		printf("%s\n", masStr[index]);


}