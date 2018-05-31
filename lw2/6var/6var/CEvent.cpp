#include "stdafx.h"
#include "CEvent.h"

CEvent::CEvent(bool signalled)
{
	m_handle = CreateEvent(
		NULL,
		TRUE,
		BOOL(signalled),
		NULL
		);
	assert(m_handle != NULL);
}

CEvent::~CEvent()
{
	BOOL closed = CloseHandle(m_handle);
	assert(closed);
	(void)closed;
}

void CEvent::SetSignalled()
{
	BOOL status = SetEvent(m_handle);
	assert(status);
	(void)status;
}

void CEvent::SetUnsignalled()
{
	BOOL status = ResetEvent(m_handle);
	assert(status);
	(void)status;
}

void CEvent::WaitUntilSignalled()
{
	DWORD status = WaitForSingleObject(m_handle, INFINITE);
	assert(status == WAIT_OBJECT_0);
	(void)status;
}