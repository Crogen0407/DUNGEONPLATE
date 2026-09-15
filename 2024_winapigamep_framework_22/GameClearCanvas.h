#pragma once
#include "Canvas.h"
class Slider;
class Image;
class Text;
class Button;
class GameClearCanvas : public Canvas
{
public:
	GameClearCanvas();
	~GameClearCanvas() override;
private:
	Text* _titleText;
	Text* _mentText;
	Button* _gotoTitleSceneButton;
};