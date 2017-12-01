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

void Error(FILE *File1, FILE *File2);
void treatment(FILE *File1, FILE *File2);

void main() {
	system("chcp 1251");
	system("cls");
	FILE *File1,
		*File2;
	File1 = fopen("File1.txt", "r");
	File2 = fopen("File2.txt", "w");
	Error(File1, File2);
	fclose(File1);
	fclose(File2);
}


void Error(FILE *File1, FILE *File2)
{
	if (File1 == NULL)
	{
		fprintf(File2, "Ошибка.Файл не найден!");
		_getch();
		exit(0);
	}
	else
		treatment(File1, File2);
}

void treatment(FILE *File1, FILE *File2)
{
	int check = 0, length;
	char symbol[SIZE];
	length = strlen(symbol);
	while (fgets(symbol, sizeof(symbol), File1) != NULL)
		for (int i = 0; symbol[i]; i++)
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
			fprintf(File2, "%c", symbol[i]);
		}
	if (check == length)
	{
		fprintf(File2, " Заменённых символов нет! ");
	}
}
