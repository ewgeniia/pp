#pragma once
#pragma once
#include <Windows.h>
#include <functional>
#include <boost/noncopyable.hpp>

class CThread : private boost::noncopyable
{
public:
	using Function = std::function<void()>;

	CThread(Function&& fn);
	~CThread();
	void Join();

private:
	static DWORD WINAPI Execute(LPVOID data);
	std::function<void()> m_fun;
	HANDLE m_handle;
};