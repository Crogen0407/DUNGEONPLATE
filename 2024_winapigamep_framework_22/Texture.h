#pragma once
#include "ResourceBase.h"
class Texture : public ResourceBase
{
public:
    Texture();
    virtual ~Texture();
public:
	void Load(const wstring& _path);
	const LONG& GetWidth() const { return m_bitInfo.bmWidth; }
	const LONG& GetHeight()const { return m_bitInfo.bmHeight; }
	const HDC& GetTexDC()const { return m_hDC; }
private:
	HDC  m_hDC;  
	HBITMAP m_hBit;
	BITMAP m_bitInfo;
};

