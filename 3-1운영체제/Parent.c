#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<tchar.h>
#include<math.h>
#include<Windows.h>

#define PIPE_NAME "\\\\.\\pipe\\_pipe"
#define MAX_NUM 100

double getStdDev(int* arr, double avg, int count);
int getNumberK(double mid, double avg, double SD);

int _tmain(int argc, TCHAR* argv[])
{
	HANDLE hNamePipe;
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	DWORD countSize;
	DWORD numSize;
	TCHAR pipe_name[] = _T(PIPE_NAME);

	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));

	// 지명 파이프 생성
	hNamePipe = CreateNamedPipe(pipe_name,
		PIPE_ACCESS_DUPLEX,
		PIPE_TYPE_MESSAGE | PIPE_READMODE_MESSAGE | PIPE_WAIT,
		PIPE_UNLIMITED_INSTANCES,
		0,
		0,
		20000,
		NULL);

	if (hNamePipe == INVALID_HANDLE_VALUE) {
		_tprintf(_T("Create Named Pipe Failed\n"));
		return -1;
	}

	// 자식 프로세스 생성
	TCHAR CommandLine[] = _T("C:\\Users\\yang\\Desktop\\OS_HW2\\OS-HW2-C.exe");

	if (CreateProcess(NULL, CommandLine, NULL, NULL, TRUE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi)) {
		_tprintf(_T("Creation Success \n"));

		// 메모리 누수 방지를 위해 닫아줌
		CloseHandle(pi.hThread);
		CloseHandle(pi.hProcess);
	}
	else {
		_tprintf(_T("Creation Failed \n"));
		return -1;
	}

	// 자연수 배열 받기
	int num, count = 0;
	int array[MAX_NUM];

	printf("숫자 입력: ");
	while (1) {
		scanf_s("%d", &num);
		if (num >= 0) {
			array[count] = num;
			count++;
		}
		else {
			break;
		}
	}

	int* numArray = malloc(sizeof(int) * (count));
	for (int i = 0; i < count; i++) {
		numArray[i] = array[i];
	}

	// 자연수의 갯수(n)을 보낸다
	TCHAR countBuf[5];
	_stprintf_s(countBuf, _countof(countBuf), _T("%d"), count); // int형인 count를 TCHAR형으로 변환

	if (!WriteFile(hNamePipe,
		countBuf,
		(_tcslen(countBuf) + 1) * sizeof(TCHAR),
		&countSize,
		NULL)) {
		_tprintf(_T("Write File Failed - countBuf\n"));
		return -1;
	}
	FlushFileBuffers(hNamePipe);

	// n개의 자연수를 보낸다
	TCHAR numBuf[10];
	
	for (int i = 0; i < count; i++) {
		_stprintf_s(numBuf, _countof(numBuf), _T("%d"), numArray[i]);

		if (!WriteFile(hNamePipe,
			numBuf,
			(_tcslen(numBuf) + 1) * sizeof(TCHAR),
			&numSize,
			NULL)) {
			_tprintf(_T("Write File Failed - numBuf\n"));
			return -1;
		}
		FlushFileBuffers(hNamePipe);
	}
	_tprintf(_T("Write Success \n"));

	// 평균을 받는다
	TCHAR avgBuf[100];
	DWORD avgSize;
	LPTSTR avgEndPtr;

	if (!ReadFile(hNamePipe,
		avgBuf,
		sizeof(avgBuf) - sizeof(TCHAR),
		&avgSize,
		NULL)) {
		_tprintf(_T("Read File Failed - avgBuf \n"));
		return -1;
	}

	// 중앙값을 받는다
	TCHAR midBuf[100];
	DWORD midSize;
	LPTSTR midEndPtr;

	if (!ReadFile(hNamePipe,
		midBuf,
		sizeof(midBuf) - sizeof(TCHAR),
		&midSize,
		NULL)) {
		_tprintf(_T("Read File Failed - midBuf \n"));
		return -1;
	}
	_tprintf(_T("Read Success \n"));

	avgBuf[avgSize / sizeof(TCHAR) - 1] = _T('\x00');
	midBuf[midSize / sizeof(TCHAR) - 1] = _T('\x00');

	double avg = _tcstod(avgBuf, &avgEndPtr);
	double mid = _tcstod(midBuf, &midEndPtr);
	_tprintf(_T("Avg: %lf | Mid: %lf \n"), avg, mid);

	// 표준편차를 계산하고 식을 만족하는 k를 찾아 출력
	double StdDev = getStdDev(numArray, avg, count);
	if (StdDev == 0) {
		printf("Standard Deviation is zero. Cannot be divided by zero!! \n");
		return -1;
	}
	int NumberK = getNumberK(mid, avg, StdDev);
	printf("StdDev: %lf\n", StdDev);

	printf("최소의 자연수 k: %d \n", NumberK);

	DisconnectNamedPipe(hNamePipe);
	free(numArray);
	_tprintf(_T("Program exit \n"));

	return 0;
}

double getStdDev(int* arr, double avg, int count)
{
	double sum = 0;
	double SD;

	for (int i = 0; i < count; i++)
		sum += pow(arr[i] - avg, 2);

	SD = sqrt(sum / count);

	return SD;
}

int getNumberK(double mid, double avg, double SD)
{
	int i = 1;
	double N = fabs(mid - avg) / SD;

	while (1) {
		if (N <= i)
			return i;
		else
			i++;
	}
}