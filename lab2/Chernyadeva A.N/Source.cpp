#include <conio.h>
#include <locale.h>
#include <stdio.h>

// Объявление функции
int prime(long N);

int main()
{
	// Русский язык
	setlocale(LC_ALL, "Rus");

	//Обыявление перемнных
	int number, index;

	//Вывод приветственного текста
	printf(" Программа раскладывает чётные числа\n       на сумму двух простых.       \n");
	printf("    (\"1\" считается простым числом)    \n\n");

	// Цилк, проверяющий, действетьно ли введено чётное число
	do
	{
		printf("Введите натуральное число n, кратное двойке\nn = ");
		if (scanf_s("%d", &number) == 0) //Проверка на ввод символа
		{
			printf("!!! Вы ввели не число !!!");
			getchar() != '\0';
		}
		else if (number == 0) printf("!!! Вы ввели ноль !!!"); //Проверка на ввод нуля
		else if (number < 0) printf("!!! Вы ввели отрицательно число !!!"); //Проверка на ввод отрицательного числа
		else if (number % 2 != 0) printf("!!! Вы ввели нечётное число !!!"); //Проверка на ввод нечётного числа
	} while ((number % 2 != 0) || (number <= 0));

	printf("-------------------\n");
	printf("%d = \n", number); //Вывод введённого числа

	//Разложение числа на сумму простых
	for (index = 0; index *2 < number; index++)
	{
		if (prime(index) && prime(number - index))
			printf("    %d + %d\n", index, number - index);
	}
	
}

//Функция, проверяющая простоту числа.
int prime(long N)
{
	long j;
	if ((N < 1) || (N % 2 == 0)) return 0;
	if (N == 1) return 1;
	for (j = 3; j * j <= N; j += 2)
		if (N % j == 0) return 0;
	return 1;
}

