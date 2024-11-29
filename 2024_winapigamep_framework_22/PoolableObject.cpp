#include "pch.h"
#include "PoolableObject.h"

void PoolableObject::Update()
{
	Object::Update();
}

void PoolableObject::LateUpdate()
{
	Object::LateUpdate();
}

void PoolableObject::Render(HDC _hdc)
{
	Object::Render(_hdc);
}
