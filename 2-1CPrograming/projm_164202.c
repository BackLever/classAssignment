#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

double myPower(double num, int order);
double myRoot(double num, int order, double precision);

int main(void)
{
	double num1, num2;
	int order1, order2;
	double preci;

	printf("제곱할 값(실수)과 차수(정수)를 입력하세요 ");
	scanf("%lf %d", &num1, &order1);
	printf("%f의 %d제곱: %f\n", num1, order1, myPower(num1, order1));

	printf("제곱근을 구할 값과 차수, 정밀도를 입력하세요 ");
	scanf("%lf %d %lf", &num2, &order2, &preci);
	printf("%f의 %d제곱근: %.12f\n", num2, order2, myRoot(num2, order2, preci));

	return 0;
}

double myPower(double num, int order)
{
	int i;
	double result = 1;

	if (order == 0)
		return 1;
	else if (order > 0) {
		for (i = 0; i < order; i++)
			result *= num;
		return result;
	}
	else {
		for (i = 0; i < -order; i++)
			result *= num;
		return 1 / result;
	}
}

double myRoot(double num, int order, double precision)
{
	double rnum, lnum, mnum, pnum;
	
	if (num > 0)
	{
		rnum = num;
		lnum = 0;
		while (1) {
			mnum = (rnum + lnum) / 2;
			pnum = myPower(mnum, order);

			if (pnum < num)
				lnum = mnum;
			else if (pnum > num)
				rnum = mnum;

			if (pnum < num + precision && pnum > num - precision)
				return mnum;
		}
	}

	return -1;
}