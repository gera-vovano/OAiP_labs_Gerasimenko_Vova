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
int main() 
{
	setlocale(LC_ALL, "Rus");
	int i, size, result,check,pr;
	float  multiplication = 1, Array[SIZE];
	printf("������� ����������� ������� �� ����� ��� %d",SIZE);
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
		printf("������� ������� ������� A[%d] = ",i);
		result = scanf("%f", &Array[i]);

		while (!scanf("%f", &Array[i]))
		while (getchar() != '\n');
			if (check > 1)
			{
				printf("������� ������� ������ � ���� �����!");
				printf("\n");
			}
					
			if (Array[i] < 0) 
				{
				multiplication *= Array[i];
				printf("%f", multiplication);}
				}
		}
		
		if (multiplication == 1) printf("������� ���");
		else printf("����� = %.2f ", multiplication);
	}
	else printf("��������� ����������� �������!");

	_getch();
	return 0;
}
