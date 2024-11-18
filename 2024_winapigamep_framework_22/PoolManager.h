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
public:
	PoolableObject* Pop(std::string name);
	void Push(PoolableObject* poolableObject);
};