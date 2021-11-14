#include <conio.h>
#include <stdio.h>
#include <locale.h>
#include <iostream>

int main()
{
	setlocale(LC_ALL, "russian");
	int  shift, counter, inputRight, input1, shiftDir;
	int input = 0;
	long int binaryLeft = 0;
	int binaryInput = 0;
	int inputLeft = 0;
	shift = counter = inputRight = input1 = shiftDir = 0;
	counter = 1;

	printf("Введите число от 1 до 1023:");
	scanf_s("%d", &input);
	binaryInput = 0;
	input1 = input;
	printf("Введите число сдвигов влево:");
	scanf_s("%d", &shift);
	printf("Введите 1 для сдвига вправо, или 2 для сдвига влево.");
	scanf_s("%d", &shiftDir);
	printf("Изначальное число:%d\n", input);
	printf("Двоичная запись числа:");

	while (input > 0)
	{
		binaryInput += ((input % 2) * pow(10, counter));
		input /= 2;
		counter++;
	}
	binaryInput /= 10;
	printf("%032d", binaryInput);
	// Сдвиг влево
	if (shiftDir == 2)
	{
		inputLeft = ((input1 << shift) + (input1 >> (32 - shift)));
		printf("\nЧисло со сдвигом влево:%d\n", inputLeft);
		counter = 1;
		
		while (inputLeft > 1)
		{
			printf("\n%d", binaryLeft);
			binaryLeft += ((inputLeft % 2) * int(pow(10, counter)));
			inputLeft /= 2;
			counter++;
		}
		printf("\n%d", binaryLeft);
		printf("\n\nЧисло со сдвигом влево в двоичной системе:%032d", binaryLeft);
	}

}
