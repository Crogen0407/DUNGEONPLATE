#pragma once
class Object;
class Component
{
public:
	Component();
	virtual ~Component();
public:
	virtual void LateUpdate() abstract;
	virtual void Render(ComPtr<ID2D1RenderTarget> renderTarget) abstract;
public:
	void SetOwner(Object* owner) { _owner = owner; }
	Object* GetOwner() const { return _owner; }
private:
	Object* _owner;
};

