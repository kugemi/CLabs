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
	unsigned int maxWeight = 0;
	unsigned int runPosition[max] = { 0 };// Текущие позиции предметов, которые мы просматриваем
	unsigned int Position[max] = { 0 };   // Позиции предметов, которые точно будут в ранце

	//         Счётчики
	int index = 0;                        // Счётчик
	int Jndex = 0;                        // Счётчик, дублирующий index в цикле while для его изменения
	int numberIteration = 0;              // Счётчик числа итераций в цикле while
	int indexZeroing = 0;                 // Счётчик для обнуления массива в цикле while

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

	//Перебор всех возможных вариантов 2^кол-во предметов
	for (index = 0; index < pow(2, itemNumber); index++)
	{
		Jndex = index;   // Дублируем номер перебора, чтобы далее взаимодействовать с ним
		numberIteration = 0;       // Обнуление счётчика числа итераций в while
		runUsefull = 0; // Обнуление текущей полезности
		runWeight = 0;  // Обнуление текущего веса
		// Обнуление текущего массива номеров предметов
		for (indexZeroing = 0; indexZeroing < itemNumber; indexZeroing++) runPosition[indexZeroing] = 0;

		// Осуществляется перебор по битам номера перебора index 
		while (Jndex >= 1)
		{
			if (Jndex % 2 == 1)                   //Если бит на месте есть...
			{
				runUsefull += itemUsefull[numberIteration];   // ... то суммируется полезность и вес предмета на месте кол-ва итераций g
				runWeight += itemWeight[numberIteration];
				runPosition[numberIteration]++;                 // в массив сохраняется бит - порядковый номер добавленного в ранец предмета
			}
			numberIteration++;  // увеличиваем кол-во итераций
			Jndex /= 2;  //Переходим к следующему биту числа index 
		}
		
		// Если текущий вес меньше вместимости ранца И текущая полезность выше максимальной...
		if ( (runWeight <= briefcaseCapacity) && (runUsefull >= maxUsefull))
		{
			// ... то в максимальную полезность (оптимум) записывается текущая.
			maxUsefull = runUsefull;
			maxWeight = runWeight;
			//В отдельный массив сохраняются позиции предметов, которые точно надо положить в ранец
			for (indexZeroing = 0; indexZeroing < pow(2, itemNumber); indexZeroing++) Position[indexZeroing] = runPosition[indexZeroing];
		}

	}

	// Вывод решения
	lineBreak;
	Space(k); printf("  | Вам стоит взять с собой предметы:\n");
	Space(k); printf("  | ");
	for (index = 0; index <= itemNumber; index++) if (Position[index] == 1) printf("#%d   ", index + 1);
	lineBreak;
	Space(k); printf("  ------------------------------------\n");
	Space(k); printf("  | Полезность предметов = %d\n", maxUsefull);
	Space(k); printf("  | Масса предметов      = %d\n", maxWeight);
}