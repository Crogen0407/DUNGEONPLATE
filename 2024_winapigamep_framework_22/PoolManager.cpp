#include "pch.h"
#include "PoolManager.h"
#include "PoolableObject.h"
#include "SlashEffect.h"
#include "FireBallEffect.h"
#include "ExplosionEffect.h"

void PoolManager::Init()
{
    MakeObjectPool<SlashEffect>(L"SlashEffect", LAYER::PROJECTILE, 5);
    MakeObjectPool<FireBallEffect>(L"FireBallEffect", LAYER::PROJECTILE, 150);
    //MakeObjectPool<ExplosionEffect>(L"ExplosionEffect", LAYER::SCREENEFFECT, 100);
    vector<Object*> o = GET_SINGLE(SceneManager)->GetCurrentScene()->GetLayerObjects(LAYER::PROJECTILE);
    int a = 0;
}

PoolableObject* PoolManager::Pop(const std::wstring& type, Vec2 pos)
{
    if (pool.find(type) == pool.end()) return nullptr;
    PoolableObject* poolObject = pool.at(type).top();
    poolObject->SetPos(pos);
    poolObject->SetActive(true);
    poolObject->OnPop();
    pool.at(type).pop();
    return poolObject;
}

void PoolManager::Push(const std::wstring& type, PoolableObject* poolableObject)
{
    poolableObject->OnPush();
    poolableObject->SetActive(false);
    pool[type].push(poolableObject);
}