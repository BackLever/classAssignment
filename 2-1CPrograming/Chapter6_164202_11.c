#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

double calculator(double num1, char op, double num2);

int main(void)
{
	double num1, num2;
	char op;

	while (1)
	{
		printf("수식 (0 0 0 입력 시 종료)? ");
		scanf("%lf %c %lf", &num1, &op, &num2);

		if (num1 == 0 && num2 == 0 && op == '0')
			break;

		printf("%f\n", calculator(num1, op, num2));
	}
	return 0;
}

double calculator(double num1, char op, double num2)
{
	switch (op) {
	case '+':
		return num1 + num2;
		break;
	case '-':
		return num1 - num2;
		break;
	case '*':
		return num1 * num2;
		break;
	case '/':
		if (num2 != 0)
			return num1 / num2;
		else
			printf("0으로 나눌 수 없습니다.\n");
		break;
	default:
		printf("잘못된 수식입니다.\n");
		break;
	}
}