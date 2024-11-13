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
	const POINT& GetMousePos() const { return m_ptMouse; }
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
};

