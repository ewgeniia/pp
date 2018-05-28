#pragma once
#include "stdafx.h"

class CSmoker
{
public:
	CSmoker(int i);
	void RunThread();
private:
	static DWORD WINAPI ThreadFunc(LPVOID lpParam);
	std::vector<int> m_materials;
	int m_intVar;
	int size = 3;
};
