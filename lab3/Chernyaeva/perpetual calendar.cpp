#include<stdio.h>
#include<conio.h>
#include<locale.h>
#include<string.h>
int checkingTheDate(int transmittedMonth,int transmittedYear);
int numberOfDays(int transmittedDay, int transmittedMonth, int transmittedYear);
int main()
{
	setlocale(LC_ALL, "Russian");
	int day,month,year,number;
	day = month = year = number = 0;
	printf("Введите дату: ");
	while ((scanf_s("%d.", &day) == 0) || (scanf_s("%d.", &month) == 0) || (scanf_s("%d.", &year) == 0)|| (checkingTheDate(month,year))||(numberOfDays(day,month,year))){
		
			printf("Неверное введенное значение, попробуйте еще:");
			while (getchar() != '\n');

	}
	if (month >= 3)
		month-=2;
	else
	{
		month+= 10;
		year--;
	}
	printf("\n");
	printf("День недели: ");
	const char *dayOfWeek[7] = {"воскресенье","понедельник","вторник","среда","четверг","пятница","суббота" };
	number = (int(2.6 * month - 0.2)) + day + (year % 100) + ((year % 100) / 4) + ((year / 100) / 4) - 2 * (year / 100);
	number = number % 7;
	if (number < 0)
		number+=7;
	printf("%s", dayOfWeek[number]);
	_getch();
		
}
int checkingTheDate(int transmittedMonth,int transmittedYear) {
	if (((transmittedYear < 1582) || (transmittedYear > 4902))||((transmittedMonth<1)||(transmittedMonth>12))) return 1;
	else return 0;
}
int numberOfDays(int transmittedDay, int transmittedMonth, int transmittedYear) {
	int daysOfMonths[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if ((transmittedYear % 4 == 0)&(transmittedYear%100!=0))
		daysOfMonths[1] = 29;
	if ((transmittedDay > daysOfMonths[transmittedMonth- 1]) || (transmittedDay < 1)) return 1;
	else return 0;
}