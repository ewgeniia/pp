#pragma once
#include "stdafx.h"
#include "CEvent.h"

class CSmoker
{
public:
	CSmoker(int i, std::shared_ptr<CEvent> smokerFinishedEvent);
	void SearchAndSmoke();
private:
	std::vector<bool> m_materials;
	int m_intVar;
	int m_size = 3;
	std::shared_ptr<CEvent> m_smokerFinishedEvent;
};