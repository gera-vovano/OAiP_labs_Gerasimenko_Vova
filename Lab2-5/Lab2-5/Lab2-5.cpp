/*
����������� �������� �������������
������������ ������ �2.
������� �5
�������: �������� ���������, ������� ��������� ������������ ���� ������������� ��������� �������.
������ � ��� ����� �������� �������������.
*/
	#define _CRT_SECURE_NO_WARNINGS
	#include <stdio.h>
	#include <locale.h>
	#include <conio.h>
	#define SIZE 100
	int CheckArray(int size);
int main()
{
	setlocale(LC_ALL, "Rus");
	int  size = 0;
	printf("������� ����������� ������� �� ����� ��� %d", SIZE);
	printf("\n");
	scanf("%d", &size);
	CheckArray(size);
}
int CheckArray(int size)
{
	int i = 0, result = 0;
	float  multiplication = 1, Array[100] = { 0 };
	if (size <= SIZE)
	{
		for (i = 0; i < size; i++)
		{
			result = 0;
			while (result == 0)
			{
				printf("������� ������� ������� A[%d] = ", i);
				result = scanf("%f", &Array[i]);
				while (getchar() != '\n')
					if (result == 0)
					{
						printf("������� ������� ������ � ���� �����! ");
						break;
					}

				if (Array[i] < 0)
				{
					multiplication *= Array[i];
				}
			}
		}
		if (multiplication == 1)
		{
			printf("������� ���");
		}
		else
		{
			printf("����� = %.2f ", multiplication);
		}
	}
	else
	{
		printf("��������� ����������� �������!");
	}
	_getch();
	return 0;
}
