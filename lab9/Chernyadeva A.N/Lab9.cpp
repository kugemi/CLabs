#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h> // для динамики
#include <iostream>
#define Space(lenghtString) for (int i = 0; i < ((80-lenghtString)/2); i++) printf(" ")


//Объявление глобальных переменных
// 
// Влияет на выбор сортировки текста.
int flag = 1; 

//Раздел функций
// 
// Добавляет в массив строк arrayString новую строку uString
char** addString(char** arrayString, int stringCount, char* uString, int lenghtString);

//Копируетс строчку s2 в строку s1
char* CopyingString(char* s1, char* s2);

//Сравнивает строки s1 и s2
int CompareString(char* s1, char* s2);

//Сортирует массив строк text размера strcout по алфавиту
char** SortingString(char** text, int strcout);

//Самая важная функция
int TADAAA();

int main()
{
	//Русский язык
	setlocale(LC_ALL, "Rus");

	// Объявление перемнных
	char userChar = NULL;     // Символ, введённый пользователем
	char* userString = NULL;  // Массив символов, строка пользователя 
	char** text = NULL;       // Массив строк
	int lenght = 0,           // Длина каждой строки userString
	    stringCount = 0,      // Количество строк в массиве text
	    i = 0,                // Счётчик
		choice = 0;           // Выбор сортировки
	const int k = 70;         // Красотишная переменная
	


	printf("\n");
	Space(36); printf("Программа сортирует введённые строки\n");
	Space(35); printf("по алфавиту или в обратном порядке.\n");
	Space(30); printf("!!!  Программа не принимает  !!!\n");
	Space(30); printf("!!! на ввод русские символы. !!!\n");
	Space(38); printf("--------------------------------------\n\n");
	Space(23); printf("Начинайте вводить текст\n");
	Space(64); printf("----------------------------------------------------------------\n");
	//Объявляем бесконечный цикл, который будет считать кол-во введённых строк
	for (stringCount = 0; ; stringCount++)
	{
		Space(k); printf("  | Строка №%d\n", stringCount+1);
		Space(k); printf(" \x10| ");

		//Обнуляем строку, дабы не было в ней мусора, и длину строки
		userString = NULL;
		lenght = 0;
		while ((userChar = getchar()) != '\n')
		{
			//Выделяем и распределяем память для строки. Увеличивается с каждым новым символом.
			userString = (char*)realloc(userString, sizeof(char) * (lenght + 1));
			if (userString)
			{
				userString[lenght] = userChar;
				lenght++;
			}
		}
		Space(k); printf("  |\n");


		//Выделяем память для '\0', проверяем выделение памяти и записываем его в строку
		userString = (char*)realloc(userString, sizeof(char) * (lenght + 1));
		if (userString) userString[lenght] = '\0';
		lenght++;

		//Если пользователь ввёл пустую строку, расчищаем память и выходим из цикла for
		if (userString[0] == '\0')
			{
				free(userString);
				break;
			}

		//Записываем строку в массив строк
		if (lenght > 1) text = addString(text, stringCount, userString, lenght);

		//Расчищаем память 
		free(userString);
	}

	//Выбор сортировки текста.
	Space(k); printf("  ------------------------------------\n");
	Space(k); printf("  | В каком порядке вывести строки?\n");
	Space(k); printf("  | Нажмите нужную цифру на клавиатуре. \n");
	Space(k); printf(" !| Если ваш символ будет отличаться от выбора в меню,\n");
	Space(k); printf(" !| будет осуществлена алфавитная сортировка.\n");
	Space(k); printf("  | \"1\" - Сортировка А \x10 Z \n");
	Space(k); printf("  | \"2\" - Сортировка Z \x10 A \n");
	Space(k); printf(" \x10| ");
	scanf_s("%d", &choice);
	switch (choice)
	{
	case 1:
		Space(k); printf(" !| Вы выбрали сортировку А \x10 Z\n");
		flag = 1;
		break;
	case 2:
		Space(k); printf(" !| Вы выбрали сортировку Z \x10 A\n");
		flag = 0;
		break;
	default:
		Space(k); printf(" !| По умолчанию выбрана сортировка А \x10 Z\n");
		break;
	}
	Space(k); printf("  ------------------------------------\n");

	//Вывод исходного текста на экран
	Space(k); printf("  |      Ваши строки\n");
	for (i = 0; i < stringCount; i++)
	{
		if (text) 
		{
			Space(k); printf("| |#%d: %s\n", i + 1, text[i]);
		}
	}
	Space(k); printf("  ------------------------------------\n");
	
	//Сортируем текст
	text = SortingString(text, stringCount);

	Space(k); printf("  |      Ваши отсортированные строки\n");

	//Выводим на экран
	for (i = 0; i < stringCount; i++)
	{
		if (text)
		{
			Space(k); printf("| |#%d: %s\n", i + 1, text[i]);
		}
	}

	//Чистим память
	Space(k); printf("  ------------------------------------\n");
	Space(k); printf(" !|      Чистка памяти! Стираем данные!\n");
	Space(k); printf("  ------------------------------------\n");
	for (i = 0; i < stringCount; i++)
	{
		text[i] = NULL;
		free(text[i]);		
	}
	free(text);
	Space(k); printf("  | Текст удалён \n");
	Space(k); printf("  ------------------------------------\n");

	TADAAA();
}

