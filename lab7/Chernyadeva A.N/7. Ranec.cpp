#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <math.h>

#define lineBreak printf("\n")
#define Space(lenghtString) for (int i = 0; i < ((80-lenghtString)/2); i++) printf(" ")

void main()
{
	//Русский язык
	setlocale(LC_ALL, "Rus");

	// Константы
	const int max_items = 10;             // Ограничение кол-ва предметов
	const int max = 1024;                 // Ограничение массивов
	const int k = 70;

	 //        Переменные, вводимые с клавиатуры
	unsigned int itemNumber = 0;          // Количество предметов 
	unsigned int itemWeight[max] = { 0 }; // Вес каждого предмета
	unsigned int itemUsefull[max] = { 0 };// Полезность каждого предмета
	unsigned int briefcaseCapacity = 0;   // Вместимость портфеля

	//         Переменные программы
	unsigned int runUsefull = 0;          // Текущая полезность предметов в переборе
	unsigned int runWeight = 0;           // Текущий вес предметов в переборе
	unsigned int maxUsefull = 0;          // Максимальная полезность вмещающихся в ранец предметов
	unsigned int maxWeight = 0;           // Максимальный вес вмещающихся в ранец предметов
	unsigned int numberBruteforse = 0;    // Номер перебора с ответом
	unsigned int mask = 1;                // Маска для выборки

	//         Счётчики
	int index = 0;                        // Счётчик
	int Jndex = 0;                        // Счётчик, дублирующий index в цикле while для его изменения

	//Приветственное сообщение, ввод данных
	lineBreak;
	Space(61); printf("Программа поможет собрать Ваш ранец с оптимальной полезностью\n");
	Space(60); printf("------------------------------------------------------------\n");
	lineBreak;

	// Ввод и проверка вместимости ранца
	Space(k); printf("  | Введите вместимость Вашего ранца\n");
	Space(k); printf(">>| ");
	while (scanf_s("%ud", &briefcaseCapacity) == 0)
	{
		Space(k); printf("  | [X] Вы ввели символ.\n");
		Space(k); printf("  | [X] Пожалуйста, будьте внимательны!\n");
		getchar() != '\0';
		Space(k); printf(">>| ");
	}
	lineBreak;

	//Ввод и проверка кол-ва предметов
	Space(k);; printf("  | Введите количество предметов, которое бы Вы\n");
	Space(k); printf("  | хотели поместить в ранец.\n");
	Space(k); printf("  | Кол-во не должно превышать %d\n", max_items);
	Space(k); printf(">>| ");
	while ((scanf_s("%ud", &itemNumber) == 0) || (itemNumber > max_items))
	{
		if (itemNumber > max_items)
		{
			Space(k); printf("  | [X] Вы ввели число больше %d.\n", max_items);
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


	// Ввод массы и полезности каждого предмета
	Space(k); printf("  | Введите массу и ползеность каждого предмета\n");
	for (index = 0; index < itemNumber; index++)
	{
		Space(k); printf("  |\n");
		Space(k); printf("  | Предмет номер %d\n", index+1);
		Space(k); printf(">>| - Масса предмета: ");
		scanf_s("%ud", &itemWeight[index]);
		Space(k); printf(">>| - Полезность: ");
		scanf_s("%ud", &itemUsefull[index]);
	}
	Space(k); printf("  -----------------------------");
	lineBreak; lineBreak;

	// Вывод введённых данных в таблице
	Space(k); printf("    Ваши предметы:\n");
	printf(" |----------------------------------------------------------------------\n");
	printf(" | Номер:  ");
	for (index = 0; index < itemNumber; index++) printf("#%3d| ", index+1);
	lineBreak;
	printf(" |----------------------------------------------------------------------\n");
	printf(" | Weight: ");
	for (index = 0; index < itemNumber; index++) printf("%4d| ", itemWeight[index]);
	lineBreak;
	printf(" | Usefull:");
	for (index = 0; index < itemNumber; index++) printf("%4d| ", itemUsefull[index]);
	lineBreak;
	printf(" |----------------------------------------------------------------------\n");
	printf(" | Вместимость ранца: %d\n", briefcaseCapacity);
	printf(" |----------------------------------------------------------------------\n");

	for (index = 0; index < pow(2, itemNumber); index++)
	{
		mask = 1;       //"Обнуление" маски, присваивание изначального значения
		runUsefull = 0; // Обнуление текущей полезности
		runWeight = 0;  // Обнуление текущего веса
		
		// Осуществляется перебор по битам index 
		for (Jndex = 0; Jndex < itemNumber; Jndex++)
		{
			if (mask & index) //Если бит на месте есть...
			{
				runUsefull += itemUsefull[Jndex];   // ... то суммируется полезность и вес предмета на месте кол-ва итераций Jndex
				runWeight += itemWeight[Jndex];
			}
			mask <<= 1; 
			//printf("\\\ni = %d\nJndex = %d\nmask = %d\nrunUsefull = %d\nrunWeight = %d\nto_samoe = %d\n\n", index, Jndex, mask, runUsefull, runWeight, to_samoe);
		}
		// Если текущий вес меньше вместимости ранца И текущая полезность выше максимальной...
		if ((runWeight <= briefcaseCapacity) && (runUsefull >= maxUsefull))
		{
			// ... то в максимальную полезность (оптимум) записывается текущая,
			maxUsefull = runUsefull;
			// в максимальный вес записывается текущее.
			maxWeight = runWeight;
			// в номер "той самой" итерации сохраняется значение index
			numberBruteforse = index;
		}
		
	}
	// Вывод решения
	lineBreak;
	Space(k); printf("  | Вам стоит взять с собой предметы:\n");
	Space(k); printf("  | ");

	mask = 1; // Присваивание изначального значения

	//Пробегаемся по битам числа numberBruteforse и выводим номера предметов
	for (index = 0; index <= itemNumber; index++)
	{
		if (mask & numberBruteforse) printf("#%d   ", index + 1);
		mask <<= 1;
	}


	lineBreak;
	Space(k); printf("  ------------------------------------\n");
	Space(k); printf("  | Полезность предметов = %d\n", maxUsefull);
	Space(k); printf("  | Масса предметов      = %d\n", maxWeight);
}