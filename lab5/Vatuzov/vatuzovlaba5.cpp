#include<conio.h>
#include<locale.h>
#include <iostream>
#include<stdio.h>
#define OUT 0
#define IN 1
int main()
{
    setlocale(LC_ALL, "Russian");
    int counterWord = 0;
    int numberWord = 0;
    int max = 0;
    int check = 0;
    char text=0;
    int checkSymbol = 1;
    int numberOfSymbol = 0;
    int checkWord = 0;
    char arrayText[1000];
    while ((text = getchar()) != EOF) {
        if (text == ' ' || text == '\n')
            checkWord = OUT;
        else if (checkWord == OUT) {
            checkWord = IN;
            counterWord++;
        }
        arrayText[numberOfSymbol] = text;
        numberOfSymbol++;
    }
    printf("\nКоличество слов: %d\n",counterWord);
    int* arrayWords = new int[counterWord];
    for (int c = 0; c < counterWord; c++) {
        arrayWords[c] = 0;
    }
    numberOfSymbol--;
        for (int symbol = 0; symbol < numberOfSymbol; symbol++) {
            if (arrayText[symbol] != ' ' && arrayText[symbol] != '\n') {
                if (checkSymbol == 0 ) numberWord++;
                check = 0;
                printf("*");
                checkSymbol++;
                arrayWords[numberWord]++;
            }
            else {
                if (check == 0) {
                    printf("\n");
                check = 1;
                checkSymbol = 0;
            }
            }
        }
    printf("\n");
    for (int maximumCycle = 0; maximumCycle < counterWord; maximumCycle++) {
        if (arrayWords[maximumCycle] > max) max = arrayWords[maximumCycle];
    }
    printf("Максимум равен: %d\n", max);
    int checkMax = max;
    for (int CycleCheckMax = 0; CycleCheckMax < checkMax; CycleCheckMax++) {
        for (int theCycleOfWords = 0; theCycleOfWords < counterWord; theCycleOfWords++ ) {
            if (arrayWords[theCycleOfWords] >= max) printf("*");
            else printf(" ");
        }
        printf("\n");
        max--;
    }
}


