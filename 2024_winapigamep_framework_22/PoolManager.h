#pragma once
#include <stack>
#include "Scene.h"

class PoolableObject;
class PoolManager
{
	DECLARE_SINGLE(PoolManager);

private:
	std::unordered_map<std::wstring, std::stack<PoolableObject*>> pool = {};
	Scene* _curScene;
public:
	void Init(Scene* curScene);
	template<typename T>
	void MakeObjectPool(const std::wstring& key, LAYER layer, int count)
	{
		std::stack<PoolableObject*> stack = {};
		pool.insert({ key, stack });
		for (int i = 0; i < count; i++)
		{
			T* object = new T;
			_curScene->AddObject(object, layer);
			object->SetPos({ -100000, -100000 });
			pool.at(key).push(object);
			object->SetActive(false);
		}
	}
public:
	PoolableObject* Pop(const std::wstring& type, Vec2 pos);
	void Push(const std::wstring& type, PoolableObject* object);
};