#pragma once
#include <Windows.h>

class CEvent
{
public:
	CEvent(bool signalled);
	~CEvent();

	void SetSignalled();
	void SetUnsignalled();
	void WaitUntilSignalled();

private:
	HANDLE m_handle;
};