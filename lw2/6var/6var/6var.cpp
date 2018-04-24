// 6var.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "process.h" 
#include "CSmoker.h"
#include <vector>

using namespace std;

HANDLE event;

void main()
{
	event = CreateEvent(NULL, TRUE, FALSE, TEXT("FirstStep"));
	/*vector <CSmoker> smokers;
	for (int i = 0; i < 5; i++)
	{
		smokers.push_back(CSmoker(i));
		cout << i;
		smokers[i].RunThread();
	}*/
	CSmoker smoker1(1);
	CSmoker smoker2(2);
	CSmoker smoker3(3);
	smoker1.RunThread();
	smoker2.RunThread();
	smoker3.RunThread();
	if (event != NULL) {
		Sleep(1000);
		SetEvent(event);
		Sleep(1000);
		ResetEvent(event);
		CloseHandle(event);
	}
	else {
		cout << "error create event" << endl;
	}

}

