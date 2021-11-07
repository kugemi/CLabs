﻿#include<stdio.h>
#include<conio.h>
#include <iostream>
#include<locale.h>
int main()
{
	setlocale(LC_ALL, "Russian");
	unsigned short int Number = 0;
	int Shift = 0;
	int Direction = 0;
	printf("Введите число: ");
	scanf_s("%hu", &Number);
	printf("\n");
	printf("Введите число позиций сдвига: ");
	scanf_s("%d", &Shift);
	printf("\n");
	printf("Двоичное представление числа %hu = ", Number);
	for (int binary = 15; binary >= 0; binary--)
	{
		if (Number & (1<<binary)) printf("1");
		else printf("0");
		if (binary % 4 == 0) printf(" ");
	}
	printf("\n");
	printf("Выберите направление сдвига\n");
	printf("1)Если вправо\n");
	printf("2)Если влево\n");
	scanf_s("%d", &Direction);
	switch (Direction)
	{
	case 1:
	{
		for (int directionRight = 0; directionRight < Shift; directionRight++)
		{
			if (Number % 2 == 1)
			{
				Number >>= 1;
				Number += 1 << 15;
			}
			else Number >>= 1;
		}
		break;
	}
	case 2:
	{
		for (int directionLeft = 0; directionLeft < Shift; directionLeft++)
		{
			if (Number & (1 << 15))
			{
				Number <<= 1;
				Number += 1;
			}
			else Number <<= 1;
		}
		break;
	}
	}
	printf("Двоичное представление числа %hu после сдвига = ", Number);
	for (int binaryNew = 15; binaryNew >= 0; binaryNew--)
	{
		if (Number & (1 << binaryNew)) printf("1");
		else printf("0");
		if (binaryNew % 4 == 0) printf(" ");
	}
}

