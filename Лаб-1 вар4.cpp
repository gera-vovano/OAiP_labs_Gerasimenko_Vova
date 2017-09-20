#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
using namespace std;
int main() {
	int x = 0;
	double otv1, otv2;
	printf("vvedite chislo v lotah \n");
	scanf("%d", &x);
	otv1 = x*63.986257;
	printf("otvet v karatah = %f \n", otv1);
	otv2 = otv1 * 0.0007;
	printf("otvet v ynziyh %f \n", otv2);
	return 0;

}