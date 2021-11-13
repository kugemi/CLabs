//Битовые операции
#include<stdio.h>
#include<conio.h>
#include<locale.h>

void conversionToBinaryNotation(int number)
{
	int index,constant;
	constant = 128; //32768;
	for (index = constant; index > 0; index /= 2)
		if (number & index) 
			printf("1");
		else 
			printf("0");
}

int main()
{
	unsigned char Number;
	int shiftSide, Index, numberOfShifts;
	setlocale(LC_ALL, "Russian");

	printf("Введите число: ");
	scanf_s("%d", &Number);
	printf("Число %d в двоичной системе счисления имеет вид: ", Number );
	conversionToBinaryNotation(Number);

	printf("\nУкажите на сколько позиций выполнить сдвиг: ");
	scanf_s("%d", &numberOfShifts);
	printf("Если хотите выполнить сдвиг вправо нажмите 1, влево нажмите 2 - ");
	shiftSide = _getche();
	if (shiftSide == '1')
	{
		for (Index = 0; Index < numberOfShifts; Index++)
		{
			if (Number % 2 == 1)
			{
				Number = Number >> 1;
				Number = Number + (1 << 7); //<<15
			}
			else
				Number = Number >> 1;
		}
		printf("\nПосле сдвига вправо на %d позиций - %d", numberOfShifts, Number);
	}
	else
	{
		for (Index = 0; Index < numberOfShifts; Index++)
		{
			if (Number & (1 << 7)) //<<15
			{
				Number = Number << 1;
				Number++;
			}
			else
				Number = Number << 1;
		}
		printf("\nПосле сдвига влево на % d позиций - %d", numberOfShifts, Number);
	}

	printf("\n");
	printf("Число %d в двоичной системе счисления имеет вид: ", Number);
	conversionToBinaryNotation(Number);
	_getch();
}