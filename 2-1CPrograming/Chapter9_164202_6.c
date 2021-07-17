#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int check_time_str(char timestr[]);

int main(void)
{
	char time[100];

	do {
		printf("시간(.입력 시 종료)? ");
		gets_s(time, sizeof(time));
		check_time_str(time);
	} while (strcmp(time, ".") != 0);

	return 0;
}

int check_time_str(char timestr[])
{
	unsigned int n, i;
	char* p = timestr;

	sscanf(timestr, "%d", &n);
	if (strcmp(timestr, ".") == 0)
		return 0;

	for (i = 0; i < strlen(timestr); i++) {
		if (isalpha(*p)) {
			printf("잘못 입력했습니다. hhmmss형식으로 입력하세요.\n");
			return 0;
		}
		p++;
	}

	if (strlen(timestr) != 6)
		printf("잘못 입력했습니다. hhmmss형식으로 입력하세요.\n");
	else if (n / 10000 < 24 && n / 100 - n / 10000 * 100 < 60 && n % 100 < 60)
		printf("%06d는 유효한 시간입니다.\n", n);
	else
		printf("잘못 입력했습니다. hhmmss형식으로 입력하세요.\n");
	return 0;
}