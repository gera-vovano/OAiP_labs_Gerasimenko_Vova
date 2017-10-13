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

int main() {
	setlocale(LC_ALL, "Rus");
	float lot, otv_inCarat, otv_inOunce;
	printf("введите число в лотах \n");

	int result = scanf("%f", &lot);
	if ((lot >= 0) && (result == 1)&& (lot<_CRT_INT_MAX))
	//scanf("%f", &lot);
	//if ((lot>=0)&&(lot<_CRT_INT_MAX))
	{
		otv_inCarat = lot*CARAT;
		otv_inOunce = lot * OUNCE;
		printf("ответ в каратах = %f \n", otv_inCarat);
		printf("ответ в унциях = %f \n", otv_inOunce);
	}
	else
	{
		printf("нет решения или неверный формат вводимых данных \n");
	}
	_getch();
	return 0;
}
