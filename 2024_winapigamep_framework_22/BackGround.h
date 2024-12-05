#pragma once
#include "Object.h"
#include "EnemySpawner.h"
class SpriteRenderer;
class Texture;

class Background :
    public Object, public EnemySpawner
{
public:
    Background();
    ~Background() override;
public:
    void Update() override;
    void Render(HDC _hdc) override;
public:
    void SubtractEnemyCount()
    {
        if (_currentEnemyCount <= 0) return;
        --_currentEnemyCount;
    }
protected:
    void SpawnEnemyByRandomPos(EnemyType enemyType);
public:
    bool isPlayerArea = false;
private:
    SpriteRenderer* _spriteRenderer;
    int _currentEnemyCount = 10;
    HFONT _font;
};

