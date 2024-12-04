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
    void Render(HDC _hdc) override;
public:
    bool m_showDebug = false;
    bool onlyOneCountClick = false;
private:
    bool _isClicked = false;
    bool m_isSelected = false;
private:
    Texture* m_defaultTex;
    Texture* m_selectedTex;
    Texture* m_pressedTex;
};

