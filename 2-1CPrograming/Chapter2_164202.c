//컴퓨터정보통신전공 164202 양진형
//Chapter2_3번문제

#include <stdio.h>

int main(void)
{
	int y, m, d;
	printf("연? ");
	scanf_s("%d", &y);
	printf("월? ");
	scanf_s("%d", &m);
	printf("일? ");
	scanf_s("%d", &d);
	printf("입력하신 날짜는 %d년 %d월 %d일입니다.\n", y, m, d);
	return 0;
}

//Chapter2_10번문제

#include <stdio.h>

int main(void)
{
	int num;
	printf("8진수로 입력하려면 012, 16진수로 입력하려면 0x12처럼 입력하세요. \n");
	printf("정수? ");
	scanf_s("%i", &num);

	printf(" 8진수: %#o \n", num);
	printf("10진수: %d \n", num);
	printf("16진수: %#x \n", num);
	return 0;
}

//Chapter2_12번문제

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	char name[20], major[20], num[20];
	printf("이름? ");
	scanf("%s", name);
	printf("학과? ");
	scanf("%s", major);
	printf("학번? ");
	scanf("%s", num);

	printf("=============================== \n");
	printf("이름: %s \n", name);
	printf("학과: %s \n", major);
	printf("학번: %s \n", num);
	printf("=============================== \n");
	return 0;
}
