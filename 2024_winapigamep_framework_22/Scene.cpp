#include "pch.h"
#include "Scene.h"
#include "Object.h"
#include "CollisionManager.h"
Scene::Scene()
{
}

Scene::~Scene()
{
	Release();
}

void Scene::Update()
{
	for (UINT i = 0; i < (UINT)LAYER::END; ++i)
	{
		for (size_t j = 0; j < _objects[i].size(); ++j)
		{
			if (_objects[i][j]->GetActive() == false) continue;
			if (!_objects[i][j]->GetIsDead())
				_objects[i][j]->Update();
		}
	}
}

void Scene::LateUpdate()
{
	for (size_t i = 0; i < (UINT)LAYER::END; i++)
	{
		for (UINT j = 0; j < _objects[i].size(); ++j)
		{
			if (_objects[i][j]->GetActive() == false) continue;
			if (!_objects[i][j]->GetIsDead())
				_objects[i][j]->LateUpdate();
		}
	}
}

void Scene::Render(ComPtr<ID2D1RenderTarget> renderTarget)
{
	for (UINT i = 0; i < (UINT)LAYER::END; ++i)
	{
		for (size_t j = 0; j < _objects[i].size();)
		{
			if (!_objects[i][j]->GetIsDead() == true)
			{
				if (_objects[i][j]->GetActive() == false)
				{
					j++;
					continue;
				}
				_objects[i][j++]->Render(renderTarget);
			}
			else
				_objects[i].erase(_objects[i].begin() + j);
		}
	}

}

void Scene::Release()
{
	// 오브젝트 삭제.
	for (size_t i = 0; i < (UINT)LAYER::END; i++)
	{
		for (UINT j = 0; j < _objects[i].size(); ++j)
		{
			delete _objects[i][j];
		}
		_objects[i].clear();
		_objects[i] = { };
	}
	GET_SINGLE(CollisionManager)->CheckReset();
}