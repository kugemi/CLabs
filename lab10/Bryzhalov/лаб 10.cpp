#include<stdio.h>
#include<conio.h>
#include<locale.h>
#include<stdlib.h>
#include<time.h>

void fusionSort(int* arr, int left, int right){
	if (left == right) return; 
	int middle = (left + right) / 2; 
	fusionSort(arr, left, middle);
	fusionSort(arr, middle + 1, right);
	int start1 = left;  
	int start2 = middle + 1; 
	int* dop = (int*)malloc(right * sizeof(int)); 
	for (int step = 0; step <= right - left; step++) {
		if ((start2 > right) || ((start1 <= middle) && (arr[start1] < arr[start2])))
		{
			dop[step] = arr[start1];
			start1++;
		}
		else
		{
			dop[step] = arr[start2];
			start2++;
		}
	}
	for (int step = 0; step <= right - left; step++)
		arr[left + step] = dop[step];
}

void insertSort(int* arr, int elements) {
	for (int i = 1; i < elements; i++) {
		int last = arr[i];
		int n = i - 1;
		while (n >= 0 && arr[n] > last) {
			arr[n + 1] = arr[n];
			n--;
		}
		arr[n + 1] = last;
	}
}

int main(void) {
	setlocale(LC_ALL, "");

	int* array = NULL;
	int quantNumbers = 0;
	int num = 0;
	int flag = 0;

	do {
		flag = 1;
		printf_s("Введите количество элементов массива: ");
		if (!scanf_s("%d", &quantNumbers)) {
			flag = 0;
			printf_s("Вы ввели не число!");
			while ((getchar()) != '\n');
		}
	} while ((quantNumbers < 1) || (flag == 0));

	array = (int*)malloc(quantNumbers * sizeof(int));
	srand(time(0));
	for (num = 0; num < quantNumbers; num++) {
		array[num] = rand() % 1001;
	}
	printf_s("\n_______________________\nНачальный массив: \n");
	for (num = 0; num < quantNumbers; num++) printf_s("%-5d",array[num]);

	if (quantNumbers < 5) insertSort(array, quantNumbers-1);
	else fusionSort(array,0,quantNumbers-1);

	printf_s("\n_______________________\nОтсоритированный массив:\n");
	for (num = 0; num < quantNumbers; num++) printf_s("%-5d", array[num]);
	printf_s("\n_______________________");
	free(array);
}