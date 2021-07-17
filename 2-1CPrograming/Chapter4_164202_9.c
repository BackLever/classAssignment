#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int runtime;
	int h, m, s;

	printf("재생시간(초)? ");
	scanf("%d", &runtime);
	printf("재생시간은");

	h = runtime / 3600;
	h > 0 ? printf(" %d시간", h) : 0 ;

	m = runtime / 60 - h * 60;
	m > 0 ? printf(" %d분", m) : 0 ;

	s = runtime - h * 3600 - m * 60;
	s > 0 ? printf(" %d초", s) : 0 ;

	printf("입니다.\n");
	return 0;
}