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
#include <stdlib.h>

#define SIZE 100

int main()
{	FILE *F1, *F2;
	F1 = fopen("C:/github/OAiP_labs_Gerasimenko_Vova/Lab4-5/F1.txt", "r");
		int length, i, check = 0;
		char symbol[SIZE];
		system("chcp 1251");
		system("cls");
		fgets(symbol, SIZE, F1);
		length = strlen(symbol);
		if (symbol == 0)
		{
			printf(" ���� � �������� ������� ������! ");
			return 0;
		}
		else
		{
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
			F2 = fopen("C:/github/OAiP_labs_Gerasimenko_Vova/Lab4-5/F2.txt", "w");
			if ((check == length)||(length==0))
			{
				fprintf(F2,"������� ���");
				fclose(F2);
			}
			else
			{
				fprintf(F2,"�����: ");
				fputs(symbol,F2);
				fclose(F2);
			}
	}
	system("pause");
	return 0;
}