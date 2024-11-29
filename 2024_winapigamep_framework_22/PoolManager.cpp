#include "pch.h"
#include "PoolManager.h"
#include "PoolableObject.h"

void PoolManager::Init()
{
    
}

PoolableObject* PoolManager::Pop(std::string name)
{
    PoolableObject* poolObject = pool[name].top();
    poolObject->OnPop();
    pool[name].pop();
    return poolObject;
}

void PoolManager::Push(PoolableObject* poolableObject)
{
    poolableObject->OnPush();
    pool[poolableObject->name].push(poolableObject);
}