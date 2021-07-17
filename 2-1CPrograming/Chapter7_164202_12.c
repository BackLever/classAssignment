#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#define SIZE 10

int main(void)
{
	int seat[SIZE] = { 0 };
	int i, j, temp, k = 0;

	while (k < SIZE)
	{
		printf("현재 좌석: [");

		for (i = 0; i < SIZE; i++) {
			if (seat[i] == 0)
				printf(" 0");
			else
				printf(" X");
		}
		printf(" ]\n");

		printf("예매할 좌석수? ");
		scanf("%d", &temp);

		k += temp;
		if (k > 10) {
			printf("10좌석 이상 예매할수 없습니다.");
			break;
		}

		for (i = 0, j = 0; j < temp;) {
			if (seat[i] == 0) {
				seat[i] = 1;
				j++;
				printf("%d ", i+1);
			}
			i++;
		}
		printf("번 좌석을 예매했습니다. \n");
	}

	return 0;
}