#include<stdio.h>
#include<conio.h>
#include<locale.h>
#include<stdlib.h>
#include <string.h>
#include<iostream>
void insert(int* arr, int fuck);
void Merge(int* arr, int first, int last, int num);
void MergeSort(int* arr, int first, int last, int num);
void main()
{
	int num;
	printf("Enter the number of numbers ");// Введите киличесво чисел, мне  так переводчик перевол
	scanf_s("%i", &num);
	int* mass = (int*)malloc(num* sizeof(int));
	srand(time(0));
	for (int i = 0; i < num ; i++)
	{ 
		*(mass + i) = rand() % 1000;
	}
	printf("Random sequence: \n");
	printf("%i", *mass);
	for (int i = 1; i < num ; i++)
	{
		printf(",%i", *(mass + i));
	}
	if (num <= 5)
	{
		insert(mass, num);
	}
	else MergeSort(mass, 0, num - 1,num);
	printf("\nSorted sequence:\n");
	printf("%i", *mass);
	for (int i = 1; i < num; i++)
	{
		printf(",%i", *(mass + i));
	}
}
void Merge(int* arr, int first, int last, int num)
{
	int f = first;
	int* sort = (int*)calloc((last - first + 1), sizeof(int));
	int left = (first + last) / 2 + 1;
	int l = left;
	int n = 0;
	while ((left <= last) || (first < l))
	{
		if ((arr[first] < arr[left] && first<l) ||  (left>last)) { sort[n] = arr[first];first++; }
		else { sort[n] = arr[left]; left++; }
		n++;
	}
	int g = 0;
	for (; f <= last; f++)
	{
		*(arr + f) = *(sort + g);
		g++;
	}
}
void insert(int* arr, int num)
{
	for (int i = 1; i < num; i++)
	{ 
		int a = i;
		{	
			while (*(arr + a - 1) > *(arr + a))
			{
				int popa = *(arr + a-1);
				*(arr + a - 1) = *(arr + a);
				*(arr + a) = popa;
				a--;
			}
		}
	}
}
void MergeSort(int* arr, int first, int last, int num)
{
	if (first < last)
	{
		MergeSort(arr, first, (first + last) / 2,num);
		MergeSort(arr, ((first + last) / 2) + 1,last, num );
		Merge(arr, first, last, num);
	}
}