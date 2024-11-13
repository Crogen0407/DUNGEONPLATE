#pragma once
// GameManager
//SAFE_DELETE()
// µø¿˚ ΩÃ±€≈Ê(¥Ÿ¿Ã≥™πÕ ΩÃ±€≈Ê)
// ¡§¿˚ ΩÃ±€≈Ê
#include "Define.h"
//#include "Object.h"
class Core
{
	DECLARE_SINGLE(Core);
public:
	bool Init(HWND _hwnd);
	void GameLoop();
	void CleanUp();
private:
	void MainUpdate();
	void MainRender();
	void CreateGDI();
public:
	const HWND& GetHwnd() const { return m_hWnd; }
	// ¿Ã∏ß πŸ≤Ÿ±‚
	const HDC& GetMainDC() const { return m_hDC; }
	const HBRUSH& GetBrush(BRUSH_TYPE _eType)
	{
		return m_colorBrushs[(UINT)_eType];
	}
	const HPEN& GetPen(PEN_TYPE _eType)
	{
		return m_colorPens[(UINT)_eType];
	}

private:
	HBRUSH m_colorBrushs[(UINT)BRUSH_TYPE::END] = {};
	HPEN m_colorPens[(UINT)PEN_TYPE::END] = {};

	HWND m_hWnd;
	HDC  m_hDC; // Main DC
	HDC  m_hBackDC; // πÈπˆ∆€ DC
	HBITMAP m_hBackBit; // πÈπˆ∆€¿« bitmap
	//Object m_obj;
	//private:
//	Core() {}
//public:
//	static Core* GetInst()
//	{
//		static Core m_pInst;
//		return &m_pInst;
//	}
//	/*static Core& GetInst2()
//	{
//		static Core m_pInst;
//		return m_pInst;
//	}*/
//
//private:


};
//void test()
//{
//	static int a = 0;
//
//}
// ≈€«√∏¥ ΩÃ±€≈Ê
//class Core 
//{
// //private:
//	static Core* m_pInst;
//public:
//	static Core* GetInst()
//	{
//		if (nullptr == m_pInst)
//			m_pInst = new Core;
//		return m_pInst;
//	}
//	static void DestoryInst()
//	{
//		if (nullptr != m_pInst)
//		{
//
//		}
//	}
//private:
//	Core() {}

//};

