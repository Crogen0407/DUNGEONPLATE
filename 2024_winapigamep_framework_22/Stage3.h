#pragma once
#include "Stage.h"
#include "StageScene.h"
class Stage3 :
    public Stage
{
public:
    virtual void Init() override;
    void Update();
    void Render(StageScene* stageScene, HDC _hdc);
public:
    void DrawScene(StageScene* stageScene, int x, int y, HDC _hdc);
};

