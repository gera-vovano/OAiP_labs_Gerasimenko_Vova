/*
����������� �������� �������������
������������ ������ �2.
������� �5
�������:�������� ���������, ������� �� �������� � ���������� ������ ������� ����� ��� �� ��� � ������� ��������� �� �����. .
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
	printf("������� �����������: ");
	fgets(symbol, SIZE, stdin);
	length = strlen(symbol);
	for (i = 0; i < length; i++)
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
	}
	if ((check == length)||(length==0))
	{
		printf("������� ���");
		_getch();
		return false;
	}
	else
	{
		printf("�����: ");
		puts(symbol);
		_getch();
		return true;
	}
}