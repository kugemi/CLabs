#include<stdio.h>
#include<conio.h>
#include<locale.h>
#include<stdlib.h>
#include <string.h>
#include<iostream>
#pragma warning(disable : 4996)
void Order(int* Posledovatelnost, int number, int** time)
{
	int left = 0;
	int right = number - 1;
	int min = 0;
	int detail;
	int stanok;
	while (right - left != -1)
	{
		int mask = 1;
		for (int index = 0; index < number; index++)
		{
			if (((*(*(time + index) + 2) == 1) && (**(time + index) < min)) || (mask == 1))
			{
				min = **(time + index);
				detail = index;
				stanok = 0;
				mask = 0;
			}
			if (*(*(time + index) + 2) == 1 && *(*(time + index) + 1) < min)
			{
				min = *(*(time + index) + 1);
				detail = index;
				stanok = 1;
			}
		}
		*(*(time + detail) + 2) = 0;
		if (stanok == 1) { *(Posledovatelnost + right) = detail + 1; right--; }
		else { *(Posledovatelnost + left) = detail + 1; left++; }
	}
}
void GanttChart(int* Posledovatelnost, int** time, int kolvo_Details)
{
	printf("\n1 станок: ");
	for (int index = 0; index < kolvo_Details; index++)
	{
		for (int kindex = 0; kindex < **(time + *(Posledovatelnost + index) - 1); kindex++)
		{
			printf("%i", *(Posledovatelnost + index));
		}
	}
	printf("\n2 станок: ");
	int time1 = 0;
	int time2 = 0;
	for (int index = 0; index < kolvo_Details; index++)
	{
		int spaces = 0;
		time1 = time1 + **(time + *(Posledovatelnost + index) - 1);
		if (time2 < time1)
		{
			for (int kindex = 0; kindex < (time1 - time2); kindex++)
			{
				printf(" ");
				spaces++;
			}
			for (int kindex = 0; kindex < *(*(time + *(Posledovatelnost + index) - 1) + 1); kindex++)
			{
				printf("%i", *(Posledovatelnost + index));
			}
		}
		else
		{
			for (int zindex = 0; zindex < *(*(time + *(Posledovatelnost + index) - 1) + 1); zindex++)
			{
				printf("%i", *(Posledovatelnost + index));
			}
		}
		time2 = time2 + spaces + *(*(time + *(Posledovatelnost + index) - 1) + 1);
	}
	printf("\nОбщее время выполнения: ");
	if (time1 < time2)
		printf("%i", time2);
	else printf("%i", time1);

}
void main()
{
	setlocale(LC_ALL, "Russian");
	FILE* fov;
	int kolvo_Details;
	int** time;

	if ((fov = fopen("List.txt", "r")) == NULL)
	{
		printf("Файла нет");
		exit(1);
	}
	fscanf_s(fov, "%i", &kolvo_Details);
	time = (int**)malloc(kolvo_Details * sizeof(int*));
	for (int index = 0; index < kolvo_Details; index++)
	{
		time[index] = (int*)malloc(2 * sizeof(int));
		fscanf_s(fov, "%i", &*(*(time + index)));
		fscanf_s(fov, "%i", &*(*(time + index) + 1));
		*(*(time + index) + 2) = 1;
	}
	fclose(fov);
	printf("%i\n", kolvo_Details);
	for (int index = 0; index < kolvo_Details; index++)
	{
		printf("%i деталь: %i  ", index + 1, *(*(time + index)));
		printf("%i\n", *(*(time + index) + 1));
	}
	int* Posledovatelnost = (int*)malloc(kolvo_Details * sizeof(int));
	Order(Posledovatelnost, kolvo_Details, time);
	printf("Преобразованная последовательность: ");
	for (int i = 0; i < kolvo_Details; i++) { printf("%i,", *(Posledovatelnost + i)); };
	GanttChart(Posledovatelnost, time, kolvo_Details);
	free(time);
	free(Posledovatelnost);
	_getch();
}