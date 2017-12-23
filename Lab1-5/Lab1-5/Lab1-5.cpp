/*
Герасименко Владимир Александрович
Лабораторная работа №1.
Вариант №5
Задание: Перевести лот в карат и выразить в унциях.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <locale.h>
#include <conio.h>

#define CARAT 63.98626
#define OUNCE 0.451410

void working();
void calculations(int result, int lot);

int main() 
{
	setlocale(LC_ALL, "Rus");
	working();
	_getch();
	return 0;
}

void working()
{
	float lot;
	printf("введите число в лотах \n");
	int result = scanf("%f", &lot);
	calculations(result, lot);

}

void calculations(int result, int lot)
{
	float otvInCarat, otvInOunce;
	if ((lot >= 0) && (result == 1) && (lot<_CRT_INT_MAX))
	{
		printf("ответ в каратах = %f \n", lot*CARAT);
		printf("ответ в унциях = %f \n", lot * OUNCE);
	}
	else
	{
		printf("нет решения или неверный формат вводимых данных \n");
	}
}
