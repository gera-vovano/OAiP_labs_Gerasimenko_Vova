/*
Герасименко Владимир Александрович
Лабораторная работа №2.
Вариант №5
Задание:Написать программу, которая со считываемого файла тексте заменит буквы «ь» на «ъ» и выведет результат в другой файл.
*/
#define _CRT_SECURE_NO_WARNINGS 
#define SIZE 100 

#include <stdio.h> 
#include <locale> 
#include <conio.h> 

void checkError(FILE *File1, FILE *File2);
void treatment(FILE *File1, FILE *File2);
void openFile(void);
void replacement(int i, char *symbol);
int *flag;

void main() 
{
	system("chcp 1251");
	system("cls");
	openFile();
}

void openFile(void)
{
	FILE
		*File1,
		*File2;
	File1 = fopen("File1.txt", "r");
	File2 = fopen("File2.txt", "w");
	checkError(File1, File2);
	treatment(File1, File2);
	fclose(File1);
	fclose(File2);
}

void checkError(FILE *File1, FILE *File2)
{
	if (File1 == NULL)
	{
		fprintf(File2, "Ошибка.Файл не найден!");
		_getch();
		exit(0);
	}
		
}

void treatment(FILE *File1, FILE *File2)
{
	int check = 0, length;
	char symbol[SIZE];
	while (fgets(symbol, sizeof(symbol), File1) != NULL)
		for (int i = 0; symbol[i]; i++)
		{
			replacement(i,symbol);
			fprintf(File2, "%c", symbol[i]);
		}
	
}

void replacement(int i,char *symbol)
{
	switch (symbol[i])
	{
	case 'ь':
		symbol[i] = 'ъ';
		break;
	case 'Ь':
		symbol[i] = 'Ъ';
		break;
	}
}
