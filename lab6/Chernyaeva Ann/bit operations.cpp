#include<stdio.h>
#include<conio.h>
#include<locale.h>
#include<ctype.h>
#include<math.h>

int main()
{
	setlocale(LC_ALL, "Rus");
	unsigned int enteredValue,rightShift, leftShift, mask, shiftSize;
	double degree;
	rightShift = leftShift = shiftSize = degree = 0;
	char shift;
	printf("Введите целое число:");
	scanf_s("%u", &enteredValue);
	printf("Двоичный код числа:");
	mask = 1;
	for (int i = 31; i >= 0; i--)
		if ((enteredValue >> i) & mask)printf("1");
		else printf("0");
	printf("\nВ какую сторону хотите осуществить сдвиг?\nвправо(P) влево(L)\n");
	printf("v");
	shift = _getche();
	shift = toupper(shift);
	if (shift == 'P') {
		printf("ravo");
		printf("\nНа сколько битов вправо хотите осуществить сдвиг?\n>>>>>>>>");
		while ((scanf_s("%d", &rightShift)) != 1) {
			printf("Неверно введеное значение, попробуйте снова\n>>>>>>>>");
			while (getchar() != '\n');
		}
		printf("Двоичный код числа:");
		for (int i = rightShift - 1, degree = 31; i >= 0; i--)
			if (enteredValue & (mask << i)) {
				printf("1");
				shiftSize += pow(2, degree);
				degree--;
			}
			else {
				printf("0");
				degree--;
			}
		for (int i = 31 - rightShift; i >= 0; i--)
			if ((enteredValue >> rightShift) & (mask << i))printf("1");
			else printf("0");
		printf("\nЧисло:%u", (enteredValue >> rightShift) + shiftSize);
		printf("\nvlevo\nНа сколько битов влево хотите осуществить сдвиг?\n<<<<<<<<");
		while ((scanf_s("%d", &leftShift)) != 1) {
			printf("Неверно введеное значение, попробуйте снова\n>>>>>>>>");
			while (getchar() != '\n');
		}
		printf("Двоичный код числа:");
		for (int i = 31; i >leftShift-1; i--)
			if ((enteredValue << leftShift) & (mask << i))printf("1");
			else printf("0");
		shiftSize = 0;
		for (int i = 31, degree = leftShift - 1; i >31 - leftShift; i--)
			if (enteredValue & (mask << i)) {
				printf("1");
				shiftSize += pow(2, degree);
				degree--;
			}
			else {
				printf("0");
				degree--;
			}
		printf("\nЧисло:%u", (enteredValue << leftShift) + shiftSize);



	}
	if (shift == 'L') {
		printf("evo\nНа сколько битов влево хотите осуществить сдвиг?\n<<<<<<<<");
		while ((scanf_s("%d", &leftShift)) != 1) {
			printf("Неверно введеное значение, попробуйте снова\n>>>>>>>>");
			while (getchar() != '\n');
		}
		printf("Двоичный код числа:");
		for (int i = 31; i > leftShift - 1; i--)
			if ((enteredValue << leftShift) & (mask << i))printf("1");
			else printf("0");
		for (int i = 31, degree = leftShift - 1; i > 31 - leftShift; i--)
			if (enteredValue & (mask << i)) {
				printf("1");
				shiftSize += pow(2, degree);
				degree--;
			}
			else {
				printf("0");
				degree--;
			}
		printf("\nЧисло:%u", (enteredValue << leftShift) + shiftSize);
		printf("\nvpravo\nНа сколько битов вправо хотите осуществить сдвиг?\n>>>>>>>>");
		while ((scanf_s("%d", &rightShift)) != 1) {
			printf("Неверно введеное значение, попробуйте снова\n>>>>>>>>");
			while (getchar() != '\n');
		}
		printf("Двоичный код числа:");
		shiftSize = 0;
		for (int i = rightShift - 1, degree = 31; i >= 0; i--)
			if (enteredValue & (mask << i)) {
				printf("1");
				shiftSize += pow(2, degree);
				degree--;
			}
			else {
				printf("0");
				degree--;
			}
		for (int i = 31 - rightShift; i >= 0; i--)
			if ((enteredValue >> rightShift) & (mask << i))printf("1");
			else printf("0");
		printf("\nЧисло:%u", (enteredValue >> rightShift) + shiftSize);

	}
}