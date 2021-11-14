#include <iostream>
#include <locale.h>
#include <conio.h>
#include<time.h>
#include <stdlib.h>

int main()
{
	int thing=0;// количесво предметов
	int combinations = 2;// комбинации
	int loadСapacity = -1;//грузоподьемонсть 
	unsigned short int numCom = 0;//номер комбинации
	int massCom = 0;// масса комбинации
	int coinCom = 0;// цена комбинации
	int maxCoin = 0;// максимальная стоимость
	int massMaxCoin=0;// весс комбинации с максимальной стоимостью
	int numMaxCoin = 0;// номер комбинации с максимальной стоимостью
	int cost[100];//стоимость 
	for (int i = 0; i < 100; i++) { cost[i] = 0; }
	int weight[100];//масса предмета
	for (int i = 0; i < 100; i++) { weight[i] = 0; }

    while (thing <= 0) 
	{
	printf("Enter the number of items\n");
       scanf_s("%i", &thing);
	}
	for (int i = 0; i < thing; i++)
	{ 
		printf("Item %i: \n", i + 1);
		printf("Enter the cost of  item\n");
		scanf_s("%i", &cost[i]);
		while (cost[i]<0){printf("Enter the cost of  item\n", i + 1);scanf_s("%i", &cost[i]);}
		printf("Enter the weight of the item\n");
		scanf_s("%i", &weight[i]);
		while (weight[i]<0){printf("Enter the weight of the item\n");scanf_s("%i", &weight[i]);}
	}
	
	while(loadСapacity<0){printf("Enter the load capacity\n");scanf_s("%i", &loadСapacity);}
	for (int i = 1; i < thing; i++) { combinations = combinations * 2; }

	for (numCom=0 ; numCom < combinations; numCom++)
	{
		massCom = 0;
		coinCom = 0;
		for(int i=0; i<16;i++)
		{
			if (numCom & (1<<i)) 
			{
				massCom += weight[i];
				coinCom += cost[i];
			}
		}
		if (massCom <= loadСapacity && coinCom > maxCoin) { maxCoin = coinCom; massMaxCoin = massCom; numMaxCoin = numCom; }
	}
	if(numMaxCoin!=0)
	{ printf("We'll take the items: ");
	for (int i = 0; i < 16; i++)
	{
		if (numMaxCoin & (1 << i))
		{
			printf("%i ", i + 1);
		}
	}
	printf("\n");
	printf("The weight of these items: %i\n", massMaxCoin);
	printf("Maximum cost: %i", maxCoin);
	}
	else {printf("We won't take anything");}

}