#pragma once
#include "stdafx.h"
#include "CEvent.h"
#include "CTable.h"

class CDealer
{
public:
	CDealer(std::shared_ptr<CEvent> smokerFinishedEvent, std::shared_ptr<CEvent> dealerPutMaterials, CTable& table);
	void CheckTable();
private:
	CTable& m_table;
	std::vector <bool> GetMaterials();
	std::vector <bool> m_materials;
	std::shared_ptr<CEvent> m_smokerFinishedEvent;
	std::shared_ptr<CEvent> m_dealerPutMaterials;
	int m_size = 3;
};