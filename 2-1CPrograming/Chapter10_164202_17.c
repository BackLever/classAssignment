#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

enum genre { BALLAD = 1, HIPHOP, DANCE , ROCK};

typedef struct song {
	char songname[20];
	char artist[20];
	int genre;
	int playtime;
}SONG;

int main(void)
{
	SONG songlist[] = {
		{"Godzilla", "Eminem", HIPHOP, 211},
		{"에잇", "아이유", ROCK, 168},
		{"살짝 설렜어", "오마이걸", DANCE, 203},
		{"Aqua Man", "빈지노", HIPHOP, 226},
		{"Psycho", "레드벨벳", DANCE, 211},
		{"가시", "버즈", BALLAD, 241},
		{"붕붕", "김하온", HIPHOP, 234},
		{"연애소설", "에픽하이", HIPHOP, 236},
		{"사람냄새", "정인, 개리", HIPHOP, 208}
	};
	int i;
	char* index = NULL;
	char key[20];
	int size = sizeof(songlist) / sizeof(songlist[0]);

	/*printf("%-16s %-10s %-10s %s \n", "제목", "아티스트", "장르", "재생시간");
	for (i = 0; i < size; i++)
	{
		printf("%-16s ", songlist[i].songname);
		printf("%-10s ", songlist[i].artist);
		switch (songlist[i].genre)
		{
		case BALLAD:
			printf("%-10s ", "ballad");
			break;
		case HIPHOP:
			printf("%-10s ", "hip-hop");
			break;
		case DANCE:
			printf("%-10s ", "dance");
			break;
		case ROCK:
			printf("%-10s ", "rock");
			break;
		}
		printf("%d초\n", songlist[i].playtime);
	}*/

	do {
		printf("키워드(제목/아티스트)? ");
		gets_s(key, sizeof(key));
		for (i = 0; i < size; i++)
		{
			index = strstr(songlist[i].songname, key);
			if (index != NULL)
			{
				printf("%-16s ", songlist[i].songname);
				printf("%-10s ", songlist[i].artist);
				switch (songlist[i].genre)
				{
				case BALLAD:
					printf("%-10s ", "ballad");
					break;
				case HIPHOP:
					printf("%-10s ", "hip-hop");
					break;
				case DANCE:
					printf("%-10s ", "dance");
					break;
				case ROCK:
					printf("%-10s ", "rock");
					break;
				}
				printf("%d초\n", songlist[i].playtime);
			}
			index = NULL;
			index = strstr(songlist[i].artist, key);
			if (index != NULL)
			{
				printf("%-16s ", songlist[i].songname);
				printf("%-10s ", songlist[i].artist);
				switch (songlist[i].genre)
				{
				case BALLAD:
					printf("%-10s ", "ballad");
					break;
				case HIPHOP:
					printf("%-10s ", "hip-hop");
					break;
				case DANCE:
					printf("%-10s ", "dance");
					break;
				case ROCK:
					printf("%-10s ", "rock");
					break;
				}
				printf("%d초\n", songlist[i].playtime);
			}
			index = NULL;
		}
	} while (strcmp(".", key) != 0);
	return 0;
}