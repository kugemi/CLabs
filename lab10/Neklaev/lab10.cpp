#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <locale.h>




void Insertionsort0(int w[], int len) { 
    for (int i = 0; i < len; i++) {
        int k = i;
        while (k > 0 && w[k - 1] > w[k]) {
            int tmp = w[k - 1];
            w[k - 1] = w[k];
            w[k] = tmp;
            k--;
        }
    }
}

void merge(int* w, int first, int last) { 
    int middle = (first + last) / 2;
    int left = first;
    int right = middle + 1;
    int* temp = (int*)malloc(last * sizeof(int));
    for (int i = 0; i < last - first; i++) {
        if (((left <= middle) && (w[left] < w[right])) || (right > last)) {
            temp[i] = w[left]; left++;
        }
        else {
            temp[i] = w[right]; right++;
        }
    }
    for (int j = 0; j < last - first; j++) {
        w[first + j] = temp[j];
    }
}



void merge_sort(int* A, int first, int last) {
    if (last - first <= 5) {
        Insertionsort0(A, last);
    }
    else {
        merge_sort(A, first, (first + last) / 2);
        merge_sort(A, (first + last) / 2 + 1, last);
        merge(A, first, last);
    }
}



int main() 
{
    setlocale(LC_ALL, "Russian");
    int* a; 
    int i, Size;
    int len;
    printf("Введите размер массива: ");
    scanf_s("%d", &Size);
    a = (int*)malloc(Size * sizeof(int));
    for (i = 0; i < Size; i++) {
        a[i] = (rand() % 100);
    }
    printf("\n");
    printf("Начальный массив: ");
    for (i = 0; i < Size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    if (Size <= 5) {
        Insertionsort0(a, Size);
    }
    else {
        merge_sort(a, 1, Size);
    }
    printf("\n");
    printf("Конечный массив: ");
    for (i = 0; i < Size; i++) {
        printf("%d ", a[i]);
    }
}

