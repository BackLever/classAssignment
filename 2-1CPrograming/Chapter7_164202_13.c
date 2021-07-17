#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void)
{
	unsigned char image1[16], image2[16], image3[16];
	int i, j;

	srand((unsigned int)time(0));
	for (i = 0; i < 16; i++) {
		image1[i] = rand() % 256;
		image2[i] = rand() % 256;
	}

	for (i = 0; i < 16; i++)
		image3[i] = image1[i] | image2[i];

	for (j = 0; j < 3; j++) {
		printf("image%d: ", j+1);

		if (j == 0)
			for (i = 0; i < 16; i++)
				printf("%02X ", image1[i]);
		else if (j == 1)
			for (i = 0; i < 16; i++)
				printf("%02X ", image2[i]);
		else if (j == 2)
			for (i = 0; i < 16; i++)
				printf("%02X ", image3[i]);

		printf("\n");
	}
	return 0;
}