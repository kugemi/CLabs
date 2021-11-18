#include <iostream>
#include<conio.h>
#include<stdio.h>
#include<locale.h>
int main()
{
	setlocale(LC_ALL, "Russian");
	unsigned short int num = 0;
	int sdvig = 0;
	int Napravlenie = 0;
	printf("Введите число: ");
	scanf_s("%hu", &num);
	printf("Введите число сдвигов: ");
	scanf_s("%d", &sdvig);
	printf("Число в двоичной системе счисления %hu = ", num);
	for (int index = 15; index >= 0; index--)
	{
		if (num & (1 << index)) printf("1");
		else printf("0");
		if (index % 4 == 0) printf(" ");
	}
	printf("\n");
	printf("Выберите направление сдвига\n");
	printf("1)Влево\n");
	printf("2)Вправо\n");
	scanf_s("%d", &Napravlenie);

	if (Napravlenie == 1)
	{

		for (int vlevo = 0; vlevo < sdvig; vlevo++)
		{
			if (num & (1 << 15)) {
				num <<= 1;
				num += 1;
			}
			else num <<= 1;
		}
	}
	if (Napravlenie == 2)
	{
		for (int vpravo = 0; vpravo < sdvig; vpravo++)
		{
			if (num % 2 ==1 ) {
				num >>= 1;
					num += 1 << 15;
			}
			else num >>= 1;
		}
	}
	printf("Число %hu в двочной системе после сдвига = ", num);
		for (int kindex = 15; kindex >= 0; kindex--)
		{
			if (num & (1 << kindex)) printf("1");
			else printf("0");
			if (kindex % 4 == 0) printf(" ");
		}
	_getch();
}