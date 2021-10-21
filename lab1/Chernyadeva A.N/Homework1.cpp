#include <stdio.h>
#include <conio.h>
#include <locale.h>


void main(void)
{   
   setlocale(LC_ALL, "Rus");

    int i, n;
    float a[20], sum;

    printf("Введите кол-во чисел n ");
    scanf_s("%d", &n);
    printf("Введите %d вещественных чисел по одному в строку\n", n);
    for (sum = 0, i = 0; i < n; i++)
    {
        printf("a[%d] = ", i + 1);
        scanf_s("%f", &a[i]);
        sum += a[i];
    }

    for (i = 0; i < n; i++)
    {

        if (i == 10) printf("%3d:[%12.2f]", i + 1, a[i]);
        else printf("%4d:[%12.2f]", i + 1, a[i]);
        if ((i + 1) % 4 == 0)
        {
            printf("\n");
        }
    }
    printf ("\n");
    printf("  Сумма всех чисел");
    printf("\n");
    for (i = 0; i < n; i++) 
        printf("%12.2f\n", a[i]);
    printf("------------------\n%12.2f", sum);

}



void Natur(void)
{
   setlocale(LC_ALL, "Rus");

    int i, s, n, a[20];
    printf("Введите количество чисел:  ");
    scanf_s("%d", &n);
    printf("Введите числа, по одному в строке\n");
    for (s = 0, i = 0; i < n; i++)
    {
        printf("a[%d] =  ", i + 1);
        scanf_s("%d", &a[i]);
        s += a[i];
    }
    for (i = 0; i < n; i++)
        printf("%2d:%5d ", i + 1, a[i]);
    printf("\n");
    for (i = 0; i < n; i++)
        printf("[%6d]\n", a[i]);
    printf("------\n%6d", s);

}