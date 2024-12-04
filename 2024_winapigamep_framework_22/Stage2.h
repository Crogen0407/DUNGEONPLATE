#pragma once
#include "Stage.h"

class GameScene;

class Stage2 :
    public Stage
{
public:
    virtual void Init() override;
    void Update();
    void Render(GameScene* _gameScene, HDC _hdc);
public:     
    void DrawScene(GameScene* _gameScene, int x, int y, HDC _hdc);
    int GetEnemyCount() const { return m_enemyCount; }
private:
    int m_enemyCount;
};