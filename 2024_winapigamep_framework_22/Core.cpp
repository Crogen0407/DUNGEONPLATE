#include "pch.h"
#include "Core.h"
#include "TimeManager.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "ResourceManager.h"
#include "CollisionManager.h"
#include "EventManager.h"
#include "SkillManager.h"
#include "FadeManager.h"
#include "GameManager.h"

bool Core::Init(HWND _hwnd)
{
	cout << "ÁÖ´¨½Ü »ç¶ûÇØ¿ä¢½" << endl;
	_hWnd = _hwnd;
	
	// Direct2D ·»´õ
	{
		::D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, _factory.GetAddressOf());

		// ·»´õ Å¸°Ù ¼Ó¼º ¼³Á¤
		D2D1_RENDER_TARGET_PROPERTIES rtProps = D2D1::RenderTargetProperties(
			D2D1_RENDER_TARGET_TYPE_DEFAULT,
			D2D1::PixelFormat(DXGI_FORMAT_B8G8R8A8_UNORM, D2D1_ALPHA_MODE_IGNORE),
			0, 0
		);

		// Ã¢ ÇÚµéÀ» °¡Á®¿Í¼­ ¿¬°á
		D2D1_HWND_RENDER_TARGET_PROPERTIES hwndRTProps = D2D1::HwndRenderTargetProperties(
			_hWnd, D2D1::SizeU(SCREEN_WIDTH, SCREEN_HEIGHT), D2D1_PRESENT_OPTIONS_IMMEDIATELY
		);

		_factory->CreateHwndRenderTarget(&rtProps, &hwndRTProps, _renderTarget.GetAddressOf());

		// AA Àû¿ë
		_renderTarget->SetAntialiasMode(D2D1_ANTIALIAS_MODE_PER_PRIMITIVE);
	}

	CreateGDI();
	// === Manager Init === 
	GET_SINGLE(TimeManager)->Init();
	GET_SINGLE(InputManager)->Init();
	GET_SINGLE(ResourceManager)->Init();
	GET_SINGLE(SkillManager)->Init();
	GET_SINGLE(SceneManager)->Init();
	GET_SINGLE(FadeManager)->Init();
	GET_SINGLE(GameManager)->Init();

	return true;
}

void Core::CleanUp()
{
	for (int i = 0; i < (UINT)PEN_TYPE::END; ++i)
	{
		DeleteObject(m_colorPens[i]);
	}
	for (int i = 1; i < (UINT)BRUSH_TYPE::END; ++i)
	{
		// Hollow Á¦¿ÜÇÏ°í
		DeleteObject(m_colorBrushs[i]);
	}

	GET_SINGLE(ResourceManager)->Release();
}

void Core::GameLoop()
{
	MainUpdate();
	MainRender();
	GET_SINGLE(EventManager)->Update();
}

void Core::MainUpdate()
{
	// === Manager Update === 
	GET_SINGLE(TimeManager)->Update();
	GET_SINGLE(InputManager)->Update();
	GET_SINGLE(SkillManager)->Update();
	GET_SINGLE(SceneManager)->Update();
	GET_SINGLE(CollisionManager)->Update();
	GET_SINGLE(FadeManager)->Update();
	GET_SINGLE(GameManager)->Update();
}

void Core::MainRender()
{
	_renderTarget->CreateCompatibleRenderTarget(&_backBuffer);
	{
		_backBuffer->BeginDraw();
		_backBuffer->Clear(D2D1::ColorF(0x306230));
		{
			// Render
			GET_SINGLE(SceneManager)->Render(_backBuffer);
			GET_SINGLE(FadeManager)->Render(_backBuffer);
		}
		_backBuffer->EndDraw();

		_backBuffer->GetBitmap(&_bitmap);
		_renderTarget->BeginDraw();
		_renderTarget->DrawBitmap(_bitmap.Get());
		_renderTarget->EndDraw();

	}
	_backBuffer->Release();
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
