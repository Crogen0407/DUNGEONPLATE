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
		for (size_t j = 0; j < m_vecObj[i].size(); ++j)
		{
			if (m_vecObj[i][j]->GetActive() == false) continue;
			if (!m_vecObj[i][j]->GetIsDead())
				m_vecObj[i][j]->Update();
		}
	}
}

void Scene::LateUpdate()
{
	for (size_t i = 0; i < (UINT)LAYER::END; i++)
	{
		for (UINT j = 0; j < m_vecObj[i].size(); ++j)
		{
			if (m_vecObj[i][j]->GetActive() == false) continue;
			if (!m_vecObj[i][j]->GetIsDead())
				m_vecObj[i][j]->LateUpdate();
		}
	}
}

void Scene::Render(ComPtr<ID2D1RenderTarget> renderTarget)
{
	for (UINT i = 0; i < (UINT)LAYER::END; ++i)
	{
		for (size_t j = 0; j < m_vecObj[i].size();)
		{
			if (!m_vecObj[i][j]->GetIsDead() == true)
			{
				if (m_vecObj[i][j]->GetActive() == false)
				{
					j++;
					continue;
				}
				m_vecObj[i][j++]->Render(renderTarget);
			}
			else
				m_vecObj[i].erase(m_vecObj[i].begin() + j);
		}
	}

}

void Scene::Release()
{
	// 오브젝트 삭제.
	for (size_t i = 0; i < (UINT)LAYER::END; i++)
	{
		for (UINT j = 0; j < m_vecObj[i].size(); ++j)
		{
			delete m_vecObj[i][j];
		}
		m_vecObj[i].clear();
		m_vecObj[i] = { };
	}
	GET_SINGLE(CollisionManager)->CheckReset();
}