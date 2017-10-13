#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <cstdlib>

int main() {
	setlocale(LC_ALL, "Rus");
	int x;
	double otv1, otv2;
	printf("введите число в лотах \n");
	scanf("%d", &x);
		if (x > 0) {
		otv1 = x*63.986257;
		printf("ответ в каратах = %f \n", otv1);
		otv2 = otv1 * 0.0071;
		printf("ответ в унциях = %f \n", otv2);
	}
	else {
		printf("нет решения или неверный формат вводимых данных \n");
	}
	system("pause");
	return 0;

}
