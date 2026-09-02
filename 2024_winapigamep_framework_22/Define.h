#pragma once
// 매크로

#define DECLARE_SINGLE(type)	 \
private:						\
	type() {}					\
public:							\
	static type* GetInst()	\
	{							\
		static type m_pInst;	\
		return &m_pInst;		\
	}							\

#define GET_SINGLE(type) type::GetInst()
#define fDT GET_SINGLE(TimeManager)->GetDT()
#define fUNSCALEDDT GET_SINGLE(TimeManager)->GetUnscaledDT()
#define TIME GET_SINGLE(TimeManager)->time
#define UNSCALEDTIME GET_SINGLE(TimeManager)->GetUnscaledTime()
#define TIMESCALE GET_SINGLE(TimeManager)->timeScale
#define Deg2Rad (PI * 2) / 360
#define Rad2Deg 360 / (PI * 2)

#define LOADTEXTURE(key, path) GET_SINGLE(ResourceManager)->TextureLoad(key, path)
#define PLAY(key) GET_SINGLE(ResourceManager)->Play(key)
#define LOADSOUND(key, path, channel) GET_SINGLE(ResourceManager)->LoadSound(key, path, channel)

#define ADDXP(value) GET_SINGLE(XPManager)->AddXP(value)
#define ADDOBJECT(object, layer) GET_SINGLE(SceneManager)->GetCurrentScene()->AddObject(object, layer);

#define POP(name, pos) GET_SINGLE(PoolManager)->Pop(name, pos)
#define PUSH(name, poolableObject) GET_SINGLE(PoolManager)->Push(name, poolableObject)

#define FINDOBJECT(name, layer) GET_SINGLE(SceneManager)->FindObject(name, layer)

#define KEY_CHECK(key, state) InputManager::GetInst()->GetKey(key) == state
#define GET_KEYNONE(key) KEY_CHECK(key, KEY_STATE::NONE)
#define GET_KEYUP(key) KEY_CHECK(key, KEY_STATE::UP)
#define GET_KEYDOWN(key) KEY_CHECK(key, KEY_STATE::DOWN)
#define GET_KEY(key) KEY_CHECK(key, KEY_STATE::PRESS)
#define GET_MOUSEPOS GET_SINGLE(InputManager)->GetMousePos()
// Render 매크로
#define RECT_RENDER(hdc, posx, posy, sizex, sizey) Rectangle(hdc, (int)(posx-sizex/2), (int)(posy-sizey/2), (int)(posx+sizex/2), (int)(posy+sizey/2))
#define ELLIPSE_RENDER(hdc, posx, posy, sizex, sizey) Ellipse(hdc, (int)(posx-sizex/2), (int)(posy-sizey/2), (int)(posx+sizex/2), (int)(posy+sizey/2))
#define RECT_MAKE(posx, posy, sizex, sizey) {posx-sizex/2, posy-sizey/2, posx+sizex/2, posy+sizey/2}
