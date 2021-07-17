#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int is_bit_set(int Z, int pos);

int main(void)
{
	int num, pos, j=0;

	printf("정수? ");
	scanf("%X", &num);
	printf("%X: ", num);

	for (pos = 31; pos >= 0; pos--)
	{
		printf("%d", is_bit_set(num, pos));
		j++;
		if (j % 4 == 0)
			printf(" ");
	}
	return 0;
}

int is_bit_set(int Z, int pos)
{
	Z >>= pos;
	if (pos > 32 || pos < -1)
		return -1;
	if (Z % 2 == 1)
		return 1;
	else
		return 0;
}