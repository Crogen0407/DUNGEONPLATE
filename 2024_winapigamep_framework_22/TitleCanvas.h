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
public:
    void Update() override;
    void LateUpdate() override;
    void Render(HDC hdc) override;
private:
    Button* _startButton;
    Button* _helpButton;
    Button* _quitButton;
};

