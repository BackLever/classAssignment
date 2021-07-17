#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

double distance(x1, y1, x2, y2);

int main(void)
{
	int x1, y1, x2, y2;
	printf("직선의 시작점 좌표? ");
	scanf("%d %d", &x1, &y1);
	printf("직선의 끝점 좌표? ");
	scanf("%d %d", &x2, &y2);

	printf("(%d, %d)~(%d, %d) 직선의 길이: %f \n", x1, y1, x2, y2, distance(x1, y1, x2, y2));
	return 0;
}

double distance(x1, y1, x2, y2)
{
	int a = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
	return sqrt(a);
}