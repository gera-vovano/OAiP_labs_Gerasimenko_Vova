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
int main() 
{
	setlocale(LC_ALL, "Rus");
	int i, size, result,check,pr;
	float  multiplication = 1, Array[SIZE];
	printf("Введите размерность массива не более чем %d",SIZE);
	printf("\n");
	scanf("%d", &size);
	if (size <= SIZE)
	{
		for (i = 0; i < size; i++)
		{
		result = 0;
		check = 0;
		while (result == 0){
		check++;
		printf("Введите элемент массива A[%d] = ",i);
		result = scanf("%f", &Array[i]);

		while (!scanf("%f", &Array[i]))
		while (getchar() != '\n');
			if (check > 1)
			{
				printf("Введите входные данные в виде числа!");
				printf("\n");
			}
					
			if (Array[i] < 0) 
				{
				multiplication *= Array[i];
				printf("%f", multiplication);}
				}
		}
		
		if (multiplication == 1) printf("решения нет");
		else printf("Ответ = %.2f ", multiplication);
	}
	else printf("Превышена размерность массива!");

	_getch();
	return 0;
}
