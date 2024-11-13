#include "pch.h"
#include "BaseWindow.h"
#include "Scene.h"
#include "TitleScene.h"
#include<crtdbg.h>
int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    BaseWindow game;
    //_CrtSetBreakAlloc(306);
    //_CRTDBG_ALLOC_MEM_DF; // 할당
    _CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF | _CRTDBG_ALLOC_MEM_DF);
    //_CrtSetBreakAlloc(번호);
    game.Run(hInstance, lpCmdLine, nCmdShow);
    //Scene* pScene = new TitleScene;
    //delete pScene;

}