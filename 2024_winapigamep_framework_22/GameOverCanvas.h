#pragma once
#include "Canvas.h"
class Slider;
class Image;
class Button;
class Text;
class GameOverCanvas :
    public Canvas
{
public:
    GameOverCanvas();
    ~GameOverCanvas() override;
public:
    void Update() override;
private:
    Text* titleText;
    Text* mentText;
    Button* retryButton;
    Button* gotoTitleSceneButton;
};

