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
    void Render(ComPtr<ID2D1RenderTarget> renderTarget) override;
protected:
    void SpawnEnemy(EnemyType enemyType, const Vec2& pos);
    void SpawnEnemyByRandomPos(EnemyType enemyType);
public:
    bool isPlayerArea = false;
    bool isClear = false;
protected:
    EnemySpawner* _enemySpawner;
    SpriteRenderer* _spriteRenderer;
    unsigned __int8 _currentEnemyCount = 0;
    unsigned __int8 _currentSpawnedEnemyIndex = 0;
    unsigned __int8 _maxEnemyCount = 10;

    ComPtr<IDWriteTextFormat> _textFormat = nullptr;
    ComPtr<ID2D1SolidColorBrush> _brush = nullptr;

public:
    void LoadFont(std::wstring fontName, float fontSize);
};

