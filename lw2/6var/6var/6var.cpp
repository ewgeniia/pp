// 6var.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "CSmoker.h"
#include <algorithm>
#include <iterator>
#include "CDealer.h"
#include "CThread.h"

using namespace std;

namespace
{
	int NUMBER_OF_SMOKERS = 3;
}

void main()
{
	auto smokerFinishedSmoking = std::make_shared<CEvent>(true);
	auto dealerPutMaterials = std::make_shared<CEvent>(false);
	std::vector<std::unique_ptr<CSmoker>> smokers;
	smokers.reserve(NUMBER_OF_SMOKERS);
	CTable table;
	for (int i = 0; i < NUMBER_OF_SMOKERS; i++)
	{
		smokers.push_back(std::make_unique<CSmoker>(i, smokerFinishedSmoking, dealerPutMaterials, table));
	}
	CDealer dealer(smokerFinishedSmoking, dealerPutMaterials, table);
	std::vector<std::unique_ptr<CThread>> threads;
	for (auto& smoker : smokers)
	{
		threads.push_back(std::make_unique<CThread>(std::move([&smoker]() { smoker->SearchAndSmoke(); })));
	}
	threads.push_back(std::make_unique<CThread>(std::move([&dealer]() { dealer.CheckTable(); })));
	for (auto& thread : threads)
	{
		thread->Join();
	}
}