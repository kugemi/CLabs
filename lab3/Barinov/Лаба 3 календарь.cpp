﻿#include<stdio.h>
#include<locale.h>
#include<conio.h>
#include <iostream>
int func();
int main() {
	setlocale(LC_ALL, "Russian");
	int day = 1;
	int month = 1;
	int year = 1600;
	int first_2Digits = 0;
	int second_2Digits = 0;
	int res = 0;
	int KolvoDney [12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	printf("Введите год: ");
	do {
		if ((year < 1582) || (year > 4902)) printf("%s", "Попробуйте снова\n");
		year = func();
	} while ((year < 1582) || (year > 4902));
	if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) KolvoDney[1] = 29;
	printf("\nВведите месяц: ");
	do {
		if ((month == 0) || (month > 12)) printf("%s", "Попробуйте снова\n");
		month = func();
	} while ((month == 0) || (month > 12));
	printf("\nВведите число: ");
	do {
		if ((day == 0) || (day > KolvoDney[month - 1])) printf("%s", "Попробуйте снова\n");
		day = func();
	} while ((day == 0) || (day > KolvoDney[month - 1]));
	if ((month == 1) || (month == 2)) {
		year -= 1;
		if (month == 1) month = 11;
		else month = 12;
	}
	else month -= 2;
	first_2Digits = year / 100;
	second_2Digits = year % 100;
	res = (int(2.6 * month - .2) + day + second_2Digits + int(second_2Digits / 4) + int(first_2Digits / 4) - 2 * first_2Digits) % 7;
	if (res < 0)res += 7;
	switch (res)
	{
	case 0:
		printf("Воскресенье");
		break;
	case 1:
		printf("Понедельник");
		break;
	case 2:
		printf("Вторник");
		break;
	case 3:
		printf("Среда");
		break;
	case 4:
		printf("Четверг");
		break;
	case 5:
		printf("Пятница");
		break;
	case 6:
		printf("Суббота");
		break;
	}
}
int func() {
	int N = 0;
	int resFunc = 0;
	int check = 0;
	do {
		resFunc = 0;
		check = 0;
		check = scanf_s("%d", &resFunc);
		if ((check != 1) || (resFunc <= 0)) printf("%s", "Попробуйте снова\n ");
		while (getchar() != '\n');
	} while (((check != 1) || (resFunc <= 0)) || (resFunc != (int)resFunc));
	N = resFunc;
	return N;
}