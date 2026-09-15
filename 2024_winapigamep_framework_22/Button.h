#pragma once
#include "Image.h"
#include "Action.h"

class Texture;
class Button : public Image
{
public:
    Button();
    ~Button();
public:
    void Init(Texture* defultTex, Texture* selectedTex, Texture* pressedTex);
    void OnClick();
    void OnSelectEnter();
    void OnSelectExit();
public:
    Action<int> OnClickEvent;
    Action<int> OnSelectEnterEvent;
    Action<int> OnSelectExitEvent;
public:
    void LateUpdate() override;
    void Render(ComPtr<ID2D1RenderTarget> renderTarget) override;
public:
    bool onlyOneCountClick = false;
private:
    bool _isClicked = false;
    bool _isSelected = false;
private:
    Texture* _defaultTex;
    Texture* _selectedTex;
    Texture* _pressedTex;
};

