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
	virtual void EnterCollision(Collider* _other);
	virtual void StayCollision(Collider* _other);
	virtual void ExitCollision(Collider* _other);
	const bool& GetIsDead() const { return m_IsDie; }
	void SetDead() { m_IsDie = true; }
	void SetActive(bool active) { activeSelf = active; }
	const bool GetActive() const { return activeSelf; }
	void SetName(wstring _name) { m_name = _name; }
	const wstring& GetName() const { return m_name; }
	static Object* FindObject(std::wstring name, LAYER layer);
	static vector<Object*> FindObjects(LAYER layer);
protected:
	bool m_IsDie;
	bool activeSelf = true;
	wstring m_name;
public:
	template<typename T>
	T* AddComponent()
	{
		T* com = new T;
		com->SetOwner(this);
		m_vecComponents.push_back(com);

		return com;
	}
	template<typename T>
	T* GetComponent()
	{
		T* component = nullptr;
		for (Component* com : m_vecComponents)
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
	vector<Component*> m_vecComponents;
};

