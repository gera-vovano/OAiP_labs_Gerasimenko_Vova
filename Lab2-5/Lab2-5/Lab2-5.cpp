		/*
		Герасименко Владимир Александрович
		Лабораторная работа №2.
		Вариант №5
		Задание: Написать программу, которая вычисляет произведение всех отрицательных элементов массива.
		Массив и его длина вводятся пользователем.
		*/

	#define _CRT_SECURE_NO_WARNINGS
	#define CONST 100
	#include <stdio.h>
	#include <locale.h>
	#include <conio.h>
	
	int CheckArray(int size);
	int CheckMass(int size,int i);
	int CheckResult(int result);

int main()
{
	setlocale(LC_ALL, "Rus");
	int  size = 0;
	printf("Введите размерность массива не более чем %d \n", CONST);
	scanf("%d", &size);
	CheckArray(size);
}
int CheckMass(int size,int i)
{
	int result;
	float A;
	result = 0;
	while (result == 0)
	{
		printf("Введите элемент массива A[%d]: ", i );
		result = scanf("%f", &A);
		while (getchar() != '\n');
		CheckResult(result);
	}
	return (A);
}
int CheckResult(int result)
{
	if (result == 0)
	{
		printf("Введите входные данные в виде числа! ");
	}
	return 0;
}
int CheckArray(int size)
{
	int i = 0;
	float  multiplication = 1, Array[CONST] = {0};
	if (size <= CONST)
	{
		for (i = 0; i < size; i++)
		{
			Array[i] = CheckMass(size,i);
			if (Array[i] < 0)
			{
				multiplication *= Array[i];
			}
		}
	}
	else 
	{
		printf("Превышена размерность массива");
	}
	if (multiplication == 1)
	{
		printf("решения нет");
	}
	else
	{
		printf("Ответ = %.2f ", multiplication);
	}
	_getch();
	return 0;
}

