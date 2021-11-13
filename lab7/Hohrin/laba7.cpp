#include <conio.h>
#include <stdio.h>
#include <locale.h>
#include <iostream>

int main()
{
    setlocale(LC_ALL, "russian");
    int maxWeight, max, amount, sum, input, weight = 0;
    int counter = 1;
    sum = 0;
    max = 0;
    int arrayWeight[100], arrayPrice[100], binaryReverse[1000], binaryArray[1000] = { 0 };
    printf("Введите вместимость ранца:");
    scanf_s("%d", &maxWeight);
    printf("Введите количество вещей:");
    scanf_s("%d", &amount);
    for (int i = 0; i < amount; i++)
    {
        printf("Введите вес и стоимость предмета:");
        scanf_s("%d %d", &arrayWeight[i], &arrayPrice[i]);
    }
    input = pow(2, amount) - 1;
    for (int a = 0; a < pow(2, amount + 1); a++)
    {
        sum = 0;
        weight = 0;
        counter = 1;
        while (input > 0)
        {
            binaryReverse[counter] = input % 2;
            input = input / 2;
            counter++;
        }
        counter--;
        for (int b = 0; b < counter; b++)
        {
            binaryArray[b] = binaryReverse[counter - b];
        }
        if (input == 0)
        {
            for (int c = 0; c < 50; c++)
            {
                if (binaryArray[c] == 1)
                {
                    sum += arrayPrice[c];
                    weight += arrayWeight[c];
                }
                if (weight <= maxWeight)
                {
                    if (sum > max)
                    {
                        max = sum;
                    }
                }
            }
        }
    }
    printf("максимальная ценность:%d", max);
}
