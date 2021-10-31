#include <stdio.h>
#include <conio.h>
#include <locale.h>

// Блок "Жизнь сделать проще"
#define lineBreak printf("\n")
#define Space(lenghtString) for (int i = 0; i < ((80-lenghtString)/2); i++) printf(" ")
#define lineTable(n) for (int i = 0; i < n; i++) printf("|-----")  //Очерчивание таблички
#define lableTable(n) for (int i = 0; i < n/2; i++) printf("      ")  //Выравнивание названия по центру таблицы

int main()
{
	//Русский язык
	setlocale(LC_ALL, "Rus");

	//Тестовые массивы, чтобы не вводить с клавы
	//Чтобы использовать матрицу horizontalSymmetry, раскомментируйте строки с номером 1
	int horizontalSymmetry[5][5] = {
		{1, 2, 3, 4, 5},
		{2, 3, 4, 5, 6},
		{0, 0, 0, 0, 0},
		{2, 3, 4, 5, 6},
		{1, 2, 3, 4, 5}
	};
	//Чтобы использовать матрицу verticalSymmetry, раскомментируйте строки с номером 2
	int verticalSymmetry[5][5] = {
		{1, 2, 3, 2, 1},
		{2, 3, 4, 3, 2},
		{3, 4, 5, 4, 3},
		{4, 5, 6, 7, 6},
		{5, 6, 7, 6, 5}
	};
	//Чтобы использовать матрицу centralSymmetry, раскомментируйте строки с номером 3
	int centralSymmetry[5][5] = {
		{1, 2, 3, 4, 5},
		{6, 7, 8, 9, 0},
		{1, 2, 3, 2, 1},
		{0, 9, 8, 7, 6},
		{5, 4, 3, 2, 1}
	};

	const int k = 70;         // Для оформления
	int userArray[99][99];  // Общий двумерный массив, который пользователь урезает введением размера таблицы.
	int iString = 0;          // Счётчик строк матрицы
	int jColumn = 0;          // Счётчик столбцов матрицы
	int flag = 1;             // Флаг на противоречие
	int userNumber = 0;       // Вводимый размер матрицы

	//Приветственное сообщение
	lineBreak;
	Space(53); printf("Программа анализирует Вашу таблицу на горизонтальную,\n");
	Space(42); printf("вертикальную и центральную симметричность.\n");
	Space(57); printf("p.s. Для того, чтобы понять, как выглядит симметричность,\n");
	Space(45); printf("раскомментируйте соответствующие строки кода.\n");
	Space(60); printf("------------------------------------------------------------\n");
	lineBreak; 

	//Ввод и проверка введённого размера матрицы
	Space(k); printf("  | Введите размер таблицы.\n");
	Space(k); printf("  | Размер должен быть нечётным числом\n");
	Space(k); printf("  | И не превышать 99.\n");
	Space(k); printf(">>| ");
	while ((scanf_s("%d", &userNumber) == 0) || (userNumber > 99) || (userNumber%2==0))
	{
		if (userNumber > 99)
		{
			Space(k); printf("  | [X] Вы ввели число большее 99.\n");
			Space(k); printf("  | [X] Пожалуйста, будьте внимательны!\n");
			getchar() != '\0';
		}
		else if (userNumber % 2 == 0)
		{
			Space(k); printf("  | [X] Вы ввели чётное число.\n");
			Space(k); printf("  | [X] Пожалуйста, будьте внимательны!\n");
			getchar() != '\0';
		}
		else 
		{
			Space(k); printf("  | [X] Вы ввели символ.\n");
			Space(k); printf("  | [X] Пожалуйста, будьте внимательны!\n");
			getchar() != '\0';
		}
		Space(k); printf(">>| ");
	}
	lineBreak;

	//Ввод матрицы
	//Если необходимо протестировать тестовые матрицы, закомментриуйте строки 89-98 с помощью /**/
	for (iString = 0; iString < userNumber; iString++)
	{
		Space(k); printf("  | Введите строку #%d\n", iString+1);
		for (jColumn = 0; jColumn < userNumber; jColumn++)
		{
			Space(k); printf(">>| ");
			scanf_s("%d", &userArray[iString][jColumn]);
		}
	}
	Space(k); printf("  |----------");

	lineBreak; lineBreak;

	//Вывод матрицы на экран
	Space(k); lableTable(userNumber); printf("Таблица\n");// Название таблицы
	Space(k); lineTable(userNumber); printf("|");        // Вывод первой очерчивающей строки 
	lineBreak;

	for (iString = 0; iString < userNumber; iString++)
	{
		Space(k); printf("|");
		for (jColumn = 0; jColumn < userNumber; jColumn++)
		{
			//№1 printf("%5d|", horizontalSymmetry[iString][jColumn]);  //Горизонтальная
			//№2 printf("%5d|", verticalSymmetry[iString][jColumn]);  //Вертикальная
			//№3 printf("%5d|", centralSymmetry[iString][jColumn]);  //Центральная
			printf("%5d|", userArray[iString][jColumn]);
		}
		lineBreak;
		Space(k); lineTable(userNumber); printf("|");
		lineBreak;
	}

	//Обработка данных и вывод ответа

	lineBreak; lineBreak;
	Space(k); printf("  | Анализ Вашей таблицы:\n");
	
	//Исследование на горизонтальную сииметричность
	Space(k); printf(">>| Горизонтальная симметричность: ");
	for (iString = 0; iString < userNumber /2; iString++)
	{
		for (jColumn = 0; jColumn < userNumber; jColumn++)
		{
			//№1 if (horizontalSymmetry[iString][jColumn] != horizontalSymmetry[userNumber - iString - 1][jColumn])  //Горизонтальная
			//№2 if (verticalSymmetry[iString][jColumn] != verticalSymmetry[userNumber - iString - 1][jColumn])  //Вертикальная
			//№3 if (centralSymmetry[iString][jColumn] != centralSymmetry[userNumber - iString - 1][jColumn])  //Центральная
			if (userArray[iString][jColumn] != userArray[userNumber - iString - 1][jColumn])
			{
				flag = 0;
				printf("-\n");
				break;
			}
		}
		if (flag == 0) break; //Выход из цикла
	}
	if (flag == 1) printf("+\n");


	
	//Исследование на вертикальную сииметричность
	Space(k); printf(">>| Вертикальная симметричность:   ");
	flag = 1;
	for (iString = 0; iString < userNumber; iString++)
	{
		for (jColumn = 0; jColumn < userNumber /2; jColumn++)
		{
			//№1 if (horizontalSymmetry[iString][jColumn] != horizontalSymmetry[iString][userNumber - jColumn - 1]) //Горизонтальная
			//№2 if (verticalSymmetry[iString][jColumn] != verticalSymmetry[iString][userNumber - jColumn - 1])  //Вертикальная
			//№3 if (centralSymmetry[iString][jColumn] != centralSymmetry[iString][userNumber - jColumn - 1])  //Центральная
			if (userArray[iString][jColumn] != userArray[iString][userNumber - jColumn - 1])
			{
				flag = 0;
				printf("-\n");
				break;
			}
		}
		if (flag == 0) break; //Выход из цикла
	}
	if (flag == 1) printf("+\n");



	//Исследование на центральную сииметричность
	Space(k); printf(">>| Центральная симметричность:    ");
	flag = 1;
	for (iString = 0; iString <= userNumber / 2; iString++)
	{
		for (jColumn = 0; jColumn < userNumber / 2; jColumn++)
		{
			//№1 if (horizontalSymmetry[iString][jColumn] != horizontalSymmetry[userNumber - iString - 1][userNumber - jColumn - 1]) //Горизонтальная
			//№2 if (verticalSymmetry[iString][jColumn] != verticalSymmetry[userNumber - iString - 1][userNumber - jColumn - 1])  //Вертикальная
			//№3 if (centralSymmetry[iString][jColumn] != centralSymmetry[userNumber - iString - 1][userNumber - jColumn - 1])  //Центральная
			if (userArray[iString][jColumn] != userArray[userNumber - iString - 1][userNumber - jColumn - 1])
			{
				flag = 0;
				printf("-\n");
				break;
			}
		}
		if (flag == 0) break; //Выход из цикла
	}
	if (flag == 1) printf("+\n");

}