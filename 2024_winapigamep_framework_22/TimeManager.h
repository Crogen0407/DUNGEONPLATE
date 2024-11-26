#pragma once
class TimeManager
{
	DECLARE_SINGLE(TimeManager);
public:
	void Init();
	void Update();
public:
	const float& GetDT() const { return m_dT; }
	const float& GetTime() const { return m_time; }
public:
	float timeScale = 1.f;
private:
	// Delta time
	LARGE_INTEGER m_llPrevCnt = {};
	LARGE_INTEGER m_llCurCnt = {};
	LARGE_INTEGER m_llFrequency = {};
	float		  m_dT = 0.f;
	float		  m_time = 0.f;

	// FPS(Frame Per Second)
	UINT		  m_fps = 0;
	UINT		  m_framecnt = 0;
	float		  m_frametime = 0.f;
};

