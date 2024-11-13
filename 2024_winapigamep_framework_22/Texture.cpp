#include "pch.h"
#include "Texture.h"
#include <assert.h>
#include "Core.h"
Texture::Texture()
	: m_hDC(nullptr)
	, m_hBit(nullptr)
	, m_bitInfo{}
{
}

Texture::~Texture()
{
	::DeleteDC(m_hDC);
	::DeleteObject(m_hBit);
}

void Texture::Load(const wstring& _path)
{
	// 1: 인스턴스 핸들(nullptr: 독립형 리소스)
	// 2: 경로
	// 3. BITMAP / ICON / CURSOR / .. 
	// 4,5 : 이미지(리소스) 크기
	// 6: 추가 플래그
	m_hBit = (HBITMAP)::LoadImage(nullptr, _path.c_str(), IMAGE_BITMAP,
		0,0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);
	assert(m_hBit); // nullptr이면 assert가 걸립니다.
	m_hDC = ::CreateCompatibleDC(GET_SINGLE(Core)->GetMainDC());
	::SelectObject(m_hDC, m_hBit);
	::GetObject(m_hBit, sizeof(BITMAP), &m_bitInfo);
	int a = 0;
}
