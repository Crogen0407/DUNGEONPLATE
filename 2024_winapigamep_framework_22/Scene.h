#pragma once
class SlashEffect;
class Object; // Ŭ���� ���漱��
class Scene	
{
public:
	Scene();
	virtual ~Scene(); // ���� �Ҹ���
public:
	virtual void Init() abstract;
	virtual void Update();
	virtual void LateUpdate();
	virtual void Render(HDC _hdc);
	virtual void Release();
public:
	void ChangeLayer(Object* _obj, LAYER from, LAYER to)
	{
		m_vecObj[(UINT)from].erase(
			remove(m_vecObj[(UINT)from].begin(), m_vecObj[(UINT)from].end(), _obj),
			m_vecObj[(UINT)from].end());

		AddObject(_obj, to);
	}
	void AddObject(Object* _obj, LAYER _type)
	{
		m_vecObj[(UINT)_type].push_back(_obj);
	}
	const vector<Object*>& GetLayerObjects(LAYER _type)
	{
		return m_vecObj[(UINT)_type];
	}
private:
	//Object m_obj;
	//Object* m_pObj;
	vector<Object*> m_vecObj[(UINT)LAYER::END];
};

