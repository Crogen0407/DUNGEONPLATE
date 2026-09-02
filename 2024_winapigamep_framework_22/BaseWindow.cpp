#include "pch.h"
#include "BaseWindow.h"
#include "Resource.h"
#include "Core.h"
#include <windowsx.h> 

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

#include "InputManager.h" // 상단에 추가되어 있는지 확인

LRESULT BaseWindow::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
        // ... (기존 WM_SIZE, WM_MOUSEMOVE 등)

    case WM_SIZING:
    {
        RECT* pRect = (RECT*)lParam;
        DWORD style = (DWORD)GetWindowLong(hWnd, GWL_STYLE);

        // 1. 프레임(타이틀 바 + 테두리)의 실제 두께 계산
        //    AdjustWindowRect를 이용해 "클라이언트 100x100이 전체 크기로 얼마가 되는지" 역산
        RECT testRect = { 0, 0, 100, 100 };
        AdjustWindowRect(&testRect, style, FALSE);
        int frameWidth = (testRect.right - testRect.left) - 100;   // 좌우 테두리 두께 합
        int frameHeight = (testRect.bottom - testRect.top) - 100;  // 상하 테두리+타이틀바 두께 합

        // 2. 현재 드래그 중인 윈도우의 클라이언트 영역 크기 계산
        int currentTotalWidth = pRect->right - pRect->left;
        int currentTotalHeight = pRect->bottom - pRect->top;
        int clientWidth = currentTotalWidth - frameWidth;
        int clientHeight = currentTotalHeight - frameHeight;

        // 3. 정사각형이 되도록 작은 값을 기준으로 맞춤
        int squareSize = min(clientWidth, clientHeight);

        // 4. 드래그 방향(wParam)에 맞춰 pRect를 재조정
        switch (wParam)
        {
        case WMSZ_LEFT:         // 왼쪽 테두리 드래그
            pRect->left = pRect->right - (squareSize + frameWidth);
            break;
        case WMSZ_RIGHT:        // 오른쪽 테두리 드래그
            pRect->right = pRect->left + (squareSize + frameWidth);
            break;
        case WMSZ_TOP:          // 위쪽 테두리 드래그
            pRect->top = pRect->bottom - (squareSize + frameHeight);
            break;
        case WMSZ_BOTTOM:       // 아래쪽 테두리 드래그
            pRect->bottom = pRect->top + (squareSize + frameHeight);
            break;
        case WMSZ_TOPLEFT:      // 왼쪽 위 모서리 드래그
            pRect->left = pRect->right - (squareSize + frameWidth);
            pRect->top = pRect->bottom - (squareSize + frameHeight);
            break;
        case WMSZ_TOPRIGHT:     // 오른쪽 위 모서리 드래그
            pRect->right = pRect->left + (squareSize + frameWidth);
            pRect->top = pRect->bottom - (squareSize + frameHeight);
            break;
        case WMSZ_BOTTOMLEFT:   // 왼쪽 아래 모서리 드래그
            pRect->left = pRect->right - (squareSize + frameWidth);
            pRect->bottom = pRect->top + (squareSize + frameHeight);
            break;
        case WMSZ_BOTTOMRIGHT:  // 오른쪽 아래 모서리 드래그
            pRect->right = pRect->left + (squareSize + frameWidth);
            pRect->bottom = pRect->top + (squareSize + frameHeight);
            break;
        }

        return TRUE; // 우리가 RECT를 수정했음을 Windows에 알림
    }
    case WM_SIZE:
    {
        if (wParam == SIZE_MINIMIZED) return 0;

        // 1. 현재 클라이언트 영역 크기 가져오기
        RECT clientRect;
        GetClientRect(hWnd, &clientRect);
        int clientWidth = clientRect.right - clientRect.left;
        int clientHeight = clientRect.bottom - clientRect.top;

        if (clientWidth == 0 || clientHeight == 0) return 0;

        // 2. WM_SIZING 방식에서는 클라이언트 전체가 게임 영역
        //    따라서 뷰포트 = 클라이언트 영역 전체, 오프셋 = 0
        int viewportWidth = clientWidth;
        int viewportHeight = clientHeight;
        int offsetX = 0;
        int offsetY = 0;

        // 3. InputManager에 뷰포트 정보 전달
        GET_SINGLE(InputManager)->SetViewportInfo(viewportWidth, viewportHeight, offsetX, offsetY);

        return 0;
    }
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    case WM_GETMINMAXINFO:
    {
        MINMAXINFO* pMMI = (MINMAXINFO*)lParam;

        int minSquareSize = 400;

        RECT rc = { 0, 0, minSquareSize, minSquareSize };
        DWORD style = (DWORD)GetWindowLong(hWnd, GWL_STYLE);
        AdjustWindowRect(&rc, style, FALSE);

        pMMI->ptMinTrackSize.x = rc.right - rc.left;
        pMMI->ptMinTrackSize.y = rc.bottom - rc.top;

        return 0;
    }

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

    AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, false);
    MoveWindow(m_hWnd, Winposx, Winposy, rt.right - rt.left, rt.bottom - rt.top, false);
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
