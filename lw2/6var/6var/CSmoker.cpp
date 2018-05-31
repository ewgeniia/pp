#include "stdafx.h"
#include "CSmoker.h"


CSmoker::CSmoker(int i, std::shared_ptr<CEvent> smokerFinishedEvent, std::shared_ptr<CEvent> dealerPutMaterials, CTable& table)
	: m_intVar(i)
	, m_smokerFinishedEvent(smokerFinishedEvent)
	, m_dealerPutMaterials(dealerPutMaterials)
	, m_table(table)
{
	m_materials.resize(m_size);
	std::fill(m_materials.begin(), m_materials.end(), false);
	m_materials[m_intVar] = true;
}

bool CSmoker::CheckMaterialsForSmoke()
{
	for (int i = 0; i < m_size; i++)
	{
		if (!(m_materials[i] || (m_table.GetMaterials())[i]))
		{
			return false;
		}
	}
	return true;
}

void CSmoker::SearchAndSmoke()
{
	while (true)
	{
		m_dealerPutMaterials->WaitUntilSignalled();
		if (!m_table.IsEmpty() && CheckMaterialsForSmoke())
		{
				m_table.ClearTable();
				m_dealerPutMaterials->SetUnsignalled();
				m_smokerFinishedEvent->SetUnsignalled();
				std::cout << m_intVar << " smoker is smoking\n";
				Sleep(500);
				std::cout << m_intVar << " smoker is finished\n";
				m_smokerFinishedEvent->SetSignalled();
		}
	}
}