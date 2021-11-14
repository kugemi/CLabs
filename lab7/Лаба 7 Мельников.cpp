#include<stdio.h>
#include<conio.h>
#include <iostream>
#include<locale.h>
#include <math.h>
int main()
{
	int numbOfItems = 0;
	int items[100][100] = { 0 };
	int weight[100] = { 0 };
	int mass = 0; // for arr
	int value[100] = { 0 };
	int val = 0; // for arr
	int maxValue = 0;
	int goodWeight = 0;
	int yourBackpack = 0;
	int needToTake = 0;
	printf("Enter the number of items\n");
	scanf_s("%d", &numbOfItems);
	printf("Enter enter their weight\n");
	for (int i = 0; i < numbOfItems; i++)
	{
		scanf_s("%d", &mass);
		weight[i] = mass;
	}
	printf("Enter enter their value\n");
	for (int i = 0; i < numbOfItems; i++)
	{
		scanf_s("%d", &val);
		value[i] = val;
	}
	printf("Capacity of your Gucci bag: \n");
	scanf_s("%d", &yourBackpack);
	val = 0; // prosto peremenie svoe otrabotali i ya reshil ispolzovat ih dalshe
	mass = 0;
	for (int i = 0; i < pow(2, numbOfItems); i++)
	{
		for (int j = 0; j < i; j++)
		{
			items[i][0] += 1;
			for (int k = 0; k < numbOfItems; k++)
			{
				if (items[i][k] == 2)
				{
					items[i][k] = 0;
					items[i][k + 1] += 1;
				}
			}
		}
	}
	for (int i = 0; i < pow(2, numbOfItems); i++)
	{
		for (int j = 0; j < numbOfItems; j++)
		{
			if (items[i][j] == 1)
			{
				mass += weight[j];
				val += value[j];
			}
		}
		if (val >= maxValue && mass <= yourBackpack)
		{
			maxValue = val;
			goodWeight = mass;
			needToTake = i;
			val = 0;
			mass = 0;
		}
		else
		{
			val = 0;
			mass = 0;
		}
	}
	printf("------------------------------------------\n");
	printf("Value: ");
	for (int l = 0; l < numbOfItems; l++)
	{
		printf("%4d", value[l]);
	}
	printf("\n");
	printf("Weight:");
	for (int l = 0; l < numbOfItems; l++)
	{
		printf("%4d", weight[l]);
	}
	printf("\n");
	printf("Capacity:%4d\n", yourBackpack);
	printf("Your need to take:\n");
	for (int b = 0; b < numbOfItems; b++)
	{
		printf("%d", items[needToTake][b]);
	}
	printf("\n");
	printf("Wight: %d", goodWeight);
	printf("\n");
	printf("Value: %d", maxValue);
}