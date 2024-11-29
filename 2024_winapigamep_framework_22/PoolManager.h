#pragma once
#include <stack>
class PoolableObject;
class PoolManager
{
	DECLARE_SINGLE(PoolManager);
private:
	std::map<std::string, std::stack<PoolableObject*>> pool;
public:
	void Init();
	template<typename PoolableObject* T>
	void AddPool(std::string key, PoolableObject* object)
	{
		object->name = key;
		pool[key].push(object);
	}
public:
	PoolableObject* Pop(std::string name);
	void Push(PoolableObject* poolableObject);
};