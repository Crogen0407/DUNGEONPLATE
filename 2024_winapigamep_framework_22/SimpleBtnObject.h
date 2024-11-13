#pragma once
#include "Object.h"
class SimpleBtnObject : public Object
{
public:
	SimpleBtnObject();
	~SimpleBtnObject() override;
public:
	// Object을(를) 통해 상속됨
	void Update() override;
	void Render(HDC _hdc) override;
};

