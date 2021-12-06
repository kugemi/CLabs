#include<locale.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

#define _CRT_SECURE_NO_WARNINGS

int** sortmin(int** arr, int m, int n) {
    int index1=0, index2=0;
    int min = 0;
    int** addArr = NULL;
    addArr = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++)addArr[i] = (int*)malloc((n) * sizeof(int));
    addArr[2] = new int[n];
    int j = 0;
    int i = 0;
    int a = 0, b = n;
    while (a < b) {
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                if ((((i == 0) & (j == 0)) || (arr[i][j] < min)) & (arr[i][j] != NULL)) {
                    min = arr[i][j];
                    index1 = i;
                    index2 = j;

                }
            }
        }
        if (index1 == 1) {
            addArr[0][b - 1] = arr[index1 - 1][index2];
            addArr[1][b - 1] = arr[index1][index2];
            addArr[2][b - 1] = arr[index1 + 1][index2];
            b--;
            arr[index1][index2] = 3000000;
            arr[index1 - 1][index2] = 3000000;
        }
        else {
            addArr[0][a] = arr[index1][index2];
            addArr[1][a] = arr[index1 + 1][index2];
            addArr[2][a] = arr[index1 + 2][index2];
            a++;
            arr[index1][index2] = 30000000;
            arr[index1 + 1][index2] = 30000000;
        }
    }
    return addArr;
} 


int main()
{
    setlocale(LC_ALL, "");

    int sum = 0, sum2 = 0, sum3 = 0;
    int** matrix = NULL;
    int details = 0;;
    int i, j = 0;
    int mach = 0;
    int num = 0, num2 = 0;
    int k=0;
    int P[200] = { 0 };
    int P2[200] = { 0 };
    FILE* f;

    printf_s("Введите кол-во деталей: ");
    scanf_s("%d", &details);
    f = fopen("text.txt", "r");
    fscanf_s(f, "%d", &mach);
    matrix = (int**)malloc(mach * sizeof(int*));
    for (i = 0; i < mach; i++)matrix[i] = (int*)malloc(details * sizeof(int));
    i = 0;
    j = 0;
    fscanf_s(f, "%d", &matrix[i][j]);
    fscanf_s(f, "%d", &matrix[i + 1][j]);
    while (!feof(f)) {
        j++;
        if (j >= details) break;
        fscanf_s(f, "%d", &matrix[i][j]);
        fscanf_s(f, "%d", &matrix[i + 1][j]);
    }
    fclose(f);

    matrix[2] = new int[details];
    for (j = 0; j < details; j++) {
        matrix[2][j] = j + 1;

    }
    printf_s("\n___________________________\nИнформация о времени обработки деталей:\n");
    printf_s("Детали:    ");
    for (i = 0; i < details; i++) {
        printf_s("%-4d", matrix[2][i]);
    }
    printf_s("\nСтанок №1: ");
    for (i = 0; i < details; i++) {
        printf_s("%-4d", matrix[0][i]);
    }
    printf_s("\nСтанок №2: ");
    for (i = 0; i < details; i++) {
        printf_s("%-4d", matrix[1][i]);
    }
    printf_s("\n___________________________\n");
    matrix = sortmin(matrix, mach, details);
    printf_s("Выгодный порядок обработки: ");
    for (i = 0; i < details; i++) {
        printf_s("%-4d", matrix[2][i]);
    }
    printf_s("\n___________________________\n");
    printf_s("График ганта: ");
    printf_s("\nСтанок №1: ");
    for (j = 0; j < details; j++) {
        for (i = 0;i < matrix[0][j]; i++) {
            P[sum] = matrix[2][j];
            printf_s("%d",P[sum]);
            sum ++;
        }
    }
    num = sum;
    printf_s("\nСтанок №2: ");
    sum = 0;
    for (j = 0; j < details; j++) {
        for (k = 0; k < matrix[1][j]; k++) {
            P2[sum2] = matrix[2][j];
            sum2 += 1;
        }
    }
    num2 = sum2;
    sum2 = 0;
    while ((sum < num) || sum2 < num2) {
        if (P[sum] == P2[sum2]) {
            printf_s(" ");
            sum++;
        }
        else {
            printf("%d", P2[sum2]);
            sum++;
            sum2++;
        }
        sum3 += 1;
    }
    printf_s("\nВремя обработки: %d", sum3);
}