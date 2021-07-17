#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

void remove_space(char str[]);

int main(void)
{
	char str[100] = "";
	printf("문자열? ");
	gets_s(str, sizeof(str));

	remove_space(str);

	printf("공백 문자 제거후: %s", str);
	return 0;
}

void remove_space(char str[]) //배열사용
{
	int i, index = 0;

	for (i=0;str[i]!=0;i++)
		if (str[i] != ' ')
		{
			str[index] = str[i];
			index++;
		}
	str[index] = 0;

}
/*
void remove_space(char str[]) //포인터사용
{
	char* p = str; 

	while (*str != 0) {
		if (*str != ' ')
		{
			*p = *str;
			p++;
		}
		str++;
	}
	*p = 0;
}
*/