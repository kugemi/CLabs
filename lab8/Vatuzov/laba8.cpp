#include <iostream>
#include<conio.h>
#include<locale.h>
#include<stdio.h>
int main()
{
    int Number;
    int Line = 0;
    int Column = 0;
    int check = 1;
    setlocale(LC_ALL,"Russian");
    printf("Введите размер квадратного массива: ");
    scanf_s("%d",&Number);
    int** ArraySquare = (int**)malloc(sizeof(int*)*Number);
    for (int indexArray=0; indexArray < Number; indexArray++) {
        ArraySquare[indexArray] = (int*)malloc(sizeof(int) * Number);
    }
    printf("Заполните квадратный массив:\n");
    for (int null = 0; null < Number; null++) {
        for (int insidenull = 0; insidenull < Number; insidenull++) {
            ArraySquare[null][insidenull] = 0;
            printf(" [%d][%d] = ",null+1,insidenull+1);
            scanf_s("%d", & ArraySquare[null][insidenull]);
        }
        printf("\n");
    }
    for (Line = 0; Line < Number; Line++) {
        for (Column = 0; Column < Number / 2; Column++) {
            if (ArraySquare[Line][Column] != ArraySquare[Line][Number - Column - 1]) {
                printf("Отсутствует вертикальная симметрия\n");
                check = 0;
                break;
            }
        }
        if (check == 0) break;
    }
    if (check == 1) printf("Массив симметричен относительно вертикали\n");
    check = 1;
    for (Line = 0; Line < Number/2; Line++) {
        for (Column = 0; Column < Number; Column++) {
            if (ArraySquare[Line][Column] != ArraySquare[Number - Line - 1][Column]) {
                printf("Отсутствует горизонтальная симметрия\n");
                check = 0;
                break;
            }
        }
        if (check == 0) break;
    }
    if (check == 1) printf("Массив симметричен относительно горизонтали\n");
    check = 1;
    for (Line = 0; Line < Number / 2; Line++) {
        for (Column = 0; Column < Number /2; Column++) {
            if (ArraySquare[Line][Column] != ArraySquare[Number - Line - 1][Number - Column - 1]) {
                printf("Отсутствует центральная симметрия\n");
                check = 0;
                break;
            }
        }
        if (check == 0) break;
    }
    if (check == 1) printf("Массив симметричен относительно центра\n");
}
