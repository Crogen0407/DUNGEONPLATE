#pragma once
class Object;
class Stage
{
public:
	Stage();
	virtual ~Stage();
public:
	virtual void Init() abstract;
	virtual void Update();
	virtual void LateUpdate();
	virtual void Render(HDC _hdc);
	virtual void Release();
	bool m_isClear = false;
public:
	void AddObject(Object* _obj, LAYER _type)
	{
		m_vecObj[(UINT)_type].push_back(_obj);
	}
	const vector<Object*>& GetLayerObjects(LAYER _type)
	{
		return m_vecObj[(UINT)_type];
	}
private:
	vector<Object*> m_vecObj[(UINT)LAYER::END];
};