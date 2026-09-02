#include "pch.h"
#include "TimeManager.h"
#include "Core.h"
#include "InputManager.h"
void TimeManager::Init()
{
	// 카운트를 측정해서 가져온다.
	::QueryPerformanceCounter(&m_llPrevCnt);
	
	// 초당 카운트 횟수(1초당 1000만) 반환
	::QueryPerformanceFrequency(&m_llFrequency);
}

void TimeManager::Update()
{
	::QueryPerformanceCounter(&m_llCurCnt);
	
	// deltatime(변화시간) : 한 프레임에 걸린 시간 
	m_unscaledDT = (float)(m_llCurCnt.QuadPart - m_llPrevCnt.QuadPart)
		/ (float)m_llFrequency.QuadPart;

	m_dT = m_unscaledDT * timeScale;

	m_llPrevCnt = m_llCurCnt;

	// FPS(Frame Per Second): 1초당 몇 프레임 가냐.
	m_framecnt++; // 프레임 체크 횟수를 모아
	m_frametime += m_dT; // 실제시간을 모아
	if (m_frametime >= 1.f) // 1초
	{
		m_fps = (UINT)(m_framecnt / m_frametime);
		m_frametime = 0.f;
		m_framecnt = 0;
	}

	time += m_dT;
	m_unscaledTime += m_unscaledDT;
}
