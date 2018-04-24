#include "stdafx.h"
#include "CSmoker.h"

extern HANDLE event;


CSmoker::CSmoker(int i)
{
	m_intVar = i;
}
DWORD WINAPI CSmoker::ThreadFunc(LPVOID lpParam)
{
	CSmoker* smoker = (CSmoker*)lpParam;
	int i = smoker->m_intVar;
	//std::cout <<"beg"<< smoker->m_intVar;
	DWORD dwWaitResult = WaitForSingleObject(event, 1);
	while (dwWaitResult != WAIT_OBJECT_0) {
		dwWaitResult = WaitForSingleObject(event, 1);
		//std::cout << "Test " << smoker->m_intVar << std::endl;
	}
	std::cout << "Event Test "<< i << std::endl;
	return 0;
}

void CSmoker::RunThread()
{
	std::cout << m_intVar;
	HANDLE hThread;
	DWORD idThread;
	// передаем потоковой функции указатель на текущий объект
	hThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ThreadFunc, this, 0, &idThread);
}