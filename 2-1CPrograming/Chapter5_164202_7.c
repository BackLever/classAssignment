#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void)
{
	double numA, numB, numC = 0;
	printf("월 사용량 (kWh)? ");
	scanf("%lf", &numA);

	if (numA > 400) {
		numB = 7300;
		numC = 200 * 93.3 + 200 * 187.9;
		printf("전기 요금 합계: %6.0f원 \n", numB + numC + (numA - 400) * 280.6);
		printf("  - 기본 요금 : %6.0f원 \n", numB);
		printf("  - 전력량요금: %6.0f원 \n", numC + (numA - 400) * 280.6);
	}
	else if (numA > 200) {
		numB = 1600;
		numC = 200 * 93.3;
		printf("전기 요금 합계: %6.0f원 \n", numB + numC + (numA - 200) * 187.9);
		printf("  - 기본 요금 : %6.0f원 \n", numB);
		printf("  - 전력량요금: %6.0f원 \n", numC + (numA - 200) * 187.9);
	}
	else {
		numB = 910;
		printf("전기 요금 합계: %6.0f원 \n", numB + numA * 93.3);
		printf("  - 기본 요금 : %6.0f원 \n", numB);
		printf("  - 전력량요금: %6.0f원 \n", numA * 93.3);
	}
	return 0;
}