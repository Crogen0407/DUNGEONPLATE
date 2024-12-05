#pragma once
class TimeManager
{
	DECLARE_SINGLE(TimeManager);
public:
	void Init();
	void Update();
public:
	const float& GetDT() const { return m_dT; }
	const float& GetUnscaledDT() const { return m_unscaledDT; }
	const float& GetUnscaledTime() const { return m_unscaledTime; }
public:
	float time = 0.f;
	float timeScale = 1.f;
private:
	// Delta time
	LARGE_INTEGER m_llPrevCnt = {};
	LARGE_INTEGER m_llCurCnt = {};
	LARGE_INTEGER m_llFrequency = {};
	float		  m_dT = 0.f;
	float		  m_unscaledDT = 0.f;
	float		  m_unscaledTime = 0.f;

	// FPS(Frame Per Second)
	UINT		  m_fps = 0;
	UINT		  m_framecnt = 0;
	float		  m_frametime = 0.f;
};

