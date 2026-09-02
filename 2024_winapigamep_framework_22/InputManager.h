#pragma once
enum class KEY_TYPE
{
	LEFT, RIGHT, UP, DOWN,
	Q, W, E, R, T, Y, U, I, O, P,
	A, S, D, F, G, H, J, K, L,
	Z, X, C, V, B, N, M,
	CTRL, LALT, LSHIFT, SPACE,
	ENTER, TAB, ESC, LBUTTON, RBUTTON,
	NUM_1, NUM_2, LAST
	// LAST의미: 끝이라는 뜻이야
};
enum class KEY_STATE
{					// HOLD
	NONE, DOWN, UP, PRESS, END
};
struct tKeyInfo
{
	KEY_STATE eState;
	bool IsPrevCheck;
};

class InputManager
{
	DECLARE_SINGLE(InputManager);
public:
	void Init();
	void Update();
	const KEY_STATE& GetKey(KEY_TYPE _eKey) const
	{
		return m_vecKey[(int)_eKey].eState;
	}

	const Vec2 GetMousePos() const
	{
		// 1. 마우스가 실제 게임 화면(뷰포트) 내부에 있는지 확인
		if (m_ptMouse.x >= m_viewportOffsetX &&
			m_ptMouse.x < m_viewportOffsetX + m_viewportWidth &&
			m_ptMouse.y >= m_viewportOffsetY &&
			m_ptMouse.y < m_viewportOffsetY + m_viewportHeight)
		{
			// 2. 뷰포트 내 상대 좌표 (0.0 ~ 1.0) 계산 (정규화)
			float normalizedX = static_cast<float>(m_ptMouse.x - m_viewportOffsetX) / m_viewportWidth;
			float normalizedY = static_cast<float>(m_ptMouse.y - m_viewportOffsetY) / m_viewportHeight;

			// 3. 논리적 해상도 기준으로 스케일링
			float logicalX = normalizedX * SCREEN_WIDTH;
			float logicalY = normalizedY * SCREEN_HEIGHT;

			// 부동소수점 오차로 인한 범위 이탈 방지 (Clamp)
			logicalX = max(0.0f, min(logicalX, static_cast<float>(SCREEN_WIDTH - 1)));
			logicalY = max(0.0f, min(logicalY, static_cast<float>(SCREEN_HEIGHT - 1)));

			return Vec2(logicalX, logicalY);
		}

		// 마우스가 화면 여백(검은색 영역)에 있는 경우
		// 게임 로직에서 "마우스가 화면 밖으로 나감"으로 처리할 수 있도록 (-1, -1) 반환
		return Vec2(-1.0f, -1.0f);
	}

	void SetViewportInfo(int width, int height, int offsetX, int offsetY)
	{
		m_viewportWidth = width;
		m_viewportHeight = height;
		m_viewportOffsetX = offsetX;
		m_viewportOffsetY = offsetY;
	}

private:
	POINT			 m_ptMouse = {};
	vector<tKeyInfo> m_vecKey;
	int				 m_arrVKKey[(int)KEY_TYPE::LAST] =
	{ VK_LEFT, VK_RIGHT, VK_UP, VK_DOWN, 'Q','W','E','R',
	'T','Y','U','I','O','P',
	'A','S','D','F','G','H','J','K','L',
	'Z','X','C','V','B','N','M',
	VK_CONTROL, VK_LMENU, VK_LSHIFT, VK_SPACE,
		VK_RETURN, VK_TAB, VK_ESCAPE,
		VK_LBUTTON, VK_RBUTTON,'1','2' };

private:
	int m_viewportWidth = SCREEN_WIDTH;
	int m_viewportHeight = SCREEN_HEIGHT;
	int m_viewportOffsetX = 0;
	int m_viewportOffsetY = 0;
};

