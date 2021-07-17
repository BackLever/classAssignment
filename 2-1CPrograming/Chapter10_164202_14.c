#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct point {
	int x;
	int y;
}POINT;

typedef struct rect {
	POINT left_bottom;
	POINT right_top;
}RECT;

void normalize_rect(RECT* x);
POINT center_rect(RECT x);

int main(void)
{
	RECT rect[3];
	int i;
	char blank = ' ';

	srand((unsigned char)time(0));
	for (i = 0; i < 3; i++)
	{
		rect[i].left_bottom.x = rand() % 100;
		rect[i].left_bottom.y = rand() % 100;
		rect[i].right_top.x = rand() % 100;
		rect[i].right_top.y = rand() % 100;

	}

	for (i = 0; i < 3; i++)
	{
		normalize_rect(&rect[i]);
		printf("[RECT 좌하단점:(%2d, %2d) 우상단점:(%2d, %2d)]", 
			rect[i].left_bottom.x, rect[i].left_bottom.y, rect[i].right_top.x, rect[i].right_top.y);
		printf("    중심점: (%2d, %2d)\n", center_rect(rect[i]).x, center_rect(rect[i]).y);
	}
	return 0;
}

void normalize_rect(RECT* x)
{
	int temp;
	if (x->left_bottom.x > x->right_top.x)
	{
		temp = x->left_bottom.x;
		x->left_bottom.x = x->right_top.x;
		x->right_top.x = temp;
	}

	if (x->left_bottom.y > x->right_top.y)
	{
		temp = x->left_bottom.y;
		x->left_bottom.y = x->right_top.y;
		x->right_top.y = temp;
	}
}


POINT center_rect(RECT x)
{
	POINT cent;
	cent.x = (x.left_bottom.x + x.right_top.x) / 2;
	cent.y = (x.left_bottom.y + x.right_top.y) / 2;
	return cent;
}