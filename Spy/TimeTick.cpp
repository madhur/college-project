// TimeTick.cpp : implementation of the CTimeTick class
//
/////////////////////////////////////////////////////////////////////////////
//
//
/////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TimeTick.h"

//////////////////////////////////////////////////////////////////////
// CTimeTick

__int64 CTimeTick::m_nPerformanceFrequency = CTimeTick::GetPerformanceFrequency();

CTimeTick::CTimeTick()
{
	m_nTimeElapsed.QuadPart = 0;
	m_nTime.QuadPart 	    = 0;
}

CTimeTick::~CTimeTick()
{
}

void CTimeTick::Start()
{	
	VERIFY(QueryPerformanceCounter(&m_nTimeElapsed));
	m_nTime.QuadPart = 0;
}

float CTimeTick::Tick()
{
	LARGE_INTEGER nTime;

	VERIFY(QueryPerformanceCounter(&nTime));

	float nTickTime		= GetTimeInSeconds(nTime.QuadPart - m_nTimeElapsed.QuadPart);
	m_nTimeElapsed.QuadPart = nTime.QuadPart;

	return nTickTime;
}

__int64 CTimeTick::GetPerformanceFrequency()
{
	LARGE_INTEGER nPerformanceFrequency;

	VERIFY(QueryPerformanceFrequency(&nPerformanceFrequency));

	return nPerformanceFrequency.QuadPart;
}

float CTimeTick::GetTimeInSeconds(__int64 nTime)
{
	return float(nTime) / m_nPerformanceFrequency;
}