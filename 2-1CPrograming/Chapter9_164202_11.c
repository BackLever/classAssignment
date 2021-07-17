#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int function(char word[], char last);

int main(void)
{
	char word[100];
	char* p = word;
	char last;
	int count = 0;
	int k;

	printf("word? ");
	gets_s(word, sizeof(word));
	last = p[strlen(word) - 1];

	while (1) {
		printf("word? ");
		gets_s(word, sizeof(word));

		k = function(word, last);

		if (k == -1)
			break;
		else if (k == 1)
		{
			last = p[strlen(word) - 1];
			count++;
		}
	}
	printf("count: %d", count);
	return 0;
}

int function(char word[], char last)
{
	if (strlen(word) < 3) {
		printf("too short, try again\n");
		return 0;
	}
	else if (word[0] != last) {
		printf("Wrong word! You failed!\n");
		return -1;
	}
	else
		return 1;
}