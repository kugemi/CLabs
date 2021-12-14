#include<stdio.h>
#include<conio.h>
#include<locale.h>
#include<stdlib.h>
#include <string.h>
#include<iostream>
#pragma warning(disable : 4996)
void Order(int* Sequence, int number, int** time)
{
	int left = 0;
	int right = number - 1;
	int min=0;// минимальный элемент матрицы
	int detail;// деталь
	int machine;//станок
	while (right -left !=-1)
	{
		int flag = 1;
		for (int g = 0; g < number; g++)
		{
			if (((*(*(time + g) + 2) == 1) && (**(time + g) < min)) || (flag == 1))
			{
				min = **(time + g);
				detail = g;
				machine = 0;
				flag = 0;
			}
			if (*(*(time + g) + 2) == 1 && *(*(time + g) + 1) < min)
			{
				min = *(*(time + g) + 1);
				detail = g;
				machine = 1;
			}
		}
		*(*(time + detail) + 2) = 0;
		if (machine==1) { *(Sequence + right) = detail + 1; right--; }
		else { *(Sequence + left) = detail + 1; left++; }
	}
}
void GanttChart(int* Sequence, int** time, int NumberParts)
{
	printf("\n1 machine: ");
	for (int i=0;i<NumberParts;i++)
	{
		for (int k = 0; k < **(time + *(Sequence + i) - 1);k++)
		{
			printf("%i", *(Sequence + i));
		}
	}
	printf("\n2 machine: ");
	int time1=0;//времня 1 станка
	int time2=0;//время 2 станка
	for (int i = 0; i < NumberParts; i++)
	{
		int Spaces = 0;// пробелы
		time1 = time1 + **(time + *(Sequence + i) - 1);
		if (time2 < time1)
		{
			for (int k = 0; k < (time1 - time2); k++)
			{
				printf(" ");
				Spaces++;
			}
			for (int k = 0; k < *(*(time + *(Sequence + i) - 1) + 1); k++)
			{
				printf("%i", *(Sequence + i));
			}
		}
		else
		{
			for (int k = 0; k < *(*(time + *(Sequence + i) - 1) + 1); k++)
			{
				printf("%i", *(Sequence + i));
			}
		}
		time2 = time2+Spaces + *(*(time + *(Sequence + i) - 1) + 1);
	}
	printf("\nTotal processing time: "); 
	if (time1 < time2)
		printf("%i", time2);
	else printf("%i", time1);
}
void main()
{
	FILE* avt;
	int NumberParts;// количесво деталей
	int** time;

	if ((avt = fopen("time.txt", "r")) == NULL)
	{
		printf("An incomprehensible thing happened");
		exit(1);
	}
	fscanf_s(avt, "%i", &NumberParts);
	time = (int**)malloc(NumberParts * sizeof(int*));
	for (int i = 0; i < NumberParts; i++)
	{
		time[i] = (int*)malloc(2 * sizeof(int));
		fscanf_s(avt, "%i", &*(*(time + i)));
		fscanf_s(avt, "%i", &*(*(time + i) + 1));
		*(*(time + i) + 2) = 1;
	}
	fclose(avt);
	printf("%i\n", NumberParts);
	for (int i = 0; i < NumberParts; i++)
	{
		printf("%i part: %i  ", i + 1, *(*(time + i)));
		printf("%i\n", *(*(time + i) + 1));
	}
	int* Sequence = (int*)malloc(NumberParts * sizeof(int));
	Order(Sequence, NumberParts, time);
	printf("Processing sequence: ");
	for (int i = 0; i < NumberParts; i++) { printf("%i,", *(Sequence + i)); };
	GanttChart(Sequence, time, NumberParts);
}