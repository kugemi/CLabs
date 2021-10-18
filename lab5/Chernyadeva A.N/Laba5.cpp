#include <stdio.h>
#include <conio.h>
#include <locale.h>
#define lineBreak printf("\n")


//он не считает последнее слово!
// 
// энтер и ctrl + z, после текста обязательно сделать пробел.
int main() {
	unsigned nSymbol;                      // Кол-во символов
	unsigned nSentences;                   // Кол-во предложений
	unsigned nWordsinText;                 // Количество слов во всём тексте
	unsigned nWordsinSent;                 // Количество слов в одном предложении
	char cChar;                            // Считываемая буква
	char flag = 1;                         // Флаг на выход из числа
	int i, j;                              // Счётчики
	int WordBarGraph[100] = { 0 };         // Массив для хранения кол-ва символов в словах
	int SentencesBarGraph[100] = { 0 };    // Массив для храниения количества слов в предложениях.
	int FullCell;                          // Считает кол-во непустых ячеек в массиве SentencesBarGraph
	int maxCBG;                            // Принимает максимальное из значений массива 


	// Инициализация переменных
	nSymbol = nSentences = nWordsinText = nWordsinSent = FullCell = maxCBG = 0;

	// Подключение русского языка
	setlocale(LC_ALL, "Rus");


	// Приветственный текст
	for (i = 0; i < 12; i++) printf(" ");
	printf("Данная программа вычисляет количество слов и предложений\n");
	for (i = 0; i < 12; i++) printf(" ");
	printf("в введённом Вами тексте, а также показывает гистограммы\n");
	for (i = 0; i < 33; i++) printf(" ");
	printf("Вашего текста.\n");
	for (i = 0; i < 5; i++) printf(" ");
	printf("=====================================================================\n");
	for (i = 0; i < 5; i++) printf(" ");
	printf("Обязательно прочтите это перед тем, как начать работать с программой!\n");
	printf("     Когда Вы закончите вводить текст, и Ваше\n");
	printf("     последнее слово написано латинскими буквами,\n");
	printf("     поставьте пробел и любой символ. Не волнуйтесь, он не считается.\n");
	printf("     Если же последнее слово написано на кириллице, то всё хорошо :)\n");
	for (i = 0; i < 5; i++) printf(" ");
	printf("=====================================================================\n\n");
	for (i = 0; i < 3; i++) printf(" ");
	printf("Когда закончите вводить, нажмите клавишу Enter, затем Ctrl+Z и снова Enter\n\n");
	
	printf("Начинайте вводить текст.\n\n <<|");




	// Считывание символов.
	while ((cChar = getchar()) != EOF)
	{
		// Проверка на конец слова. Если конец, счётчик слов уеличивается, в массив запоминается кол-во символов в слове.
		if (cChar == ' ' || cChar == '\n' || cChar == '\t')
		{
			flag = -1;
		}
		else if (flag == -1)
		{
			flag = 1;
			WordBarGraph[++nWordsinText] = nSymbol-1;
			nWordsinSent++;
			nSymbol = 0;
		}

		// Проверка на конец предложения. Если конец, счётчик предложений увеличивается, в массив запоминается кол-во слов.
		if (cChar == '.' || cChar == '!' || cChar == '?')
		{
			nSentences++;
			SentencesBarGraph[nSentences] = nWordsinSent;
			nWordsinSent = 0;
			
		}
		nSymbol++;
	}
	printf("|>>\n\n\n");

	for (i = 0; i < 16; i++) printf(" ");
	printf("= = = = =   Результат работы программы:   = = = = =\n\n");


	// Первое слово программа не считывает, поэтому для верности добавляется 1.
	SentencesBarGraph[1]++;

	// Счёт непустых ячеек в массиве для того, чтобы потом построить вертикальную гистограмму.
	for (i = 0; i < 30; i++) if (SentencesBarGraph[i] != 0) FullCell++;

	//
	//////////////////////Вывод ответов и гистограмм
	//

	// Вывод количества слов в тексте + склонение по кол-ву.

	printf("   Количество слов во всём тексте: %u ", nWordsinText);
	if (nWordsinText%10 == 1) printf("слово\n");
	else if (nWordsinText%10 > 1 && nWordsinText%10 < 5) printf("слова\n");
	else printf("слов\n");

	printf("\n\n--------------   График слов и букв в словах.   --------------\n");
	printf(" \\ --> Кол - во символов\n");
	printf("|\n");
	printf("V\n");
	printf("Кол-во слов\n\n");
	// Вывод кол-ва символов по словами в виде горизонтальной гистограммы.

	//printf("|   ");
	for (i = 1; i < 100; i++)
	{
		printf("|   ");
		if (WordBarGraph[i] == 0) break;
		for (j = 0; j < WordBarGraph[i]; j++) printf("+");
		if (j == WordBarGraph[i])
		{
			lineBreak;
		}
	}
	// Вычисление максимального значения в массиве SentencesBarGraph
	for (i = 0; i < 100; i++) if (SentencesBarGraph[i] > maxCBG) maxCBG = SentencesBarGraph[i];

	printf("\n\n-------   График предложений и слов в предложениях.   -------\n\n");
	
	// Вывод кол-ва слов по предложениям в виде вертикальной гистограммы.
	for (j = maxCBG; j > 0; j--)
	{
		printf("|   ");
		for (i = 1; i <= FullCell; i++)
		{
			if (SentencesBarGraph[i] == j)
			{
				printf(" *");
				SentencesBarGraph[i]--;
			}
			else printf("  ");
		}
		lineBreak;
	}
	printf("\nКол-во слов\n");
	printf("^\n");
	printf("|\n");
	printf("/--> Кол - во предложений\n");
	printf("=====================================================================\n");
	for (i = 0; i < 30; i++) printf(" ");
	printf("Программа завершена!\n\n\n\n");}