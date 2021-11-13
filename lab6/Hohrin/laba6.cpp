#include <conio.h>
#include <stdio.h>
#include <locale.h>
#include <iostream>

int main()
{
	setlocale(LC_ALL, "russian");
	int input, shiftRight, shiftLeft, binaryInput, counter, counterRight, counterLeft, binary;
	input = shiftRight = shiftLeft = counter = binaryInput = counterRight = counterLeft = 1;
	binary = 2;
	int binaryArray[100] = { 0 };
	int binaryReverse[100] = { 0 };
	printf("Введите число:");
	scanf_s("%d", &input);
	printf("Введите число сдвигов влево:");
	scanf_s("%d", &shiftLeft);
	printf("Введите число сдвигов вправо:");
	scanf_s("%d", &shiftRight);
	while (input > 0)
	{
		binaryReverse[counter] = input % 2;
		input = input / 2;
		counter++;
	}
	counter--;
	for (int i = 0; i < counter; i++)
	{
		binaryArray[i] = binaryReverse[counter - i];
	}
	printf("Двоичная запись числа:");
	for (int i = 0; i < counter; i++)
	{
		printf("%d", binaryArray[i]);
	}
	printf("\n Двоичная запись числа с сдвигом влево:");
	for (int i = 0; i < counter; i++)
	{
		printf("%d", binaryArray[(i + shiftLeft) % counter]);
	}

	printf("\nДвоичная запись числа с сдвигом вправо:");
	for (int i = 0; i < counter; i++)
	{
		printf("%d", binaryArray[((abs(counter*shiftRight) + i - shiftRight) % counter)]);
	}

}
