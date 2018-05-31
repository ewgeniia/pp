#include "stdafx.h"
#include "CSmoker.h"


CSmoker::CSmoker(int i, std::shared_ptr<CEvent> smokerFinishedEvent)
{
	m_intVar = i;
	m_materials.resize(m_size);
	std::fill(m_materials.begin(), m_materials.end(), false);
	m_smokerFinishedEvent = smokerFinishedEvent;
}
void CSmoker::SearchAndSmoke()
{
	bool condition = true;
	while (true)
	{
		if (condition)
		{
			std::cout << m_intVar << " smoker is smoking\n";
			m_smokerFinishedEvent->SetUnsignalled();
			Sleep(300);
			condition = false;
		}
		else
		{
			std::cout << m_intVar << " smoker finished\n";
			m_smokerFinishedEvent->SetSignalled();
			Sleep(200);
			condition = true;
		}
	}
}