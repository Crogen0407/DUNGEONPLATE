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
#include "PlayerManager.h"
#include "Managers.h"

bool Core::Init(HWND hwnd)
{
	_hWnd = hwnd;
	
	// Direct2D 렌더
	{
		::D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, _factory.GetAddressOf());

		// 렌더 타겟 속성 설정
		D2D1_RENDER_TARGET_PROPERTIES rtProps = D2D1::RenderTargetProperties(
			D2D1_RENDER_TARGET_TYPE_DEFAULT,
			D2D1::PixelFormat(DXGI_FORMAT_B8G8R8A8_UNORM, D2D1_ALPHA_MODE_IGNORE),
			0, 0
		);

		// 창 핸들을 가져와서 연결
		D2D1_HWND_RENDER_TARGET_PROPERTIES hwndRTProps = D2D1::HwndRenderTargetProperties(
			_hWnd, D2D1::SizeU(SCREEN_WIDTH, SCREEN_HEIGHT), D2D1_PRESENT_OPTIONS_IMMEDIATELY
		);

		_factory->CreateHwndRenderTarget(&rtProps, &hwndRTProps, _renderTarget.GetAddressOf());

		// AA 적용
		_renderTarget->SetAntialiasMode(D2D1_ANTIALIAS_MODE_PER_PRIMITIVE);
	}

	CreateGDI();
	// === Manager Init === 
	GET_SINGLE(Managers)->Init();

	return true;
}

void Core::CleanUp()
{
	for (int i = 0; i < (UINT)PEN_TYPE::END; ++i)
	{
		DeleteObject(_colorPens[i]);
	}
	for (int i = 1; i < (UINT)BRUSH_TYPE::END; ++i)
	{
		// Hollow 제외하고
		DeleteObject(_colorBrushs[i]);
	}

	GET_SINGLE(Managers)->Release();
}

void Core::GameLoop()
{
	MainUpdate();
	MainRender();
}

void Core::MainUpdate()
{
	// === Manager Update === 
	GET_SINGLE(Managers)->Update();
}

void Core::MainRender()
{
	_renderTarget->CreateCompatibleRenderTarget(&_backBuffer);
	{
		_backBuffer->BeginDraw();
		_backBuffer->Clear(D2D1::ColorF(0x306230));
		{
			// Render
			GET_SINGLE(Managers)->Render(_backBuffer);
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
	_colorBrushs[(UINT)BRUSH_TYPE::HOLLOW] = (HBRUSH)GetStockObject(HOLLOW_BRUSH);
	_colorBrushs[(UINT)BRUSH_TYPE::RED] = (HBRUSH)CreateSolidBrush(RGB(255, 167, 167));
	_colorBrushs[(UINT)BRUSH_TYPE::GREEN] = (HBRUSH)CreateSolidBrush(RGB(134, 229, 134));
	_colorBrushs[(UINT)BRUSH_TYPE::BLUE] = (HBRUSH)CreateSolidBrush(RGB(103, 153, 255));
	_colorBrushs[(UINT)BRUSH_TYPE::YELLOW] = (HBRUSH)CreateSolidBrush(RGB(255, 187, 0));

	//RED GREEN BLUE PEN
	_colorPens[(UINT)PEN_TYPE::RED] = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	_colorPens[(UINT)PEN_TYPE::GREEN] = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
	_colorPens[(UINT)PEN_TYPE::BLUE] = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
	_colorPens[(UINT)PEN_TYPE::YELLOW] = CreatePen(PS_SOLID, 1, RGB(255, 255, 0));
	_colorPens[(UINT)PEN_TYPE::HOLLOW] = CreatePen(PS_NULL, 0, RGB(0, 0, 0));
}
