#pragma once
// PlayerManager
//SAFE_DELETE()
// µø¿˚ ΩÃ±€≈Ê(¥Ÿ¿Ã≥™πÕ ΩÃ±€≈Ê)
// ¡§¿˚ ΩÃ±€≈Ê
#include "Define.h"
//#include "Object.h"
class Core
{
	DECLARE_SINGLE(Core);
public:
	bool Init(HWND hwnd);
	void GameLoop();
	void CleanUp();

private:
	void MainUpdate();
	void MainRender();
	void CreateGDI();

public:
	const HWND& GetHwnd() const { return _hWnd; }
	const HBRUSH& GetBrush(BRUSH_TYPE brushType)
	{
		return _colorBrushs[(UINT)brushType];
	}
	const HPEN& GetPen(PEN_TYPE penType)
	{
		return _colorPens[(UINT)penType];
	}
	const ComPtr<ID2D1HwndRenderTarget> GetRenderTarget() { return _renderTarget; }
	const ComPtr<ID2D1Factory> GetFactory() { return _factory; }

private:
	HBRUSH _colorBrushs[(UINT)BRUSH_TYPE::END] = {};
	HPEN _colorPens[(UINT)PEN_TYPE::END] = {};

	HWND _hWnd;
	ComPtr<ID2D1Factory> _factory = nullptr;

	ComPtr<ID2D1HwndRenderTarget> _renderTarget = nullptr;
};