#include "pch.h"
#include "BaseWindow.h"
#include "Scene.h"
#include "TitleScene.h"
#include <crtdbg.h>

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    HRESULT hr = ::CoInitializeEx(nullptr, COINIT_APARTMENTTHREADED);
    if (FAILED(hr))
    {
        MessageBox(nullptr, L"CoInitializeEx 실패", L"Error", MB_OK);
        return -1;
    }

    BaseWindow game;
    _CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF | _CRTDBG_ALLOC_MEM_DF);
    int result = game.Run(hInstance, lpCmdLine, nCmdShow);

    ::CoUninitialize();
    return result;
}