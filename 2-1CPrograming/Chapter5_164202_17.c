#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void)
{
	int min, fee = 3000;
	printf("주차 시간(분)? ");
	scanf("%d", &min);
	
	if (min > 1440) {
		printf("주차 시간은 최대 24시간(1440분)을 넘을 수 없습니다. \n");
	}
	else if (min == 0) {
		printf("주차 요금: 0원 \n");
	}
	else if (min > 30) {
		fee += (min - 30) / 10 * 1000;
		if (fee > 25000)
			fee = 25000;
		printf("주차 요금: %d원 \n", fee);
	}
	else {
		printf("주차 요금: %d원 \n", fee);
	}
	return 0;
}