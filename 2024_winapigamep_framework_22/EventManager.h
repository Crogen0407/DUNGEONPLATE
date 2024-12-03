#pragma once
class Object;
class Scene;
struct tEvent
{
	EVENT_TYPE eveType;
	Object* obj;
	Scene* scene;
	LAYER objType;
public:
	bool operator==(const tEvent& other)
	{
		return eveType == other.eveType && obj == other.obj;
	}
};
class EventManager
{
	DECLARE_SINGLE(EventManager);
public:
	void Update();
	void DeleteObject(Object* _pObj);
	void DeleteScene(Scene* pScene);
	// todo..
private:
	void Excute(const tEvent& _eve);
private:
	vector<tEvent> m_vecEvent;
	vector<Object*> m_vecObjectDead;
	Scene* deadScene;
	Scene* loadScene;
};