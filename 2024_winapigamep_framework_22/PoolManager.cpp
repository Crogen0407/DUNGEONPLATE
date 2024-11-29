#include "pch.h"
#include "PoolManager.h"
#include "PoolableObject.h"
#include "SlashEffect.h"

void PoolManager::Init()
{
    MakeObjectPool<SlashEffect>(L"SlashEffect", 5);
}

PoolableObject* PoolManager::Pop(std::wstring name)
{
    PoolableObject* poolObject = pool[name].top();
    pool[name].pop();
    poolObject->OnPop();
    return poolObject;
}

void PoolManager::Push(PoolableObject* poolableObject)
{
    poolableObject->OnPush();
    pool[poolableObject->name].push(poolableObject);
}