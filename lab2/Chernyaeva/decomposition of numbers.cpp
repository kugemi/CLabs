/*простой состав числа*/
#include<stdio.h>
#include<conio.h>
#include<locale.h>
int checkingTheNumber(long summand);

int main()
{
	setlocale(LC_ALL, "Russian");
	int number;
	int firstSummand;
	printf("Введите четное число: ");
	while ((scanf_s("%d", &number) == 0) || (number < 0) || (number % 2 != 0))
	{
		printf("Неверное полученное значение, попробуйте еще раз: ");
		while (getchar() != '\n');
	}
	printf("\n");
	for (firstSummand = 1; firstSummand <= (number / 2); firstSummand++)
		if (checkingTheNumber(firstSummand))
				if (checkingTheNumber(number-firstSummand))
						printf(" %d = %d + %d \n",number, firstSummand, number-firstSummand);
	_getch();

}
int checkingTheNumber(long summand)
{
	int divider;
	if (summand < 4) return 1;
	if (summand % 2 == 0) return 0;
	for (divider = 3; divider * divider <= summand; divider += 2)
		if (summand % divider == 0) return 0;
	return 1;
}
