#pragma once
#include "Scene.h"
class GameClearScene :
    public Scene
{
public:
    void Init() override;
    void Update() override;
    void LateUpdate() override;
    void Render(HDC _hdc) override;
};

