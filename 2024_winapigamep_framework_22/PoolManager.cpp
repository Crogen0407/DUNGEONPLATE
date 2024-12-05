#include "pch.h"
#include "PoolManager.h"
#include "PoolableObject.h"
#include "SlashEffect.h"
#include "FireBallEffect.h"
#include "EnemyBullet.h"
#include "GuidedMissile.h"
#include "EnemyBounceBullet.h"

void PoolManager::Init(Scene* curScene)
{
    pool = {};
    _curScene = curScene;
    MakeObjectPool<SlashEffect>(L"SlashEffect", LAYER::PROJECTILE, 5);
    MakeObjectPool<FireBallEffect>(L"FireBallEffect", LAYER::PROJECTILE, 150);
    MakeObjectPool<EnemyBullet>(L"EnemyBullet", LAYER::PROJECTILE, 200);
    MakeObjectPool<GuidedMissile>(L"GuidedMissile", LAYER::PROJECTILE, 50);
    MakeObjectPool<EnemyBounceBullet>(L"EnemyBounceBullet", LAYER::PROJECTILE, 50);
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