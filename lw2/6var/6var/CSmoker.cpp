#include "stdafx.h"
#include "CSmoker.h"

extern HANDLE event;
extern std::vector <int> table;

CSmoker::CSmoker(int i)
{
	m_intVar = i;
	m_materials.resize(size);
}
DWORD WINAPI CSmoker::ThreadFunc(LPVOID lpParam)
{
	CSmoker* smoker = (CSmoker*)lpParam;
	std::vector<int> mat  = smoker->m_materials;
	//std::cout <<"beg"<< smoker->m_intVar;
	DWORD dwWaitResult = WaitForSingleObject(event, 1);
	while (dwWaitResult != WAIT_OBJECT_0) 
	{
		if ((table[0] + mat[0] == 1) && (table[1] + mat[1] == 1) && (table[2] + mat[2] == 1))
		{
			std::cout << "Smoker " << smoker->m_intVar << " smoking" << std::endl;
		}
		dwWaitResult = WaitForSingleObject(event, 1);
		//ResetEvent(event);
	}
	//std::cout << "Event Test "<< i << std::endl;
	return 0;
}

void CSmoker::RunThread()
{
	//std::cout << m_intVar;
	HANDLE hThread;
	DWORD idThread;
	// передаем потоковой функции указатель на текущий объект
	hThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ThreadFunc, this, 0, &idThread);
}