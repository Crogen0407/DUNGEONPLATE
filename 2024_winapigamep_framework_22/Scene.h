#pragma once
class SlashEffect;
class Object; // 클래스 전방선언
class Scene	
{
public:
	Scene();
	virtual ~Scene(); // 가상 소멸자
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
	LAYER GetLayer(Object* _obj)
	{
		for (int i = 0; i < (UINT)LAYER::END; i++)
		{
			if (find(m_vecObj[i].begin(), m_vecObj[i].end(), _obj) != m_vecObj[i].end())
			{
				return (LAYER)i;
			}
		}

		return LAYER::END;
	}
private:
	//Object m_obj;
	//Object* m_pObj;
	vector<Object*> m_vecObj[(UINT)LAYER::END];
};

