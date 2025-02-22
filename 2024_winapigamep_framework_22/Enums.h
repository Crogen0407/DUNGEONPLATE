#pragma once
enum class LAYER
{
	BACKGROUND,
	PLAYERCAST,
	DEFAULT,
	PLAYER,
	PROJECTILE,
	EFFECT,
	ENEMY,
	UI,
	SCREENEFFECT,
	END
};

enum class PEN_TYPE
{
	HOLLOW, RED, GREEN,
	BLUE, YELLOW, END
};

enum class BRUSH_TYPE
{
	HOLLOW, RED, GREEN,
	BLUE, YELLOW, END
};


enum class EVENT_TYPE
{
	CREATE_OBJECT,
	DELETE_OBJECT,
	SCENE_CHANGE,
	END,
};
