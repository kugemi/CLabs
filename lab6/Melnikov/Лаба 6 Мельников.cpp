#include<stdio.h>
#include<conio.h>
#include <iostream>
#include<locale.h>
int main()
{
	setlocale(LC_ALL, "Russian");
	unsigned int Number = 0;
	int Shift = 0;
	int Direction = 0;
	printf("Choose a number: ");
	scanf_s("%u", &Number);
	printf("\n");
	printf("Binary representation of a number %u = ", Number);
	for (int binary = 31; binary >= 0; binary--)
	{
		if (Number & (1 << binary)) printf("1");
		else printf("0");
	}
	printf("\n");
	printf("Enter the number of shift positions: ");
	scanf_s("%d", &Shift);
	printf("\n");
	
	printf("Select the shift direction\nWrite 1 if to the right\nWrite 2 if to the left\n");
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
				Number += 1 << 31;
			}
			else Number >>= 1;
		}
		break;
	}
	case 2:
	{
		for (int directionLeft = 0; directionLeft < Shift; directionLeft++)
		{
			if (Number & (1 << 31))
			{
				Number <<= 1;
				Number += 1;
			}
			else Number <<= 1;
		}
		break;
	}
	}
	printf("Binary representation of a number %d after shift = ", Number);
	for (int binaryNew = 31; binaryNew >= 0; binaryNew--)
	{
		if (Number & (1 << binaryNew)) printf("1");
		else printf("0");
	}
	_getch();
}