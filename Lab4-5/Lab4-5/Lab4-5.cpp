/*
����������� �������� �������������
������������ ������ �2.
������� �5
�������:�������� ���������, ������� �� ������������ ����� ������ ������� ����� ��� �� ��� � ������� ��������� � ������ ����.
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
		fprintf(File2, "������.���� �� ������!");
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
			case '�': symbol[i] = '�';
				break;
			case '�': symbol[i] = '�';
				break;
			case '�': symbol[i] = '�';
				break;
			case '�': symbol[i] = '�';
				break;
			default: check++;
				break;
			}
			fprintf(File2, "%c", symbol[i]);
		}
	if (check == length)
	{
		fprintf(File2, " ��������� �������� ���! ");
	}
}
