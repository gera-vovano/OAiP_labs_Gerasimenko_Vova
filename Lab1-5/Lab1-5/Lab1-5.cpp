/*
����������� �������� �������������
������������ ������ �1.
������� �5
�������: ��������� ��� � ����� � �������� � ������.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <conio.h>
#define CARAT 63.98626
#define OUNCE 0.451410

int main() {
	setlocale(LC_ALL, "Rus");
	double lot;
	double otv_inCarat, otv_inOunce;
	printf("������� ����� � ����� \n");
	int result = scanf("%f", &lot);
	if (result == 1) {
		otv_inCarat = lot*CARAT;
		otv_inOunce = lot * OUNCE;
		printf("����� � ������� = %f \n", otv_inCarat);
		printf("����� � ������ = %f \n", otv_inOunce);
	}
		else printf("��� ������� ��� �������� ������ �������� ������ \n");
	_getch();
	return 0;
}
/*
P.S. ����������, ����������, ��� �������, ����� ���������� ���� �����������? 
������ � ����� 1 � �� ���� ��������� ������ ������� ��������, 
�� ������� ���������� � �������� �����*/