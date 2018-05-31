#pragma once
#include "stdafx.h"
class CTable
{
public:
	CTable();
	void PutMaterials(std::vector <bool> materials);
	void ClearTable();
	std::vector <bool> GetMaterials();
	bool IsEmpty();
	std::string PrintMaterials();
private:
	std::vector <bool> m_materials;
	std::vector <std::string> m_nameMaterials = { "paper", "tabacco", "matches"};
	int m_size = 3;
};