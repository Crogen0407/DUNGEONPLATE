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
public:
    void ShowDashUI();
private: //UI
    Slider* healthBar;
    Slider* shieldBar;
    Slider* attackCountBar;
    Slider* dashCoolTimeBar;
    Slider* xpBar;

    Image* bottomDashCoolTimeContainer;

    Text* scoreText;
    Text* timeText;
    Text* healthText;
    Text* shieldText;
};
