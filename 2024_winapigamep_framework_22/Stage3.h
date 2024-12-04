#pragma once
#include "Stage.h"
#include "StageScene.h"

class GameScene;

class Stage3 :
    public Stage
{
public:
    virtual void Init() override;
    void Update();
    void Render(GameScene* _gameScene, HDC _hdc);
public:
    void DrawScene(GameScene* _gameScene, int x, int y, HDC _hdc);
};

