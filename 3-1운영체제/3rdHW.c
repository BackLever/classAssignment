#include<Windows.h>
#include<stdio.h>

#define THREADCOUNT 4

HANDLE ghMutex;

DWORD LSD_freq[10];
DWORD MSD_freq[10];

struct Params {
	int start;
	int end;
	int k;
};

int coprime(int A, int B)
{
	int r, q;
	while (1) {
		q = A / B;
		r = A % B;
		if (r == 0)
			break;
		A = B;
		B = r;
	}
	if (B == 1)
		return TRUE;
	else
		return FALSE;
}

DWORD WINAPI get_LSD_MSD(LPVOID p_) {
	struct Params p = *(struct Params*)p_;
	int LSD, MSD;
	
	printf("%d ", GetCurrentThreadId());
	for (int i = p.start; i <= p.end; i++) {
		if (coprime(p.k, i) == TRUE) {
			LSD = i % 10;
			int n = i;
			while (1) {
				if (n / 10 == 0) {
					MSD = n;
					break;
				}
				n /= 10;
			}
			WaitForSingleObject(
				ghMutex,
				INFINITE
			);
			LSD_freq[LSD]++;
			MSD_freq[MSD]++;
			ReleaseMutex(ghMutex);
		}
	}
	return 0;
}

int main()
{
	DWORD ThreadId;
	HANDLE ThreadHandle[THREADCOUNT];
	struct Params p[THREADCOUNT];
	int m = 10000;
	int n = 3000000;
	int k = 210;
	int batch = (n - m) / THREADCOUNT;
	double LSD_sum = 0, MSD_sum = 0;

	memset(LSD_freq, 0, sizeof(LSD_freq));
	memset(MSD_freq, 0, sizeof(MSD_freq));

	ghMutex = CreateMutex(
		NULL,
		FALSE,
		NULL
	);
	if (ghMutex == NULL) {
		printf("CreateMutex error: %d\n", GetLastError());
		return -1;
	}

	printf("Run Thread... ");
	for (int i = 0; i < THREADCOUNT; i++) {
		p[i].k = k;
		if (i == 0) {
			p[i].start = m;
			p[i].end = p[i].start + batch;
		}
		else {
			p[i].start = p[i - 1].end + 1;
			p[i].end = p[i].start + batch - 1;
		}

		ThreadHandle[i] = CreateThread(
			NULL,
			0,
			get_LSD_MSD,
			&p[i],
			0,
			&ThreadId
		);
		if (ThreadHandle[i] == NULL) {
			printf("Create Thread Error: %d\n", GetLastError());
			return -1;
		}
	}

	WaitForMultipleObjects(
		THREADCOUNT,
		ThreadHandle,
		TRUE,
		INFINITE
	);
	printf("\nDone!\n");

	CloseHandle(ghMutex);
	for (int i = 0; i < THREADCOUNT; i++)
		CloseHandle(ThreadHandle[i]);

	for (int i = 0; i < 10; i++) {
		MSD_sum += MSD_freq[i];
		LSD_sum += LSD_freq[i];
	}

	printf("MSD |");
	for (int i = 0; i < 10; i++) {
		printf("%d: %6d(%5.2f%%) |", i, MSD_freq[i], (double)MSD_freq[i] / MSD_sum * 100);
		if (i == 4)
			printf("\n    |");
	}

	printf("\n\nLSD |");
	for (int i = 0; i < 10; i++) {
		printf("%d: %6d(%5.2f%%) |", i, LSD_freq[i], (double)LSD_freq[i] / LSD_sum * 100);
		if (i == 4)
			printf("\n    |");
	}
	printf("\n");

	return 0;
}