char** addString(char** arrayString, int stringCount, char* uString, int lenghtString)
{
	if (stringCount == 0)  //Если кол-во строк равно нулю...
	{
		arrayString = new char* [stringCount + 1];  //...то мы выделяем память для одной строчки в исходном массиве строк
	}
	else
	{
		char** copy = new char* [stringCount + 1];  //Выделяем память для строчки 
		for (int i = 0; i < stringCount; i++)  // копируются все предыдущие строчки, которые уже были внесены в массив строк
		{
			copy[i] = arrayString[i];
		}
		delete[] arrayString;  //освобождаем память в исходном массиве 
		arrayString = copy;    //и сохраняется копия со всеми введёнными строками
	}

	//Добавляется последняя введённая строчка
	arrayString[stringCount] = new char[lenghtString + 1];
	CopyingString(arrayString[stringCount], uString);

	//Возвращается массив строк
	return arrayString;
}
char* CopyingString(char* s1, char* s2) // функция копирования одной строки в дргую
{
	char* ptrs1 = s1;
	while ((*s1++ = *s2++) != 0);
	return ptrs1;
}
int CompareString(char* s1, char* s2) //Функция сравнения двух строк 
{
	int lenght = 0;  //максимальная длина двух строк
	char* ptrs1 = s1; // Указатель на первую строку
	char* ptrs2 = s2; // Указатель на вторую строку
	int order = 2;   // Влияет на выбор пользователя, в каком порядке вывести строки

	// В бесконечном цикле осуществляется подсчёт длины самой большой строки 
	// p.s. потому что strlen не работает на них
	for (int i = 0; ; i++)
	{
		if ((*(ptrs1 + i)) || (*(ptrs2 + i))) lenght++;
		else break;
	}

	if (flag % 2 == 0)
	{
		order = 3;
	}
	// Выполняется посимвольное сравнение двух строк
	for (int i = 0; i < lenght; i++)
	{
		if (*(ptrs1 + i) > *(ptrs2 + i))  //Если первая строка по алфавиту стоит позже второй...
		{
			return int (order % 2);  //... то по дефолту возвращаем 0, если надо в обратном, вернёт 1
		}
		if (*(ptrs1 + i) < *(ptrs2 + i)) //Если первая строка по алфавиту стоит раньше второй...
		{
			return int ((order +1) % 2);  //... то по дефолту возвращаем 1, если надо в обратном, вернёт 0
		}
	}
	// Если ни то, ни то условие не выполнилось, т.е строки равны, возвращаем 0
	return 0;

}
char** SortingString(char** text, int strcout)
{
	// Создаём дубликат исходного массива строк
	char** stringFROMtexts = new char* [strcout];  
	for (int i = 0; i < strcout; i++)
	{
		stringFROMtexts[i] = text[i];
	}

	//Сортируем
	for (int i = 0; i < strcout - 1; i++)
	{
		for (int j = i + 1; j < strcout; j++)
		{
			if (!CompareString(stringFROMtexts[i], stringFROMtexts[j]))
			{
				//создаём новый указатель 
				char* emptyString = new char[strlen(stringFROMtexts[i])];

				//*emptyString = *stringFROMtexts[i];
				//*stringFROMtexts[i] = *stringFROMtexts[j];
				//*stringFROMtexts[j] = *emptyString;
				// 
				// 
				CopyingString(emptyString, stringFROMtexts[i]);
				CopyingString(stringFROMtexts[i], stringFROMtexts[j]);
				CopyingString(stringFROMtexts[j], emptyString);
			}
		}
	}

	return stringFROMtexts;
}
int TADAAA()
{
	printf("\n");
	printf("                   @@@@                  \n");
	printf("                 @@@ @@             @@   \n");
	printf("               @@@    @@          @@@@   \n");
	printf("             @@@      @@      @@@@@  @   \n");
	printf("            @@@        @   @@@@      @   \n");
	printf("           @@          @@@@@         @   \n");
	printf("          @@@@@@@@@    @@            @   \n");
	printf("         @@      @@@     @@@@@@@     @   \n");
	printf("        @@         @@   @@     @@@   @       Спасибо, что пользуетесь\n");
	printf("        @           @  @         @@  @       нашими программами!\n");
	printf("       @@           @@@           @@ @   \n");
	printf("      @@@            @             @ @   \n");
	printf("      @@@      @@    @             @ @   \n");
	printf("     @@ @      @@   @@             @ @   \n");
	printf("     @  @           @      @@      @ @   \n");
	printf("    @@  @@         @@@     @@      @ @   \n");
	printf("    @    @@       @@ @             @ @   \n");
	printf("    @     @@@   @@ @ @@           @@ @   \n");
	printf("   @@       @@@@@  @  @@         @@  @   \n");
	printf("   @@              @   @@       @@   @@  \n");
	printf("   @             @@@@@  @@@@@@@@@     @  \n");
	printf("   @              @@@@                @@ \n");
	printf("  @@                                   @ \n");
	printf("  @@                                   @@\n");
	printf("-----------------------------------------\n");
	return 0;
}