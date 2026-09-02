#pragma once
#include "Canvas.h"
class Slider;
class Image;
class Button;
class Text;
class TitleCanvas :
    public Canvas
{
public:
    TitleCanvas();
    ~TitleCanvas() override;

private:
    Button* _startButton;
    Button* _helpButton;
    Button* _quitButton;
};

