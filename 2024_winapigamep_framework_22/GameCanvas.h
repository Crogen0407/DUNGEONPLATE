#pragma once
#include "Canvas.h"
class Slider;
class Image;
class Text;
class GameCanvas : public Canvas
{
public:
    GameCanvas();
    ~GameCanvas() override;
public:
    void Update() override;
    void LateUpdate() override;
    void Render(HDC hdc) override;
private: //UI
    Slider* healthBar;
    Slider* shieldBar;
    Slider* attackCountBar;
    Text* scoreText;
    Text* timeText;
};
