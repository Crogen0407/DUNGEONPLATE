#pragma once
#include "Object.h"
class SimpleBtnObject : public Object
{
public:
	SimpleBtnObject();
	~SimpleBtnObject() override;
public:
	// Object��(��) ���� ��ӵ�
	void Update() override;
	void Render(HDC _hdc) override;
};

