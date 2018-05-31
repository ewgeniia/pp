#include "stdafx.h"
#include "CDealer.h"

CDealer::CDealer(std::shared_ptr<CEvent> smokerFinishedEvent)
{
	m_smokerFinishedEvent = smokerFinishedEvent;
	m_materials.resize(m_size);
}
std::vector <bool> CDealer::PutMaterials()
{
	int missingMaterial = rand() % 3;
	for (int i = 0; i < 3; i++)
	{
		if (i == missingMaterial)
		{
			m_materials[i] = false;
		}
		else
		{
			m_materials[i] = true;
		}
	}
	return m_materials;
}

void CDealer::CheckTable()
{
	while (true)
	{
		m_smokerFinishedEvent->WaitUntilSignalled();
		m_materials = PutMaterials();
		std::cout << "Dealer put materials\n";
	}
}
