#include <Windows.h>

#include "Clock.h"

long Clock::getCurrentTime()
{
	SYSTEMTIME time;
	GetSystemTime(&time);

	long time_msec =
		(time.wMinute * 60 * 1000000) + 
		(time.wSecond * 1000000) + 
		(time.wMilliseconds * 1000);
				
	return time_msec;
}

Clock::Clock()
{
	m_prevTime = getCurrentTime();
}

long Clock::delta()
{
	long currTime = getCurrentTime();
	long elapsedTime = currTime - m_prevTime;
	m_prevTime = currTime;
	return elapsedTime;
}

long Clock::split()
{
	long currTime = getCurrentTime();
	long elapsedTime = currTime - m_prevTime;
	return elapsedTime;
}
