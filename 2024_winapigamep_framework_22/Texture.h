#pragma once
#include "ResourceBase.h"
class Texture : public ResourceBase
{
public:
    Texture();
    virtual ~Texture();

public:
	const UINT& GetWidth() const { return _bitmap->GetPixelSize().width; }
	const UINT& GetHeight()const { return _bitmap->GetPixelSize().height; }
	const ComPtr<ID2D1Bitmap> GetBitmap() { return _bitmap; }
	void SetBitmap(ComPtr<ID2D1Bitmap> bitmap) { _bitmap = bitmap; }
private:
	ComPtr<ID2D1Bitmap> _bitmap;

};

