/*
Герасименко Владимир Александрович
Лабораторная работа №2.
Вариант №5
Задание: Написать программу, которая вычисляет произведение всех отрицательных элементов массива.
Массив и его длина вводятся пользователем.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <conio.h>
#define SIZE 100
int CheckArray(int size);
int CheckMass(int size);

int main()
{
	setlocale(LC_ALL, "Rus");
	int  size = 0;
	printf("Введите размерность массива не более чем %d", SIZE);
	printf("\n");
	scanf("%d", &size);
	CheckArray(size);
}
int CheckMass(int size)
{
	int result, i;
	float A;

	result = 0;
	while (result == 0)
	{
		printf("Введите элемент массива ");
		result = scanf("%f", &A);
		while (getchar() != '\n')
			if (result == 0)
			{
				printf("Введите входные данные в виде числа! ");
				break;
			}
	}
	return (A);
}
int CheckArray(int size)
{
	int i = 0, result = 0;
	float  multiplication = 1, Array[100];
	if (size <= SIZE)
	{

		for (i = 0; i < size; i++)
		{
			Array[i] = CheckMass(size);
			if (Array[i] < 0)
			{
				multiplication *= Array[i];
			}
		}

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

