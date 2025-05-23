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
	virtual void Render(HDC _hdc) abstract;
	void ComponentRender(HDC _hdc);
public:
	void SetPos(Vec2 _vPos) { m_vPos = _vPos; }
	void AddPos(Vec2 pos) { m_vPos += pos; }
	void SetSize(Vec2 _vSize) { m_vSize = _vSize; }
	const Vec2& GetPos() const { return m_vPos; }
	const Vec2& GetSize() const { return m_vSize; }
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
	//POINT m_ptPos;
	//POINT m_ptSize;
	Vec2 m_vPos;
	Vec2 m_vSize = { 100, 100 };
	vector<Component*> m_vecComponents;
};

