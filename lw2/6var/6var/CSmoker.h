#pragma once
#include "stdafx.h"
#include "CEvent.h"
#include "CTable.h"

class CSmoker
{
public:
	CSmoker(int i, std::shared_ptr<CEvent> smokerFinishedEvent, std::shared_ptr<CEvent> dealerPutMaterials, CTable& table);
	void SearchAndSmoke();
private:
	CTable& m_table;
	std::vector<bool> m_materials;
	bool CheckMaterialsForSmoke();
	int m_intVar;
	int m_size = 3;
	std::shared_ptr<CEvent> m_smokerFinishedEvent;
	std::shared_ptr<CEvent> m_dealerPutMaterials;
};