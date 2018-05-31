#include "stdafx.h"
#include "CThread.h"

CThread::CThread(std::function<void()>&& fun)
	: m_fun(fun)
	, m_handle()
{
	m_handle = CreateThread(NULL, SIZE_T(0u), &CThread::Execute, &m_fun, DWORD(0), NULL);
	assert(m_handle != NULL);
}

CThread::~CThread()
{
	BOOL closed = CloseHandle(m_handle);
	assert(closed);
	(void)closed;
}

void CThread::Join()
{
	DWORD state = WaitForSingleObject(m_handle, INFINITE);
	assert(state == WAIT_OBJECT_0);
	(void)state;
}

DWORD WINAPI CThread::Execute(LPVOID data)
{
	auto fun = reinterpret_cast<std::function<void()>*>(data);
	(*fun)();
	return 0;
}