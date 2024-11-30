#include "pch.h"
#include "Effect.h"
#include "SpriteRenderer.h"
#include "Object.h"
#include "TimeManager.h"
#include "PoolManager.h"

Effect::Effect()
{
	
}

Effect::~Effect()
{
}

void Effect::Update()
{
	PoolableObject::Update();
	/*std::string str;
	str.assign(GetKey().begin(), GetKey().end());
	cout << str;*/
	_curTime += fDT;
	if (_curTime > _lifeTime)
	{
		//SetActive(false);
		
		PUSH(L"SlashEffect", this);
	}
}

