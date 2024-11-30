#include "pch.h"
#include "PoolableObject.h"

PoolableObject::PoolableObject()
{
}

PoolableObject::~PoolableObject()
{
}

void PoolableObject::Update()
{
}

void PoolableObject::LateUpdate()
{
	Object::LateUpdate();
}

void PoolableObject::Render(HDC _hdc)
{
}
