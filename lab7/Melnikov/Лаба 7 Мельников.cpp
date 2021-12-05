#include<stdio.h>
#include<conio.h>
#include <iostream>
#include<locale.h>
#include <math.h>
int main()
{
	int numbOfItems = 0;
	int index = 0;
	int weight[100] = { 0 };
	int mass = 0; // for arr
	int value[100] = { 0 };
	int val = 0; // for arr
	int maxValue = 0;
	int goodWeight = 0;
	int yourBackpack = 0;
	int needToTake = 0;
	int mask = 1;
	printf("Enter the number of items: ");
	scanf_s("%u", &numbOfItems);
	printf("Enter enter their weight:\n");
	for (int i = 0; i < numbOfItems; i++)
	{
		scanf_s("%d", &mass);
		weight[i] = mass;
	}
	printf("Enter enter their value:\n");
	for (int i = 0; i < numbOfItems; i++)
	{
		scanf_s("%d", &val);
		value[i] = val;
	}
	printf("Capacity of your Gucci bag: \n");
	scanf_s("%d", &yourBackpack);
	for (int i = 1; i < (1 << numbOfItems); i++)
	{
		for (int j = 0; j < numbOfItems; j++)
		{
			if (i & mask)
			{
				mass += weight[j];
				val += value[j];
			}
			mask <<= 1;
		}
		if (mass <= yourBackpack)
		{
			if (val > maxValue)
			{
				maxValue = val;
				index = i;
				goodWeight = mass;
			}
		}
		mass = 0;
		val = 0;
		mask = 1;
	}
	printf("------------------------------------------\n");
	printf("Items: ");
	for (int l = 1; l <= numbOfItems; l++)
	{
		printf("%4d", l);
	}
	printf("\n");
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
	mask = 1;
	for (int i = 0; i <= numbOfItems; i++)
	{
		if (index & (mask << i))
		{
			printf("%d ", i + 1);
		}
	}
	printf("\n");
	printf("Wight: %d", goodWeight);
	printf("\n");
	printf("Value: %d", maxValue);
	printf("\n");
}