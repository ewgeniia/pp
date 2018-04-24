#pragma once
#include "stdafx.h"

class CSmoker
{
public:
	CSmoker(int i);
	void RunThread();
private:
	static DWORD WINAPI ThreadFunc(LPVOID lpParam);
	int m_intVar;
};
