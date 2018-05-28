#include "stdafx.h"
#include "CDealer.h"

extern HANDLE event;
extern std::vector <int> table;

CDealer::CDealer()
{
	materials.resize(size);
}
std::vector <int> CDealer::GetMaterials()
{
	int missingMaterial = rand() % 3;
	for (int i = 0; i < 3; i++)
	{
		if (i == missingMaterial)
		{
			materials[i] = 0;
		}
		else
		{
			materials[i] = 1;
		}
	}
	return materials;
}
DWORD WINAPI CDealer::ThreadFunc(LPVOID lpParam)
{

	CDealer* dealer = (CDealer*)lpParam;
	//cout << smoker->materials.size();
	DWORD dwWaitResult = WaitForSingleObject(event, 1);
	while (dwWaitResult != WAIT_OBJECT_0)
	{
		table = dealer->GetMaterials();
		std::cout << "Test dealer" << std::endl;
		dwWaitResult = WaitForSingleObject(event, 1);
		//SetEvent(event);
	}
	//std::copy(mat.begin(), mat.end(), std::ostream_iterator<int>(std::cout, " "));
	return 0;
}

void CDealer::RunThread()
{
	HANDLE hThread;
	DWORD idThread;
	// передаем потоковой функции указатель на текущий объект
	hThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ThreadFunc, this, 0, &idThread);
}