#pragma once
class BaseWindow
{
public:
	BaseWindow();
	~BaseWindow();
public:
	int Run(HINSTANCE _hInst, LPWSTR _lpCmdline, int _CmdShow);
private:
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	ATOM MyRegisterClass(); // 1
	void createWindow();   // 2
	void showWindow(int _CmdShow); // 3
	void updateWindow(); // 4
	int  MessageLoop(); // 5
private:
	HINSTANCE m_hInst;
	HWND	  m_hWnd;
};

