// 6var.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "CSmoker.h"
#include <algorithm>
#include <iterator>
#include "CDealer.h"

using namespace std;

HANDLE event;
vector <int> table;


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
	CSmoker smoker1(0);
	CSmoker smoker2(1);
	CSmoker smoker3(2);
	smoker1.RunThread();
	smoker2.RunThread();
	smoker3.RunThread();
	CDealer dealer;
	dealer.RunThread();
	table.resize(3);
	if (event != NULL) 
	{
		while (true)
		{
			SetEvent(event);
			Sleep(1000);
			std::copy(table.begin(), table.end(), std::ostream_iterator<int>(std::cout, " "));
			ResetEvent(event);
			Sleep(1000);
		}
		CloseHandle(event);
	}
	else {
		cout << "error create event" << endl;
	}

}

