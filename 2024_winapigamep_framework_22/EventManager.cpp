#include "pch.h"
#include "EventManager.h"
#include "Object.h"
#include "SceneManager.h"

void EventManager::Update()
{
	// 이전 프레임에서 등록해둔 
	for (Object* obj : _deadObjects)
	{
		if (obj != nullptr)
			delete obj;
	}
	_deadObjects.clear();

	for (auto& eve : _events)
		Excute(eve);
	_events.clear();
}

void EventManager::DeleteObject(Object* _pObj)
{
	Event eve = {};
	eve.eventType = EVENT_TYPE::DELETE_OBJECT;
	eve.obj = _pObj;

	if (std::find(_events.begin(), _events.end(), eve) == _events.end())
	{
		_events.push_back(eve);
	}
}

void EventManager::LoadScene(std::wstring sceneName)
{
	Event eve = {};
	eve.eventType = EVENT_TYPE::SCENE_CHANGE;
	eve.name = sceneName;

	if (std::find(_events.begin(), _events.end(), eve) == _events.end())
	{
		_events.push_back(eve);
	}
}

void EventManager::Excute(const Event& _eve)
{
	switch (_eve.eventType)
	{
	case EVENT_TYPE::DELETE_OBJECT:
	{
		Object* pDeadObj = _eve.obj;
		pDeadObj->SetDead();
		_deadObjects.push_back(pDeadObj);
	}
	break;
	case EVENT_TYPE::CREATE_OBJECT:
		break;
	case EVENT_TYPE::SCENE_CHANGE:
	{
		GET_MANAGER(SceneManager)->LoadScene(_eve.name);
	}
	break;
	}
}
