#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable : 4996)

#define q 70
#define lineBreak printf("\n")
#define Space(lenghtString) for (int i = 0; i < ((80-lenghtString)/2); i++) printf(" ")

int ind(int* M, int SIZE, int n); //возвращет индекс элемента массива
int main()
{
	setlocale(LC_ALL, "Rus");


	Space(24); printf("Лабораторная работа # 11\n\n");
	Space(38); printf("Задача Джонсона для нескольких станков\n\n");
	Space(57); printf("Программа читает из файла кол-во деталей, станков и время\n");
	Space(51); printf("обработки каждой детали на каждом станке. На выходе\n");
	Space(58); printf("программа возвращает оптимальную очередь обраюотки и время\n");
	Space(60); printf("------------------------------------------------------------\n");
	lineBreak;

	// Переменные
	int detailCount = 0; // кол-во деталей
	int machineCount = 0; //кол-во станков
	int maxNumber = 0; // маскимальное число
	int** matrizeofTimes = NULL; //массив, в которм будет хранится время

	Space(q); printf("  | Открытие файла\n");
	Space(q); printf(">>| . . .\n");

	//Открытие файла и чтение данных
	FILE* file;
	if((file = fopen("qwe.txt", "r")) == NULL)
	{
		Space(q); perror("!!| Произошла ошибка чтения файла!\n");
		exit(0);
	}
	Space(q); printf("  | Файл успешно открыт!\n");
	Space(q); printf("  |------------------------------\n");
	// Если надо прочитать данные с клавиатуры, раскомментируйте следующие строки
	//printf("Введиет кол-во деталей\n");
	//scanf_s("%d", &detailCount);
	//printf("Введиет кол-во станков\n");
	//scanf_s("%d", &machineCount);
	fscanf_s(file, "%d", &detailCount);
	fscanf_s(file, "%d", &machineCount);

	//Чтение времени и нахождение максимального значения
	matrizeofTimes = (int**)malloc(detailCount * sizeof(int*));
	for (int i = 0; i < detailCount; i++)
	{	
		matrizeofTimes[i] = (int*)malloc((machineCount+1) * sizeof(int));
		for (int j = 0; j < machineCount+1; j++)
		{
			if (j == machineCount) matrizeofTimes[i][j] = 1;   //Доп. столбец служит идентификаторов при дальнейшей работе с массивом
			else fscanf_s(file, "%d", &matrizeofTimes[i][j]);  //scanf_s("%d", &matrizeofTimes[i][j]);
			if (matrizeofTimes[i][j] > maxNumber) maxNumber = matrizeofTimes[i][j];
		}
	}
	fclose(file);


	//Формирование очереди
	int* queue = (int*)malloc(sizeof(int) * detailCount); //Массив Р, хранит последовательность обработки деталей
	int left = 0;                                         //левая граница массива
	int right = detailCount - 1;                          //правая граница массива
	int medium = (machineCount / 2);                      //середина. необходима чтобы разделить несколько станков.
	int* Deletes = (int*)malloc(sizeof(int) * detailCount); //массив для вывода порядка удаления
	int numder = 0;                                          //счётчик
	for (int MinimumCheck = 1; MinimumCheck <= maxNumber; MinimumCheck++)
	{
		for (int ColumnMatrizeofTimes = 0; ColumnMatrizeofTimes < machineCount; ColumnMatrizeofTimes++)
		{
			for (int StringMatrizeofTimes = 0; StringMatrizeofTimes < detailCount; StringMatrizeofTimes++)
			{
				if ((matrizeofTimes[StringMatrizeofTimes][ColumnMatrizeofTimes] == MinimumCheck) && (matrizeofTimes[StringMatrizeofTimes][machineCount] == 1))
				{
					Deletes[numder] = StringMatrizeofTimes;
					numder++;
					if (ColumnMatrizeofTimes < medium)
					{
						queue[left] = StringMatrizeofTimes;
						left++;
					}
					else if (ColumnMatrizeofTimes >= medium)
					{
						queue[right] = StringMatrizeofTimes;
						right--;
					}
					matrizeofTimes[StringMatrizeofTimes][machineCount] = 0;  //помечаем, что эта строка уже рассмотрена
				}
			}	
		}
	}

	//вывод очереди
	Space(q); printf("  | Оптимальная очередль обработки деталей\n");
	Space(q); printf(">>| ");
	for (int i = 0; i < detailCount; i++) printf("%d ", queue[i] + 1);
	lineBreak;
	Space(q); printf("  |-------------------------------------------\n");

	for (int i = 0; i < detailCount; i++)
	{
		Space(q); printf("  | %3d деталь | ", i + 1);

		for (int j = 0; j < machineCount; j++)
		{
			printf("%3d | ", matrizeofTimes[i][j]);
		}
		printf("Удалена на %d шаге\n", ind(Deletes, detailCount, i)+1);
	}
	free(Deletes);
	Space(q); printf("  |-------------------------------------------\n");
	Space(q); printf("  | График Ганта\n");
	Space(q); printf("  | ");
	//График Ганта
	lineBreak;
	for (int i = 0; i < machineCount; i++)  //счётчик по количеству станков
	{
		Space(q);
		printf("  | Станок #%d: ", i + 1);
		for (int indexR = 0; indexR < detailCount; indexR++)
		{
			for (int j = 0; j < matrizeofTimes[queue[indexR]][i]; j++)
			{
				printf("%d ", queue[indexR] + 1);
			}
		}
		lineBreak;
	}
	Space(q); printf("  |-------------------------------------------\n");

	//Подсчёт времени на каждом станке. Выводим максимальный
	int* Time = NULL;
	Time = (int*)malloc(sizeof(int) * machineCount);
	for (int i = 0; i < machineCount; i++) *(Time + i) = 0;

	for (int iteracia = 0; iteracia < (detailCount + machineCount - 1); iteracia++)
	{
		int k = iteracia;
		for (int timeCount = 0; timeCount < machineCount; timeCount++)  //присваиваем значения
		{
			if ((k>=0)&&(k < detailCount)&&(Time))
			{
				Time[timeCount] += matrizeofTimes[queue[k]][timeCount];
			}
			k--;
		}
		for (int timeCount = 0; timeCount < machineCount-1; timeCount++)
		{
			if ((Time[timeCount + 1] < Time[timeCount]) && (Time[timeCount + 1] >= 0) && (Time[timeCount] > 0))
			{
				Time[timeCount + 1] = Time[timeCount];
			}
		}
	}
	Space(q); printf("  | Время обработки всех деталей: ");
	maxNumber = 0;
	for (int i = 0; i < machineCount; i++)
	{
		if (maxNumber < Time[i]) maxNumber = Time[i];
	}
	printf("%d", maxNumber);
	lineBreak;
	Space(q); printf("  |-------------------------------------------\n");
	
	//резня
	free(Time);
	free(queue);
	for (int i = 0; i < detailCount; i++) free(matrizeofTimes[i]);
	free(matrizeofTimes);
}
int ind(int* M, int SIZE, int n)
{
	for (int i = 0; i < SIZE; i++)
		if (M[i] == n)
			return i;
	return -1;
}