#include "pch.h"
#include "Razer.h"
#include "ResourceManager.h"
#include "SpriteRenderer.h"
#include "TimeManager.h"
#include "Texture.h"
#include "Collider.h"
#include "EventManager.h"
#include "SceneManager.h"
#include "Scene.h"
#include "HealthCompo.h"

Razer::Razer(float lifeTime)
{
	_damage = 10;
	SetSize({ 0,0 });
	_lifeTime = lifeTime;
	_startLifeTime = TIME;
	_texture = LOADTEXTURE(L"Razer", L"Texture\\Razer.png");

	AddComponent<Collider>();
	GetComponent<Collider>()->SetSize(GetSize());
}

Razer::~Razer()
{
}

void Razer::Update()
{
	if (_startLifeTime + _lifeTime < TIME)
		GET_MANAGER(EventManager)->DeleteObject(this);

	Vec2 vPos = _owner->GetPosition();
	Vec2 vSize = GetSize();

	vSize.x = 80.f + (sinf(TIME * 50) * 0.5f + 0.5f) * 20.f;

	if (vSize.y <= _targetSize)
		vSize = Vec2(vSize.x, vSize.y + (1000 * fDT));

	vPos = Vec2(vPos.x, vPos.y + 50 + vSize.y / 2);// Vec2(0, 1)* (vSize.y * 2);
	GetComponent<Collider>()->SetSize(vSize);
	SetSize(vSize);
	SetPosition(vPos);
}

void Razer::Render(ComPtr<ID2D1RenderTarget> renderTarget)
{
	Vec2 vPos = GetPosition();
	Vec2 vSize = GetSize();

	int width = _texture->GetWidth();
	int height = _texture->GetHeight();

	renderTarget->DrawBitmap(
		_texture->GetBitmap().Get(), 
		D2D1::RectF(vPos.x - vSize.x / 2, 
			vPos.y - vSize.y / 2, 
			vPos.x + vSize.x / 2, 
			vPos.y + vSize.y / 2), 
		1.0f,
		D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR
	);
}

void Razer::EnterCollision(Collider* _other)
{
}

void Razer::StayCollision(Collider* _other)
{

	if (_prevAttackTime + _attackDelay < TIME)
	{
		_prevAttackTime = TIME;
		LAYER layer =
			GET_MANAGER(SceneManager)->GetCurrentScene()->GetLayer(_other->GetOwner());

		if (layer == LAYER::PLAYER)
		{
			HealthCompo* health = _other->GetOwner()->GetComponent<HealthCompo>();

			if (health != nullptr)
				health->ApplyDamage(_damage);
		}
	}
}
