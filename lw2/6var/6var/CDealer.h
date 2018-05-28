#pragma once
#include "stdafx.h"

class CDealer
{
public:
	void RunThread();
	CDealer();
	std::vector <int> GetMaterials();
private:
	static DWORD WINAPI ThreadFunc(LPVOID lpParam);
	std::vector <int> materials;
	int size = 3;
};