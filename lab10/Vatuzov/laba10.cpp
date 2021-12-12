#include <locale.h>
#include <conio.h>
#include <stdio.h>
#include <time.h>
#include <iostream>
void insertSort(int* sortingArray, int quantity) {
	int position = 0;
	int elementOfQuantity = 0;
	for (int indexIS = 1; indexIS < quantity; indexIS++) {
		elementOfQuantity = sortingArray[indexIS];
		position=indexIS-1;
		while (position >= 0 && sortingArray[position] > elementOfQuantity) {
			sortingArray[position + 1] = sortingArray[position];
			position--;
		}
		sortingArray[position+1] = elementOfQuantity;
	}
}
void mergeSort(int* sortingArray, int left, int right) {
	if (left == right) return;
	int middle = (left + right) / 2;
	mergeSort(sortingArray, left, middle);
	mergeSort(sortingArray, middle + 1, right);
	int indicatorLeft = left;
	int indicatorMiddle = middle + 1;
	int* mergeSortArray = (int*)malloc(right * sizeof(int));
	for (int indexMergeSort = 0; indexMergeSort <= right - left; indexMergeSort++) {
		if ((indicatorMiddle > right) || ((indicatorLeft <= middle) && (sortingArray[indicatorLeft] < sortingArray[indicatorMiddle])))
		{
			mergeSortArray[indexMergeSort] = sortingArray[indicatorLeft];
			indicatorLeft++;
		}
		else
		{
			mergeSortArray[indexMergeSort] = sortingArray[indicatorMiddle];
			indicatorMiddle++;
		}
	}
	for (int step = 0; step <= right - left; step++)
		sortingArray[left + step] = mergeSortArray[step];
}
int main()
{
	srand(time(0));
	setlocale(LC_ALL, "Russian");
	printf("Введите число элементов массива: ");
	int Number = 0;
	scanf_s("%d", &Number);
	int* array = (int*)malloc(Number * sizeof(int));
	printf("Первоначальный массив:\n");
	for (int index = 0; index < Number; index++) {
		array[index] = 0;
		array[index] = rand();
		printf("%5d ",array[index]);
		if ((index+1) % 13 == 0)printf("\n");
	}
	printf("\nОтсортированный массив:\n");
	if (Number <= 5) insertSort(array, Number);
	else mergeSort(array,0,Number-1);
	for (int sortingIndex = 0; sortingIndex < Number; sortingIndex++) {
		printf("%5d ", array[sortingIndex]);
		if ((sortingIndex + 1) % 13 == 0)printf("\n");
	}
}

