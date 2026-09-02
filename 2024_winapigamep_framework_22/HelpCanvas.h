#pragma once
#include "Canvas.h"
class Image;
class Text;
class Button;
class Texture;

class Slide
{
public:
    Slide(std::wstring description)
    {
        this->description = description;
    }
    ~Slide()
    {
    }
public:
    Texture* texture;
    std::wstring description;
};

class HelpCanvas :
    public Canvas
{
public:
    HelpCanvas();
    ~HelpCanvas() override;
public:
    void Update() override;
private:
    Image*      _slideImage;
    Text*       _descriptionText;

    bool _isFading = false;
    int _curSlide = 0;
    std::vector<Slide*> slides;
};

