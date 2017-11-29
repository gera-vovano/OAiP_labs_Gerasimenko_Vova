/*
Герасименко Владимир Александрович
Лабораторная работа №2.
Вариант №5
Задание:Написать программу, которая во вводимом с клавиатуры тексте заменит буквы «ь» на «ъ» и выведет результат на экран. .
*/
#define _CRT_SECURE_NO_WARNINGS
#include <conio.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <locale>

#define SIZE 100

bool main()
{
	int length, i, check = 0;
	char symbol[SIZE];
	system("chcp 1251");
	system("cls");
	printf("Введите предложение: ");
	fgets(symbol, SIZE, stdin);
	length = strlen(symbol);
	for (i = 0; i < length; i++)
	{
		switch (symbol[i])
			{
			case 'ь': symbol[i] = 'ъ';
				break;
			case 'Ь': symbol[i] = 'Ъ';
				break;
			case 'ъ': symbol[i] = 'ь';
				break;
			case 'Ъ': symbol[i] = 'Ь';
				break;
			default: check++;
				break;
			}
	}
	if ((check == length)||(length==0))
	{
		printf("решения нет");
		_getch();
		return false;
	}
	else
	{
		printf("ответ: ");
		puts(symbol);
		_getch();
		return true;
	}
}