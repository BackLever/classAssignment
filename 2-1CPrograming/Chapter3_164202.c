//전자컴퓨터공학부 164202 양진형
//Chapter3_2번문제

#include <stdio.h>

int main(void)
{
	int numA, numB;
	printf("가로의 길이? ");
	scanf_s("%d", &numA);
	printf("세로의 길이? ");
	scanf_s("%d", &numB);
	printf("직사각형의 넓이: %d \n", numA * numB);
	printf("직사각형의 둘레: %d \n", (numA + numB) * 2);
	return 0;
}

//Chapter3_6번문제

#include <stdio.h>

int main(void)
{
	const double i = 0.3025;
	double area;
	printf("아파트의 면적(제곱미터)? ");
	scanf_s("%lf", &area);
	printf("%.2f 제곱미터 = %.2f 평 \n", area, area * i);
	return 0;
}

//Chapter3_10번문제

#include <stdio.h>

int main(void)
{
	double usd, er;
	printf("USD? ");
	scanf_s("%lf", &usd);
	printf("원/달러 환율? ");
	scanf_s("%lf", &er);
	printf("USD %.2f = KRW %.2f \n", usd, usd * er);
	return 0;
}