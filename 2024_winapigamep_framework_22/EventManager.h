#pragma once
#include "IManager.h"
class Object;
class Scene;
struct Event
{
	EVENT_TYPE eventType;
	Object* obj;
	std::wstring name;
	LAYER objType;
public:
	bool operator==(const Event& other)
	{
		return eventType == other.eventType && obj == other.obj;
	}
};
class EventManager : public IManager
{
public:
	void Init() override { /* Empty */ }
	void Update() override;
	void DeleteObject(Object* _pObj);
	void LoadScene(std::wstring sceneName);
private:
	void Excute(const Event& _eve);
private:
	vector<Event> _events;
	vector<Object*> _deadObjects;
};