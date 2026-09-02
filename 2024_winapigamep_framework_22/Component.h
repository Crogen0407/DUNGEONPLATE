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
	void SetOwner(Object* _owner) { m_pOwner = _owner; }
	Object* GetOwner() const { return m_pOwner; }
private:
	Object* m_pOwner;
};

