#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<Windows.h>
#include<tchar.h>

#define PIPE_NAME "\\\\.\\pipe\\_pipe"

double getAvg(int* arr, int count);
double getMid(int* arr, int count);
void sortAsc(int* arr, int count);

int _tmain(int argc, TCHAR* argv[])
{
	TCHAR pipe_name[] =_T(PIPE_NAME);
	HANDLE hNamePipe;

	printf("== Child Process == \n");

	hNamePipe = CreateFile(pipe_name, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);
	
	if (hNamePipe == INVALID_HANDLE_VALUE) {
		_tprintf(_T("Create File Failed \n"));
		//return -1;
	}

	DWORD pipeMode = PIPE_READMODE_MESSAGE | PIPE_WAIT;

	//생성한 Named Pipe의 핸들을 부모 프로세스와 연결
	ConnectNamedPipe(hNamePipe, NULL);

	// 자연수의 갯수(n)을 받는다
	TCHAR countBuf[5];
	DWORD countSize;

	if (!ReadFile(hNamePipe,
		countBuf,
		sizeof(countBuf)-sizeof(TCHAR),
		&countSize,
		NULL)) {
		_tprintf(_T("Read File Failed - countBuf \n"));
		CloseHandle(hNamePipe);
		return -1;
	}
	countBuf[countSize / sizeof(TCHAR) - 1] = _T('\x00');

	int count = _ttoi(countBuf);

	// n개의 자연수를 받는다
	TCHAR numBuf[10];
	DWORD numSize;

	int* numArray = malloc(sizeof(int) * (count));
	if (numArray) {
		for (int i = 0; i < count; i++) {
			if (!ReadFile(hNamePipe,
				numBuf,
				sizeof(numBuf) - sizeof(TCHAR),
				&numSize,
				NULL)) {
				_tprintf(_T("Read File Failed - numBuf \n"));
				CloseHandle(hNamePipe);
				return -1;
			}
			numBuf[numSize / sizeof(TCHAR) - 1] = _T('\x00');

			numArray[i] = _ttoi(numBuf);
		}
	}

	// 평균과 중앙값 계산
	double avg, mid;
	avg = getAvg(numArray, count);
	mid = getMid(numArray, count);

	// 평균값을 부모 프로세스에 전달
	TCHAR avgBuf[100];
	DWORD avgSize;
	_stprintf_s(avgBuf, _countof(avgBuf), _T("%f"), avg);

	if (!WriteFile(hNamePipe,
		avgBuf,
		(_tcslen(avgBuf) + 1) * sizeof(TCHAR),
		&avgSize,
		NULL)) {
		_tprintf(_T("Wirte File Failed - avgBuf \n"));
		CloseHandle(hNamePipe);
		return -1;
	}
	FlushFileBuffers(hNamePipe);

	// 중앙값을 부모 프로세스에 전달
	TCHAR midBuf[100];
	DWORD midSize;
	_stprintf_s(midBuf, _countof(midBuf), _T("%f"), mid);

	if (!WriteFile(hNamePipe,
		midBuf,
		(_tcslen(midBuf) + 1) * sizeof(TCHAR),
		&midSize,
		NULL)) {
		_tprintf(_T("Wirte File Failed - midBuf \n"));
		CloseHandle(hNamePipe);
		return -1;
	}
	FlushFileBuffers(hNamePipe);

	free(numArray);
	CloseHandle(hNamePipe);

	return 0;
}

double getAvg(int* arr, int count)
{
	int sum = 0;
	for (int i = 0; i < count; i++)
		sum += arr[i];

	return (double)sum / (double)count;
}

double getMid(int* arr, int count)
{
	sortAsc(arr, count);
	if (count % 2 == 1)
		return arr[(count - 1) / 2];
	else
		return (arr[count / 2] + arr[(count / 2) - 1]) / 2.0;
}

void sortAsc(int* arr, int count)
{
	int temp;
	for (int i = 0; i < count; i++) {
		for (int j = 0; j < count - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}