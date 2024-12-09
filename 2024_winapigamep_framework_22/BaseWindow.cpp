#include "pch.h"
#include "BaseWindow.h"
#include "Resource.h"
#include "Core.h"
BaseWindow::BaseWindow()
	: m_hWnd(nullptr)
	, m_hInst(nullptr)
{
}

BaseWindow::~BaseWindow()
{
}

int BaseWindow::Run(HINSTANCE _hInst, LPWSTR _lpCmdline, int _CmdShow)
{
    this->m_hInst = _hInst;
    this->MyRegisterClass();
    this->createWindow();
    this->showWindow(_CmdShow);
    this->updateWindow();
    if (!GET_SINGLE(Core)->Init(m_hWnd))
        MessageBox(m_hWnd, L"Core Init Error", L"Error", MB_OK);
    return this->MessageLoop();
}

LRESULT BaseWindow::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    //case WM_PAINT:
    //{
    //    PAINTSTRUCT ps;
    //    HDC hdc = BeginPaint(hWnd, &ps);
    //    
    //    // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
    //    EndPaint(hWnd, &ps);
    //}
    //break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

ATOM BaseWindow::MyRegisterClass()
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);
    
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = BaseWindow::WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = m_hInst;
    wcex.hIcon = LoadIcon(m_hInst, MAKEINTRESOURCE(IDI_ICON1));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    wcex.lpszMenuName = nullptr;
    wcex.lpszClassName = L"DUNGEONPLATE";
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_ICON1));

    return RegisterClassExW(&wcex);
}

void BaseWindow::createWindow()
{
    int ResolutionX = GetSystemMetrics(SM_CXSCREEN);
    int ResolutionY = GetSystemMetrics(SM_CYSCREEN);

    int Winposx = ResolutionX / 2 - SCREEN_WIDTH / 2;
    int Winposy = ResolutionY / 2 - SCREEN_HEIGHT / 2;

    m_hWnd = CreateWindowW(
        L"DUNGEONPLATE", // 윈도우 클래스 식별자
        L"DUNGEONPLATE",   // 제목
        WS_OVERLAPPEDWINDOW, // 윈도우 어떤 스타일로 만들것인가
        Winposx,  // ★ 띄울 위치의 LEFT
        Winposy,             // ★ 띄울 위치의 TOP
        SCREEN_WIDTH,             // ★ 해상도X
        SCREEN_HEIGHT,             // ★ 해상도Y
        nullptr,       // 부모 윈도우 어쩌구라서 무시
        nullptr,       // 메뉴쓸꺼냐
        m_hInst,     // 내 프로그램 인스턴스 값 
        nullptr);      // 자식 윈도우 관련된것 무시

    // 윈도우 사이즈 조정(타이틀, 메뉴 계싼하지 않도록)
    RECT rt = { Winposx , Winposy,
                 Winposx + SCREEN_WIDTH,
                 Winposy + SCREEN_HEIGHT };
#if _DEBUG
    AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, false);
    MoveWindow(m_hWnd, Winposx, Winposy,
        rt.right - rt.left, rt.bottom - rt.top, false);
    return;
#endif

    AdjustWindowRect(&rt, WS_POPUP, false);
    MoveWindow(m_hWnd, Winposx, Winposy,
        rt.right - rt.left, rt.bottom - rt.top, false);

    // 변경된 스타일 적용
    SetWindowLong(m_hWnd, GWL_STYLE, WS_POPUP | WS_VISIBLE);

    // 크기와 위치 갱신
    SetWindowPos(m_hWnd, NULL, 0, 0,
        rt.right - rt.left,
        rt.bottom - rt.top,
        SWP_FRAMECHANGED | SWP_NOMOVE | SWP_NOSIZE);
}

void BaseWindow::showWindow(int _CmdShow)
{
    // global namespace
    ::ShowWindow(m_hWnd, _CmdShow);
}

void BaseWindow::updateWindow()
{
    ::SetWindowPos(m_hWnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_SHOWWINDOW);

    ::UpdateWindow(m_hWnd); // WM_PAINT
}

int BaseWindow::MessageLoop()
{
    MSG msg;
    memset(&msg, 0, sizeof(msg)); // 0 초기화
    while (true)
    {
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            if (msg.message == WM_QUIT)
                break;
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        else
        {
            // 메인 코드
            GET_SINGLE(Core)->GameLoop();
        }
    }
    GET_SINGLE(Core)->CleanUp();
    return (int)msg.wParam;
}
