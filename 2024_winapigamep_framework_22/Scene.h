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
	virtual void Render(ComPtr<ID2D1RenderTarget> renderTarget);
	virtual void Release();
public:
	void ChangeLayer(Object* obj, LAYER from, LAYER to)
	{
		_objects[(UINT)from].erase(
			remove(_objects[(UINT)from].begin(), _objects[(UINT)from].end(), obj),
			_objects[(UINT)from].end());

		AddObject(obj, to);
	}
	void AddObject(Object* obj, LAYER type)
	{
		_objects[(UINT)type].push_back(obj);
	}
	const vector<Object*>& GetLayerObjects(LAYER type)
	{
		return _objects[(UINT)type];
	}
	LAYER GetLayer(Object* obj)
	{
		for (int i = 0; i < (UINT)LAYER::END; i++)
		{
			if (find(_objects[i].begin(), _objects[i].end(), obj) != _objects[i].end())
			{
				return (LAYER)i;
			}
		}

		return LAYER::END;
	}
private:
	vector<Object*> _objects[(UINT)LAYER::END];
};

