#include <stdio.h>

int main(void)
{
	double m, v;

	printf("질량(kg)? ");
	scanf_s("%lf", &m);
	printf("속력(m/s)? ");
	scanf_s("%lf", &v);

	printf("운동에너지: %.2f", 0.5 * m * v * v);
	return 0;
}

//#define _CRT_SECURE_NO_WARNINGS를 선언하고 scanf를 사용하면 빌드가 안되서 scanf_s를 썼습니다.