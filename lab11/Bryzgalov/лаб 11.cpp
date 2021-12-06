#include<locale.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

#define _CRT_SECURE_NO_WARNINGS

int** sortmin(int** arr, int machines, int details) {
    int indexMin1=0, indexMin2=0;
    int min = 0;
    int** addArr = NULL;
    addArr = (int**)malloc(machines * sizeof(int*));
    for (int i = 0; i < machines; i++)addArr[i] = (int*)malloc((details) * sizeof(int));
    addArr[2] = new int[details];
    int countDetails = 0;
    int countMachines = 0;
    int begin = 0, end = details;
    while (begin < end) {
        for (countMachines = 0; countMachines < machines; countMachines++) {
            for (countDetails = 0; countDetails < details; countDetails++) {
                if ((((countMachines == 0) & (countDetails == 0)) || (arr[countMachines][countDetails] < min)) & (arr[countMachines][countDetails] != NULL)) {
                    min = arr[countMachines][countDetails];
                    indexMin1 = countMachines;
                    indexMin2 = countDetails;

                }
            }
        }
        if (indexMin1 == 1) {
            addArr[0][end - 1] = arr[indexMin1 - 1][indexMin2];
            addArr[1][end - 1] = arr[indexMin1][indexMin2];
            addArr[2][end - 1] = arr[indexMin1 + 1][indexMin2];
            end--;
            arr[indexMin1][indexMin2] = 3000000;
            arr[indexMin1 - 1][indexMin2] = 3000000;
        }
        else {
            addArr[0][begin] = arr[indexMin1][indexMin2];
            addArr[1][begin] = arr[indexMin1 + 1][indexMin2];
            addArr[2][begin] = arr[indexMin1 + 2][indexMin2];
            begin++;
            arr[indexMin1][indexMin2] = 30000000;
            arr[indexMin1 + 1][indexMin2] = 30000000;
        }
    }
    return addArr;
} 


int main()
{
    setlocale(LC_ALL, "");

    int countTimeMach1 = 0, countTimeMach2 = 0, totalTime = 0;
    int** matrix = NULL;
    int details = 0;;
    int strings, columns = 0;
    int mach = 0;
    int timeMach1 = 0, timeMach2 = 0;
    int gant1[200] = { 0 };
    int gant2[200] = { 0 };
    FILE* f;

    printf_s("Введите кол-во деталей: ");
    scanf_s("%d", &details);
    f = fopen("text.txt", "r");
    fscanf_s(f, "%d", &mach);
    matrix = (int**)malloc(mach * sizeof(int*));
    for (strings = 0; strings < mach; strings++)matrix[strings] = (int*)malloc(details * sizeof(int));
    strings = 0;
    columns = 0;
    fscanf_s(f, "%d", &matrix[strings][columns]);
    fscanf_s(f, "%d", &matrix[strings + 1][columns]);
    while (!feof(f)) {
        columns++;
        if (columns >= details) break;
        fscanf_s(f, "%d", &matrix[strings][columns]);
        fscanf_s(f, "%d", &matrix[strings + 1][columns]);
    }
    fclose(f);


    matrix[2] = new int[details];
    for (columns = 0; columns < details; columns++) {
        matrix[2][columns] = columns + 1;

    }


    printf_s("\n___________________________\nИнформация о времени обработки деталей:\n");
    printf_s("Детали:    ");
    for (strings = 0; strings < details; strings++) {
        printf_s("%-4d", matrix[2][strings]);
    }
    printf_s("\nСтанок №1: ");
    for (strings = 0; strings < details; strings++) {
        printf_s("%-4d", matrix[0][strings]);
    }
    printf_s("\nСтанок №2: ");
    for (strings = 0; strings < details; strings++) {
        printf_s("%-4d", matrix[1][strings]);
    }
    printf_s("\n___________________________\n");


    matrix = sortmin(matrix, mach, details);


    printf_s("Выгодный порядок обработки: ");
    for (strings = 0; strings < details; strings++) {
        printf_s("%-4d", matrix[2][strings]);
    }


    printf_s("\n___________________________\n");
    printf_s("График ганта: ");
    printf_s("\nСтанок №1: ");
    for (columns = 0; columns < details; columns++) {
        for (strings = 0;strings < matrix[0][columns]; strings++) {
            gant1[countTimeMach1] = matrix[2][columns];
            printf_s("%d",gant1[countTimeMach1]);
            countTimeMach1 ++;
        }
    }

    timeMach1 = countTimeMach1;
    printf_s("\nСтанок №2: ");
    countTimeMach1 = 0;
    for (columns = 0; columns < details; columns++) {
        for (strings = 0; strings < matrix[1][columns]; strings++) {
            gant2[countTimeMach2] = matrix[2][columns];
            countTimeMach2 += 1;
        }
    }
    timeMach2 = countTimeMach2;
    countTimeMach2 = 0;

    while ((countTimeMach1 < timeMach1) || countTimeMach2 < timeMach2) {
        if (gant1[countTimeMach1] == gant2[countTimeMach2]) {
            printf_s(" ");
            countTimeMach1++;
        }
        else {
            printf("%d", gant2[countTimeMach2]);
            countTimeMach1++;
            countTimeMach2++;
        }
        totalTime += 1;
    }
    printf_s("\nВремя обработки: %d", totalTime);
    printf_s("\n___________________________\n");
}