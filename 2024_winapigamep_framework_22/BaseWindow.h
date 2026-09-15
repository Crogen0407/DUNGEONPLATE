#pragma once
class BaseWindow
{
public:
	BaseWindow();
	~BaseWindow();
public:
	int Run(HINSTANCE hInstance, LPWSTR lpCmdline, int cmdShow);
private:
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	ATOM MyRegisterClass(); // 1
	void createWindow();   // 2
	void ShowWindow(int _CmdShow); // 3
	void UpdateWindow(); // 4
	int  MessageLoop(); // 5
private:
	HINSTANCE _hInstance;
	HWND	  _hWnd;
};

