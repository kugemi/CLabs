#include <stdio.h>
#include <locale.h>
#include <conio.h>

// Блок "Жизнь себе облегчить"
#define lineBreak printf("\n")
#define Space(lenghtString) for (int i = 0; i < ((80-lenghtString)/2); i++) printf(" ")


int main()
{
	//Русский язык
	setlocale(LC_ALL, "Rus");

	unsigned short int userNumber = 0;  // Число, вводимое пользователем
	unsigned short int userShift = 0;   // Число сдвигов, вводимое пользователем
	unsigned short int direction = 0;   // Напрвление, в котором необходимо сдвинуть текст
	int index = 0;                      // Счётчик

	// Приветственное сообщение
	lineBreak;
	Space(50); printf("--------------------------------------------------\n");
	Space(49); printf("Программа осуществляет циклический сдвиг по битам\n");
	Space(47); printf("введённого Вами числа в выбранную Вами сторону.\n");
	Space(50); printf("--------------------------------------------------\n\n");

	//Ввод данных и проверка корректности

	// Ввод числа
	Space(50); printf("  | Введите число от 0 до 65 535\n");
	Space(50); printf(">>| ");
	if (scanf_s("%hu", &userNumber) == 0)  //Проверка на введение символа, отличного от числа
	{
		Space(50); printf("Вы ввели символ. Пожалуйста, будьте внимательны!\n\n");
		getchar() != '\0';
	}
	lineBreak;

	// Ввод сдвига
	Space(50); printf("  | Введите количество сдвигов\n");
	Space(50); printf(">>| ");
	if (scanf_s("%hu", &userShift) == 0)  //Проверка на введение символа, отличного от числа
	{
		Space(50); printf("Вы ввели символ. Пожалуйста, будьте внимательны!\n\n");
		getchar() != '\0';
	}
	lineBreak;

	//Меню выбора сдвига
	Space(50); printf("  | Выбериет направление, в котором необходимо\n");
	Space(50); printf("  | сдвинуть число\n");
	Space(50); printf("  | \"1\" - Сдвинуть число вправо\n");
	Space(50); printf("  | \"2\" - Сдвинуть число влево\n");
	Space(50); printf(">>|  ");
	if (scanf_s("%hu", &direction) == 0)  //Проверка на введение символа, отличного от числа
	{
		Space(50); printf("Вы ввели символ. Пожалуйста, будьте внимательны!\n\n");
		getchar() != '\0';
	}


	// Вывод чисел
	Space(50); printf("--------------------------------------------------\n");
	Space(11); printf("Ваши данные\n");
	Space(50); printf("        Число:\n");
	Space(50); printf("               %u\n", userNumber);
	Space(50); printf("               -------------------\n");
	Space(19); 
	for (index = 15; index >= 0; index--)
	{
		if ((userNumber >> index) & 1) printf("1"); else printf("0");
		if (index % 4 == 0) printf(" ");
	}
	lineBreak;
	Space(50); printf("--------------------------------------------------\n");

	// Осуществление выбора сдвига
	switch (direction)
	{
	case 1:
	{
		Space(34); printf("Вы выбрали \"Сдвинуть число вправо\"\n");
		for (index = 0; index < userShift; index++)
		{
			// Проверка, является ли последний символ двоичного числа единицей 
			if (userNumber % 2 == 1)
			{
				//Если да, единица помещается в начало двоичного числа
				userNumber >>= 1;
				userNumber += 1 << 15;
			}
			else userNumber >>= 1;
		}
		break;
	}
	case 2:
	{
		Space(33); printf("Вы выбрали \"Сдвинуть число влево\"\n");
		for (index = 0; index < userShift; index++)
		{
			// Проверка, является ли первый символ двоичного числа единицей
			if (userNumber & (1 << 15))
			{
				// Если да, единица помещается в конец двоичного числа
				userNumber <<= 1;
				userNumber += 1;
			}
			else userNumber <<= 1;
		}
		break;
	}
	default:
	{
		Space(23); printf("Операция не определена.\n");
		break;
	}
	}
	Space(50); printf("--------------------------------------------------\n");
	Space(12); printf("Новые данные\n");
	Space(50); printf("        Число:\n");
	Space(50); printf("               %u\n", userNumber);
	Space(50); printf("               -------------------\n");
	Space(19);

	// Вывод конечного ответа
	for (index = 15; index >= 0; index--)
	{
		if ((userNumber >> index) & 1) printf("1"); else printf("0");
		if (index % 4 == 0) printf(" ");
	}
	lineBreak;
	Space(50); printf("--------------------------------------------------\n");
	Space(20); printf("Программа завершена!\n");
}