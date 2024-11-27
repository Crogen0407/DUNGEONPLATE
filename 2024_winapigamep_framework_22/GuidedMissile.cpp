#include "pch.h"
#include "GuidedMissile.h"
#include "ResourceManager.h"
#include "SpriteRenderer.h"
#include "EventManager.h"
#include "TimeManager.h"
#include "Collider.h"

GuidedMissile::GuidedMissile()
{
	AddComponent<SpriteRenderer>();
	tex = GET_SINGLE(ResourceManager)->TextureLoad(L"EnemyMissile", L"Texture\\EnemyMissile.bmp");
	GetComponent<SpriteRenderer>()->SetTexture(tex);

	this->AddComponent<Collider>();
	GetComponent<Collider>()->SetSize({ 20.f,20.f });

	target = FindObject(L"Player", LAYER::PLAYER);
	spawnedTime = TIME;
}

GuidedMissile::~GuidedMissile()
{
}

void GuidedMissile::Update()
{
	Vec2 vPos = GetPos();
	Vec2 targetDir = (vPos * -1) + target->GetPos();
	targetDir.Normalize();

	if (targetDir.x > currentDir.x)
		currentDir.x += fDT;
	else if (targetDir.x < currentDir.x)
		currentDir.x -= fDT;

	if (targetDir.y > currentDir.y)
		currentDir.y += fDT;
	else if (targetDir.y < currentDir.y)
		currentDir.y -= fDT;
	cout << targetDir.x << " " << targetDir.y << " " << currentDir.x << " " << currentDir.y << '\n';

	currentDir.Normalize();

	if (spawnedTime + lifetime < TIME)
		GET_SINGLE(EventManager)->DeleteObject(this);

	vPos.x += currentDir.x * speed * fDT;
	vPos.y += currentDir.y * speed * fDT;
	SetPos(vPos);

	GetComponent<SpriteRenderer>()->LookAt(currentDir);

	Vec2 vSize = GetSize();
	if (vPos.y < -vSize.y)
		GET_SINGLE(EventManager)->DeleteObject(this);
}

void GuidedMissile::Render(HDC _hdc)
{
	ComponentRender(_hdc);
}

void GuidedMissile::EnterCollision(Collider* _other)
{
	GET_SINGLE(EventManager)->DeleteObject(this);
}

void GuidedMissile::StayCollision(Collider* _other)
{
}

void GuidedMissile::ExitCollision(Collider* _other)
{
}
