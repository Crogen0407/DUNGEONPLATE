#pragma once
#include <stack>
#include "SceneManager.h"
#include "Scene.h"
#include <string>

class PoolableObject;
class PoolManager
{
	DECLARE_SINGLE(PoolManager);

private:
	std::unordered_map<std::wstring, std::stack<PoolableObject*>> pool = {};
public:
	void Init();
	template<typename T>
	void MakeObjectPool(const std::wstring& key, LAYER layer, int count)
	{
		std::stack<PoolableObject*> stack = {};
		pool.insert({ key, stack });
		for (int i = 0; i < count; i++)
		{
			AddPool<T>(key, layer);
		}

	}
	template<typename T>
	void AddPool(const std::wstring& key, LAYER layer)
	{
		T* object = new T;
		GET_SINGLE(SceneManager)->GetCurrentScene()->AddObject(object, layer);
		pool.at(key).push(object);
		object->SetActive(false);
	}
public:
	PoolableObject* Pop(const std::wstring& type, Vec2 pos);
	void Push(const std::wstring& type, PoolableObject* object);
};