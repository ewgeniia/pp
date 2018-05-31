#pragma once
#include "stdafx.h"
#include "CEvent.h"

class CDealer
{
public:
	CDealer(std::shared_ptr<CEvent> smokerFinishedEvent);
	void CheckTable();
private:
	std::vector <bool> PutMaterials();
	std::vector <bool> m_materials;
	std::shared_ptr<CEvent> m_smokerFinishedEvent;
	int m_size = 3;
};