#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>

#define lineBreak printf("\n")
#define Space(lenghtString) for (int i = 0; i < ((80-lenghtString)/2); i++) printf(" ")

//Прототипы функций
int AAA(); // Надо
void Vstavki(int* notSortArr, int len);  //Функция сортировки всатвками
void Sliyanie(int* arr, int first, int last); // Функция сортировки слиянием

int main()
{
    // Призываем великую силу рандома
	srand(time(0));

	//Рашн лангуаге
	setlocale(LC_ALL, "Rus");

	//Раздел переменных
	const int k = 70;   // для оформления
	int userLenght = 0; // Размер массива, вводимый пользователем

	// Приветственное сообщение
	lineBreak;
	Space(24); printf("Лабораторная работа # 10\n\n");
	Space(57); printf("Программа сортирует массив случайных чисел по возрастанию\n");
	Space(60); printf("------------------------------------------------------------\n");
	lineBreak;

	// Проверка ввода
	Space(k); printf("  | Введите размер числового массива\n");
	Space(k); printf(">>| ");
	while ((!scanf_s("%d", &userLenght)) || (userLenght < 1))
	{
		if (userLenght < 1)
		{
			Space(k); printf("  | [X] Вы ввели отрицательное число или ноль.\n");
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

	// Массив чисел размера userLenght
	int* randomArray = (int*)malloc(userLenght * sizeof(int));

	// Заполяем массив числами и выводим их на экран
	Space(k); printf("  | Ваш неотсортированный массив:\n");
	Space(k); printf(">>| ");
	for (int i = 0; i < userLenght; i++)
	{
		*(randomArray + i) = rand();
		printf("%d ", *(randomArray + i));
	}
	
	//Осуществляем сортировку
	if (userLenght < 5) Vstavki(randomArray, userLenght);
	else Sliyanie(randomArray, 0, userLenght - 1);

	//Выводим ответ на экран
	lineBreak;
	Space(k); printf("  | \n");
	Space(k); printf("  | Ваш свежесортированный массив:\n");
	Space(k); printf(">>| ");
	for (int i = 0; i < userLenght; i++) printf("%d ", randomArray[i]);

	//Чистим память
	free(randomArray);

	lineBreak;
	Space(k); printf("  |------------------------------\n");
	AAA();
}



void Sliyanie(int* arr, int first, int last)
{
	if (first == last) return; //Ничего не вернёт или вернёт тот самый arr

	//Вызываем эту же функцию для двух половин исходного массива
	Sliyanie(arr, first, ((first + last) / 2));
	Sliyanie(arr, ((first + last) / 2) + 1, last);


	// Само тело функции, сортировка
	int* SortArray = (int*)malloc(sizeof(int) * last);  //Результурующий массив
	int iLeft = first;                                  //Счётчик по левой части массива
	int jRight = ((first + last) / 2) + 1;              //Счётчик по правой части массива
	

	/*т.е. иначе можно изобразить так :
	   arr =  3    4    8    10    6    7    9    11
	          |                    | 
	        iLeft                 jRight
	  Начало первого "массива"    Начало второго
	*/

	for (int i = 0; i <= (last - first); i++)  // last-first - это длина полученного массива
	{
		
		//Если правый "массив" закончился ИЛИ левый массив ещё не кончился
		// 
		//  * Пояснялочка:
		//  При делении нечётного массива пополам правый подмассив всегда получается больше
		//  Поэтому в случае, если левый подмассив кончился, мы дописываем элементы правого без проверки
		//  на сортировку, ибо здесь сортируются уже два отсортированных подмассива
	
		if ( (jRight > last) || ((iLeft <= ((first + last) / 2)) && (arr[iLeft] < arr[jRight])) )
		{
			// Если число из первой подстроки данного массива меньше числа из второй подстроки...
			// ... то добавляем это число в SortArray
			if (SortArray) SortArray[i] = arr[iLeft];
			iLeft++;
		}
		else
		{
			// Иначе добавляем другое число
			if (SortArray) SortArray[i] = arr[jRight];
			jRight++;
		}
	}
	// Переписываем элементы в исходный массив
	for (int i = 0; i <= (last - first); i++) if (SortArray) arr[first + i] = SortArray[i];

	// Массив SortArray не чистим, ибо вылетит ошибочка
}



void Vstavki(int* notSortArr, int len)
{
	
	int* sortArr = (int*)malloc((len) * sizeof(int)); // Сортированный массив
	if (sortArr) sortArr[0] = notSortArr[0];  // Кладём в него первый элемент
	int lenSortArray = 1;  // Длина сортированного массива
	
	for (int i = 1; i < len; i++)  // пробегаем несортированный массив
	{
		for (int j = 0; j < lenSortArray; j++) //пробегаем по всем эл-ам сортированного
		{
			if ((sortArr) && (*(notSortArr + i) < *(sortArr + j))) //если есть элемент меньше, то
			{
				for (int g = lenSortArray; g > j; g--)
				{
					*(sortArr + g) = *(sortArr + g - 1);  //сдвигаем все эл-ты вправо
				}
				*(sortArr + j) = *(notSortArr + i);  //на освободимвшееся место ставим новый эл-т
				break;
			}
			else if (j == lenSortArray - 1)  // иначе просто дописываем элемент справа
			{
				if (sortArr) *(sortArr + lenSortArray) = *(notSortArr + i);
			}
		}
		lenSortArray++;
	}

	// Переписываем в исходный массив
	for (int i = 0; i < len; i++)
	{
		if (sortArr) *(notSortArr + i) = *(sortArr + i);
	}
	free(sortArr);

	return;
}
int AAA()
{
	printf("       |\n");
	printf("       |    (             )\n");
	printf("       |   ))            ((\n");
	printf("       | <[__]          [__]>\n");
	printf("       |====== coffee? ======\n");
	return 0;
}
