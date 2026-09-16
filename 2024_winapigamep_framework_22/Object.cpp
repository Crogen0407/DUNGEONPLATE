#include "pch.h"
#include "Object.h"
#include "TimeManager.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "Scene.h"
#include "Component.h"
#include <typeinfo>

Object::Object()
	: _position{}
	, _size{}
	, _IsDie(false)
{

}

Object::~Object()
{
	int a = 0;
	for (Component* com : _components)
	{
		if (com != nullptr)
			delete com;
	}
	_components.clear();
}

void Object::LateUpdate()
{
	for (Component* com : _components)
	{
		if (com)
		{
			com->LateUpdate();
		}
	}
}

void Object::Render(ComPtr<ID2D1RenderTarget> renderTarget)
{
	for (Component* com : _components)
	{
		if (com)
		{
			com->Render(renderTarget);
		}
	}
}

Object* Object::FindObject(std::wstring name, LAYER layer)
{
	Object* object = GET_MANAGER(SceneManager)->FindObject(name, layer);
	return object;
}

vector<Object*> Object::FindObjects(LAYER layer)
{
	vector<Object*> objects = GET_MANAGER(SceneManager)->GetCurrentScene()->GetLayerObjects(layer);

	return objects;
}

//void Object::Update()
//{
//	if (GET_KEY(KEY_TYPE::LEFT))
//		m_vPos.x -= 100.f * fDT;
//	if (GET_KEY(KEY_TYPE::RIGHT))
//		m_vPos.x += 100.f * fDT;
//}
//
//void Object::Render(HDC _hdc)
//{
//	RECT_RENDER(_hdc, m_vPos.x, m_vPos.y
//		, m_vSize.x, m_vSize.y);
//}
