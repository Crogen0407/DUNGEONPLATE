#pragma once
#include "Object.h"
#include "Action.h"
#include "EnemySpawner.h"
class SpriteRenderer;
class Texture;
class Stage;

class Background : public Object
{
public:
    Stage* owner;
public:
    Background();
    virtual ~Background() override;
public:
    virtual void Update() abstract override;
    void Render(HDC _hdc) override;
public:
    void SubtractEnemyCount();
protected:
    void SpawnEnemyByRandomPos(EnemyType enemyType);
public:
    bool isPlayerArea = false;
    bool isClear = false;
protected:
    EnemySpawner* _enemySpawner;
    SpriteRenderer* _spriteRenderer;
    int _currentEnemyCount = 10;
    HFONT _font;
};

