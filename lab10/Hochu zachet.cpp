#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<locale.h>
#include <time.h>
#include <string.h>
void insert(int* arr, int number);
void MergeSort(int* arr, int first, int last, int number);
void main()
{
	setlocale(LC_ALL, "RUSSIAN");
	int number;
	printf("Введи количество чисел ");
	scanf_s("%i", &number);
	int* mass = (int*)malloc(number * sizeof(int));
	srand(time(0));
	for (int index = 0; index < number; index++)
	{
		*(mass + index) = rand() % 1000;
	}
	printf("Рандомная последовательность: \n");
	printf("%i", *mass);
	for (int index = 1; index < number; index++)
	{
		printf(",%i", *(mass + index));
	}
	if (number <= 5)
	{
		insert(mass, number);
	}
	else MergeSort(mass, 0, number - 1, number);
	printf("\nОтсортированная последовательность:\n");
	printf("%i", *mass);
	for (int index = 1; index < number; index++)
	{
		printf(",%i", *(mass + index));
	}
}

void insert(int* arr, int number)
{
	for (int index = 1; index < number; index++)
	{
		int kindex = index;
		{
			while (*(arr + kindex - 1) > *(arr + kindex))
			{
				int check = *(arr + kindex - 1);
				*(arr + kindex - 1) = *(arr + kindex);
				*(arr + kindex) = check;
				kindex--;
			}
		}
	}
}
void MergeSort(int* arr, int first, int last, int number)
{
	if (first < last)
	{
		MergeSort(arr, first, (first + last) / 2, number);
		MergeSort(arr, ((first + last) / 2) + 1, last, number);
		int f = first;
		int* sort = (int*)calloc((last - first + 1), sizeof(int));
		int left = (first + last) / 2 + 1;
		int l = left;
		int n = 0;
		while ((left <= last) || (first < l))
		{
			if ((arr[first] < arr[left] && first < l) || (left > last)) { sort[n] = arr[first]; first++; }
			else { sort[n] = arr[left]; left++; }
			n++;
		}
		int check = 0;
		for (; f <= last; f++)
		{
			*(arr + f) = *(sort + check);
			check++;
		}
	}
}