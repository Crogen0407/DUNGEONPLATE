#include "pch.h"
#include "Core.h"
#include "TimeManager.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "ResourceManager.h"
#include "CollisionManager.h"
#include "EventManager.h"
bool Core::Init(HWND _hwnd)
{
	// 변수 초기화
	m_hWnd = _hwnd;
	m_hDC = ::GetDC(m_hWnd);
	m_hBackDC = 0;
	m_hBackBit = 0;

	// 더블 버퍼링
	// 1. 생성(세팅)
	m_hBackBit = ::CreateCompatibleBitmap(m_hDC, SCREEN_WIDTH, SCREEN_HEIGHT);
	m_hBackDC =::CreateCompatibleDC(m_hDC);

	// 2. 연결
	::SelectObject(m_hBackDC,m_hBackBit);
	
	CreateGDI();
	// === Manager Init === 
	GET_SINGLE(TimeManager)->Init();
	GET_SINGLE(InputManager)->Init();
	GET_SINGLE(ResourceManager)->Init();
	GET_SINGLE(SceneManager)->Init();

	//m_obj.SetPos(Vec2(SCREEN_WIDTH / 2
	//				,SCREEN_HEIGHT/ 2));
	//m_obj.SetSize(Vec2(100, 100));
	return true;
}
void Core::CleanUp()
{
	// 생성한순서 반대로 삭제
	::DeleteDC(m_hBackDC);	//createdc한거
	::DeleteObject(m_hBackBit); // createbitmap 한거
	::ReleaseDC(m_hWnd, m_hDC);
	for (int i = 0; i < (UINT)PEN_TYPE::END; ++i)
	{
		DeleteObject(m_colorPens[i]);
	}
	for (int i = 1; i < (UINT)BRUSH_TYPE::END; ++i)
	{
		// Hollow 제외하고
		DeleteObject(m_colorBrushs[i]);
	}

	GET_SINGLE(ResourceManager)->Release();
}

void Core::GameLoop()
{
	//static int callcount = 0;
	//++callcount;
	//static int prev = GetTickCount64();
	//int cur = GetTickCount64();
	//if (cur - prev > 1000)
	//{
	//	prev = cur;
	//	callcount = 0;
	//}
	MainUpdate();
	MainRender();
	GET_SINGLE(EventManager)->Update();
}



void Core::MainUpdate()
{
	// === Manager Update === 
	GET_SINGLE(TimeManager)->Update();
	GET_SINGLE(InputManager)->Update();
	GET_SINGLE(SceneManager)->Update();
	GET_SINGLE(CollisionManager)->Update();

}

void Core::MainRender()
{
	// 1. clear
	::PatBlt(m_hBackDC, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, WHITENESS);
	// 2. Render
	GET_SINGLE(SceneManager)->Render(m_hBackDC);
	// 3. display	
	::BitBlt(m_hDC, 0,0, SCREEN_WIDTH,SCREEN_HEIGHT,
			m_hBackDC,0,0, SRCCOPY);

 //	::TransparentBlt();
	//::StretchBlt();
	//::PlgBlt();
	//::AlphaBlend();
 }
void Core::CreateGDI()
{
	// HOLLOW
	m_colorBrushs[(UINT)BRUSH_TYPE::HOLLOW] = (HBRUSH)GetStockObject(HOLLOW_BRUSH);
	m_colorBrushs[(UINT)BRUSH_TYPE::RED] = (HBRUSH)CreateSolidBrush(RGB(255, 167, 167));
	m_colorBrushs[(UINT)BRUSH_TYPE::GREEN] = (HBRUSH)CreateSolidBrush(RGB(134, 229, 134));
	m_colorBrushs[(UINT)BRUSH_TYPE::BLUE] = (HBRUSH)CreateSolidBrush(RGB(103, 153, 255));
	m_colorBrushs[(UINT)BRUSH_TYPE::YELLOW] = (HBRUSH)CreateSolidBrush(RGB(255, 187, 0));

	//RED GREEN BLUE PEN
	m_colorPens[(UINT)PEN_TYPE::RED] = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	m_colorPens[(UINT)PEN_TYPE::GREEN] = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
	m_colorPens[(UINT)PEN_TYPE::BLUE] = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
	m_colorPens[(UINT)PEN_TYPE::YELLOW] = CreatePen(PS_SOLID, 1, RGB(255, 255, 0));
	m_colorPens[(UINT)PEN_TYPE::HOLLOW] = CreatePen(PS_NULL, 0, RGB(0, 0, 0));
}
