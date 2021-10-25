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
    int numberOfWord[100];
    int numberOfSymbol[100];
    int proposal = 0;
    int max = 0;
    int checkMax = 0;
    char text = 0;
    int check = OUT;
    for (int null = 0; null < 100; null++) {
        numberOfSymbol[null] = 0;
        numberOfWord[null] = 0;
    }
    while ((text = getchar()) != EOF) {
        if (text == ' ' || text == '\n' || text == ',' || text == '-' || text == ':' || text == ';')
            check = OUT;
        else if (text == '.' || text == '?' || text == '!') {
            check = OUT;
            proposal++;
        }
        else if (check == OUT) {
            check = IN;
            numberOfWord[proposal]++;
            counterWord++;
        }
        if(check==IN)
        numberOfSymbol[counterWord]++;
    }
    printf("\n");
    printf("Количество слов: %d\n", counterWord);
    for (int cycleNumberOfWord = 1; cycleNumberOfWord <= counterWord; cycleNumberOfWord++) {
        for (int symbol = 1; symbol <= numberOfSymbol[cycleNumberOfWord]; symbol++) {
            printf("*");
        }
        printf("\n");
    }
    printf("Количество предложений: %d\n", proposal);
    for (int numberOfProposal = 0; numberOfProposal < proposal; numberOfProposal++) {
        printf("В %d предложении: %d слов\n",numberOfProposal+1,numberOfWord[numberOfProposal]);
    }
    for (int maximumCycle = 0; maximumCycle < proposal; maximumCycle++) {
                if (numberOfWord[maximumCycle] > max) max = numberOfWord[maximumCycle];
            }
           printf("Максимум равен: %d\n", max);
           checkMax = max;
           for (int cycleCheckMax = 0; cycleCheckMax < checkMax; cycleCheckMax++) {
               for (int cycleOfProposal = 0; cycleOfProposal < proposal; cycleOfProposal++) {
                   if (numberOfWord[cycleOfProposal] >= max) printf("*");
                   else printf(" ");
               }
               printf("\n");
               max--;
           }
}



