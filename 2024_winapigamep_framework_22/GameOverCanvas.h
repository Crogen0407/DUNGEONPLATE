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
private:
    Text* _titleText;
    Text* _mentText;
    Button* _retryButton;
    Button* _gotoTitleSceneButton;
};

