#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>

int stcmp_my(char* arrayReceiver, char* arraySource);
char* strcpy_my(char* theFirstString, char* theSecondString);
char** sort(char** userArray, int numberOfElements);

int main()
{
	setlocale(LC_ALL, "Rus");

	char** arrayOfStrings = NULL;
	char* roughСopy = NULL;
	char auxiliaryString = NULL;
	char* theFirstAssistant = NULL;//для нормальной работы realloc
	char** theSecondAssistant = NULL;//для нормальной работы realloc
	int numberOfRows = 0;
	int stringLength = 0;
	int memoryString = 0;
	int memoryArray = 2;

	arrayOfStrings = (char**)malloc(2 * sizeof(char*));
	printf("Введите строки:\n");

	for (int index = 0;; index++)
	{
		printf("%d)", index + 1);
		stringLength = 0;
		memoryString = 2;
		roughСopy = (char*)malloc(2 * sizeof(char));
		theFirstAssistant = (char*)malloc(2 * sizeof(char));
		while ((auxiliaryString = getchar()) != '\n')
		{
			if (stringLength == memoryString)
			{
				memoryString = memoryString * 2;
				theFirstAssistant = (char*)realloc(roughСopy, (memoryString + 2) * sizeof(char));
				roughСopy = theFirstAssistant;
			}
			if (roughСopy != NULL)
			{
				roughСopy[stringLength] = auxiliaryString;
				stringLength++;
			}
		}
		roughСopy = (char*)realloc(roughСopy, (stringLength + 1) * sizeof(char));
		roughСopy[stringLength] = '\0';
		if (!*roughСopy)
		{
			free(roughСopy);
			break;
		}
		else
		{
			if (numberOfRows >= memoryArray) {
				memoryArray = memoryArray * 3;
				theSecondAssistant = (char**)realloc(arrayOfStrings, memoryArray * sizeof(char*));
				arrayOfStrings = theSecondAssistant;
			}
			arrayOfStrings[index] = (char*)malloc((strlen(roughСopy) + 1) * sizeof(char));
			strcpy_my(arrayOfStrings[index], roughСopy);
			numberOfRows++;
		}
		free(roughСopy);
	}
	arrayOfStrings = (char**)realloc(arrayOfStrings, numberOfRows * sizeof(char*));
	printf("-----------------------");
	printf("\nОтсортированные строки:\n");
	printf("-----------------------\n");
	arrayOfStrings = sort(arrayOfStrings, numberOfRows);

	for (int index = 0; index < numberOfRows; index++)
		printf("%d)%s\n", index + 1, arrayOfStrings[index]);
	_getch();
	free(arrayOfStrings);
}
char* strcpy_my(char* arrayReceiver, char* arraySource)
{
	char* ptrs1 = arrayReceiver;

	while ((*arrayReceiver++ = *arraySource++) != 0);
	return ptrs1;
}
int stcmp_my(char* theFirstString, char* theSecondString)
{
	int maximumLength = 0;
	char* theFirstPointer, * theSecondPointer;
	theFirstPointer = theFirstString;
	theSecondPointer = theSecondString;

	if (strlen(theFirstPointer) >= strlen(theSecondPointer))
		maximumLength = strlen(theFirstPointer);
	else
		maximumLength = strlen(theSecondPointer);

	for (int index = 0; index <= maximumLength; index++)
	{
		if ((*theFirstPointer - *theSecondPointer) < 0)
			return 0;
		else if ((*theFirstPointer - *theSecondPointer) > 0)
			return 1;
		theFirstPointer++;
		theSecondPointer++;
	}
	return 0;
}
char** sort(char** userArray, int numberOfElements)
{
	int isFlag = 1;
	char* roughСopy = NULL;

	for (int index = 0; index < numberOfElements; index++)
	{
		isFlag = 1;
		for (int jndex = 0; jndex < numberOfElements - (index + 1); jndex++)
		{
			if (stcmp_my(userArray[jndex], userArray[jndex + 1]))
			{
				isFlag = 0;
				roughСopy = userArray[jndex];
				userArray[jndex] = userArray[jndex + 1];
				userArray[jndex + 1] = roughСopy;
			}
		}
		if (isFlag)
			break;
	}
	return userArray;
}