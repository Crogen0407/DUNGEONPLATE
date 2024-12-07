#pragma once
#include "Scene.h"

class Canvas;
class GameCanvas;
class Background;
class StageLoader;
class GameScene :
    public Scene
{
public: 
    GameScene();
    ~GameScene() override;
private:
    static const int _gridSize = 3;
    int m_currentStage = 1;
    int frameCount = 0;
    int maxFrame = 300;
    bool isInitialized = false;
public:
    void Init() override;
    void Release() override;
    void Update() override;
    void Render(HDC hdc) override;
    void SetEnemyCount();
    void OnNextStageEffect();
private:
    GameCanvas* _gameCanvas;
    std::unique_ptr<StageLoader> _stageLoader;
    Canvas* _skillCanvas;
};

