#include "pch.h"
#include "InputManager.h"
#include "Core.h"

void InputManager::Init()
{
    for (int i = 0; i < (int)KEY_TYPE::LAST; ++i)
        m_vecKey.push_back(tKeyInfo{ KEY_STATE::NONE, false });

    // 초기 뷰포트 정보를 기본 해상도로 설정
    m_viewportWidth = SCREEN_WIDTH;
    m_viewportHeight = SCREEN_HEIGHT;
    m_viewportOffsetX = 0;
    m_viewportOffsetY = 0;
}

void InputManager::Update()
{
    // 포커싱된 윈도우 핸들 가져오기
    HWND hWnd = GetFocus();
    if (hWnd == nullptr)
    {
        // 창이 포커스를 잃었을 때 모든 키 상태를 NONE으로 초기화
        for (int i = 0; i < (int)KEY_TYPE::LAST; ++i)
        {
            m_vecKey[i].IsPrevCheck = false;
            m_vecKey[i].eState = KEY_STATE::NONE;
        }
        return;
    }

    // 키보드 입력 상태 업데이트
    for (int i = 0; i < (int)KEY_TYPE::LAST; ++i)
    {
        if (GetAsyncKeyState(m_arrVKKey[i]) & 0x8000) // 0x8000 마스크로 최상위 비트 확인 (더 안정적)
        {
            if (m_vecKey[i].IsPrevCheck)
                m_vecKey[i].eState = KEY_STATE::PRESS;
            else
                m_vecKey[i].eState = KEY_STATE::DOWN;
            m_vecKey[i].IsPrevCheck = true;
        }
        else
        {
            if (m_vecKey[i].IsPrevCheck)
                m_vecKey[i].eState = KEY_STATE::UP;
            else
                m_vecKey[i].eState = KEY_STATE::NONE;
            m_vecKey[i].IsPrevCheck = false;
        }
    }

    // 마우스 입력 상태 업데이트
    ::GetCursorPos(&m_ptMouse); // 1. 화면 기준 좌표(Screen Coordinates) 가져오기

    // 2. 현재 게임 윈도우의 클라이언트 기준 좌표(Client Coordinates)로 변환
    // (m_ptMouse는 이제 (0,0)이 윈도우 왼쪽 상단 내부인 좌표가 됨)
    ::ScreenToClient(GET_SINGLE(Core)->GetHwnd(), &m_ptMouse);
}