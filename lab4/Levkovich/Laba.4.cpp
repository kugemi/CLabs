
#include <iostream>
#include <locale.h>
#include <conio.h>
#include<time.h>
#include <stdlib.h>

int main()
{
    setlocale(LC_ALL, "Russian");
    int number1;
    int number2;
    int minimum = 0;
    int attempts;
    char word ;
    printf("Начать игру Y/N?\n");
    do 
    {
        scanf_s(" %c", &word);
        if ((word != 'y') && (word != 'n'))
        {
            printf("Нужно написать Y или N. Вы написали что-то другое, я не понимаю.\n");
        }
        while (getchar() != '\n');
    } while ((word != 'y') && (word != 'n'));
    while (word == 'y') 
    {
        srand(time(0));
        number1 = minimum + rand() % 100 + 1;
        for (attempts = 1; attempts < 10; attempts++) {
            printf("Попытка номер %d:Введите номер:", attempts);
            scanf_s("%i", &number2);
            if (number1 > number2)
            {
                printf("Число больше\n");
            }
            if (number1 < number2)
            {
                printf("Число меньше\n");
            }
            if (number1 == number2)
            {
                printf("Поздравляю, вы угадали число %d\n", number1); 
                printf("Количество попыток %d\n", attempts);
                break;
            }
            if (number1 != number2 && attempts == 10)
            {
                printf("Вы использовали все попытки, загаданное число было: %d\n", number1);
            }
        }
        printf("Продолжить игру Y/N?");
        do {
            scanf_s(" %c", &word);
            if ((word != 'y') && (word != 'n'))
            {
                printf("Нужно написать Y или N. Вы написали что-то другое, я не понимаю.\n");
            }
            while (getchar() != '\n');
        } while ((word != 'y') && (word != 'n'));
    }
    _getch();
}

