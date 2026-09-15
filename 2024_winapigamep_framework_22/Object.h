#pragma once
class Collider;
class Component;
class Object
{
public:
	Object();
	virtual ~Object();
public:
	virtual void Update() abstract;
	virtual void LateUpdate();
	virtual void Render(ComPtr<ID2D1RenderTarget> renderTarget);
public:
	void SetPosition(Vec2 position) { _position = position; }
	void AddPosition(Vec2 position) { _position += position; }
	void SetSize(Vec2 size) { _size = size; }
	const Vec2& GetPosition() const { return _position; }
	const Vec2& GetSize() const { return _size; }
public:
	virtual void EnterCollision(Collider* other);
	virtual void StayCollision(Collider* other);
	virtual void ExitCollision(Collider* other);
	const bool& GetIsDead() const { return _IsDie; }
	void SetDead() { _IsDie = true; }
	void SetActive(bool active) { _activeSelf = active; }
	const bool GetActive() const { return _activeSelf; }
	void SetName(wstring name) { _name = name; }
	const wstring& GetName() const { return _name; }
	static Object* FindObject(std::wstring name, LAYER layer);
	static vector<Object*> FindObjects(LAYER layer);
protected:
	bool _IsDie;
	bool _activeSelf = true;
	wstring _name;
public:
	template<typename T>
	T* AddComponent()
	{
		T* com = new T;
		com->SetOwner(this);
		_components.push_back(com);

		return com;
	}
	template<typename T>
	T* GetComponent()
	{
		T* component = nullptr;
		for (Component* com : _components)
		{
			component = dynamic_cast<T*>(com);
			if (component)
				break;
		}
		return component;
	}
private:
	Vec2 _position;
	Vec2 _size = { 100, 100 };
	vector<Component*> _components;
};

