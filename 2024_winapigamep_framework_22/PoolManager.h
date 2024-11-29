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
	void AddPool(std::string key, PoolableObject* object);
public:
	PoolableObject* Pop(std::string type);
	void Push(PoolableObject* object);
};