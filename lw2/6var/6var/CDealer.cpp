#include "stdafx.h"
#include "CDealer.h"

CDealer::CDealer(std::shared_ptr<CEvent> smokerFinishedEvent, std::shared_ptr<CEvent> dealerPutMaterials, CTable& table)
	:m_smokerFinishedEvent(smokerFinishedEvent)
	, m_dealerPutMaterials(dealerPutMaterials)
	, m_table(table)
{
	m_materials.resize(m_size);
}
std::vector <bool> CDealer::GetMaterials()
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
		if (m_table.IsEmpty())
		{
			m_table.PutMaterials(GetMaterials());
			std::cout << "Dealer put " << m_table.PrintMaterials() << "\n";
			m_dealerPutMaterials->SetSignalled();
			m_smokerFinishedEvent->SetUnsignalled();
		}
	}
}
