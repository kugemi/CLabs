#include<stdio.h>
#include<conio.h>
#include <iostream>
#include<locale.h>
#include <math.h>
#define IN 1
#define OUT 0
int horizontal(int array[10][10], int n)
{
	int status = IN;
	int mid = (n / 2);
	for (int j = 0; j < n; j++)
	{
		for (int k = 1; k <= n / 2; k++)
		{
			if (array[mid + k][j] == array[mid - k][j])
			{
				status = IN;
			}
			else
			{
				status = OUT;
				break;
			}
		}
		if (status == OUT)
		{
			break;
		}
	}
	if (status == OUT)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
int Vertical(int array[10][10], int n)
{
	int status = IN;
	int mid = (n / 2);
	for (int j = 0; j < n; j++)
	{
		for (int k = 1; k <= n / 2; k++)
		{
			if (array[j][mid + k] == array[j][mid - k])
			{
				status = IN;
			}
			else
			{
				status = OUT;
				break;
			}
		}
		if (status == OUT)
		{
			break;
		}
	}
	if (status == OUT)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
int Center(int array[10][10], int n)
{
	int status = IN;
	int center = (n / 2);
	for (int j = 0; j < n; j++)
	{
		for (int k = n / 2; k >= 1; k--)
		{
			if (array[center - k][j] == array[center + k][n - 1 - j])
			{
				status = IN;
			}
			else
			{
				status = OUT;
				break;
			}
		}
		if (status == OUT)
		{
			break;
		}
	}
	if (status == OUT)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
int main()
{
	int n = 0;
	int array[10][10] = { 0 };
	printf("You have an array N x N. Enter the value N (N %% 2 != 0): ");
	scanf_s("%d", &n);
	printf("Fill in the array\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d string:\n", i);
		for (int j = 0; j < n; j++)
		{
			scanf_s("%d", &array[i][j]);
		}
	}
	printf("Your array:\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d ", array[i][j]);
		}
		printf("\n");
	}
	printf("Horizontal symmetry: ");
	if (horizontal(array, n) == 1)
	{
		printf("+");
	}
	else
	{
		printf("-");
	}
	printf("\nVertical symmetry: ");
	if (Vertical(array, n) == 1)
	{
		printf("+");
	}
	else
	{
		printf("-");
	}
	printf("\nCenter symmetry: ");
	if (Center(array, n) == 1)
	{
		printf("+");
	}
	else
	{
		printf("-");
	}
}