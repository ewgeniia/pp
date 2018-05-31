#include "stdafx.h"
#include "CTable.h"

CTable::CTable()
{
	m_materials.resize(m_size);
	ClearTable();
}

void CTable::PutMaterials(std::vector <bool> materials)
{
	m_materials = materials;
}

void CTable::ClearTable()
{
	std::fill(m_materials.begin(), m_materials.end(), false);
}

std::vector <bool> CTable::GetMaterials()
{
	return m_materials;
}

bool CTable::IsEmpty() 
{
	for (auto mat : m_materials)
	{
		if (mat == true)
		{
			return false;
		}
	}
	return true;
}

std::string CTable::PrintMaterials()
{
	std::string result;
	for (int i = 0; i < m_size; i++)
	{
		if (m_materials[i])
		{
			result += m_nameMaterials[i] + " ";
		}
	}
	result.replace(result.find(" "), 1, " and ");
	return result;
}