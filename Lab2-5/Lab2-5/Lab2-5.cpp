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
#include<stdlib.h> //установка русского языка

void working();
void checkArray(int size);
int checkMass(int size, int i);
int checkResult(int result);
void counterItems(int size, float *array);
void checkMultiplication(float multiplication);

int main()
{
	system("chcp 1251");
	system("cls");
	working();
	system("PAUSE");
}

//процесс работы
void working()
{
	int  size = 0;
	printf("Введите размерность массива не более чем %d \n", CONST);
	scanf("%d", &size);
	checkArray(size);
}

//проверка размерности массива. 
void checkArray(int size)
{

	float array[CONST] = { 0 };
	if (size <= CONST)
	{
		counterItems(size, array);
	}
	else
	{
		printf("Превышена размерность массива, повторите попытку ввода!\n");
		working();//возвращает на ввод размерности массива
	}
}

//Проверка каждого элемента
void counterItems(int size, float *array)
{
	float multiplication = 1;
	for (int i = 0; i < size; i++)
	{
		array[i] = checkMass(size, i);//отправка на ввод элемента массива
		if (array[i] < 0)
		{
			multiplication *= array[i];
		}
	}
	checkMultiplication(multiplication);
}

//Проверка, если начальное произведения осталось без изменеия"1", то выводится сообщение, что решения нет. ИНАЧЕ выводится ответ работы программы
void checkMultiplication(float multiplication)
{
	if (multiplication == 1)
	{
		printf("решения нет");
	}
	else
	{
		printf("Ответ = %.2f ", multiplication);
	}
}

//ввод элемента
int checkMass(int size, int i)
{
	int result;
	float A;
	result = 0;
	while (result == 0)
	{
		printf("Введите элемент массива A[%d]: ", i);
		result = scanf("%f", &A);
		while (getchar() != '\n');
		checkResult(result);
	}
	return (A);
}

// проверка, чтобы вводимые данные были числом
int checkResult(int result)
{
	if (result == 0)
	{
		printf("Введите входные данные в виде числа! ");
	}
	return 0;
}


