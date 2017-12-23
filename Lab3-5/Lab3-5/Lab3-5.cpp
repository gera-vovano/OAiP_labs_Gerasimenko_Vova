/*
Герасименко Владимир Александрович
Лабораторная работа №3.
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

void working(void);
void treatment(int length,char *symbol), verify(int check, int length);

bool main()
{
	system("chcp 1251");
	system("cls");
	working();
	_getch();
}

//Процесс работы программы
void working()
{
	int length;
	char symbol[SIZE];
	printf("Введите предложение: ");
	fgets(symbol, SIZE, stdin);
	length = strlen(symbol);
	treatment(length, symbol);
	printf("ответ: ");
	puts(symbol);
}

//Проверка каждого символа на "Ь" и "ь"
void treatment(int length,char *symbol)
{
	int check = 0;
	for (int i = 0; i < length; i++)
	{
		switch (symbol[i])
		{
		case 'ь': symbol[i] = 'ъ';
			break;
		case 'Ь': symbol[i] = 'Ъ';
			break;
		default: check++;
			break;
		}
	}
	verify(check, length);
}

//Проверка на кол-во незаменённых символов, если в вводимой строке нет символов "Ь" и "ь", то выводится сообщение о ошибке
void verify(int check,int length)
{
	if ((check == length) || (length == 0))
	{
		printf("решения нет");
		_getch();
	}
}