#include "pch.h"
#include "CollisionManager.h"
#include "SceneManager.h"
#include "Scene.h"
#include "Object.h"
#include "Collider.h"
void CollisionManager::Update()
{
	for (UINT Row = 0; Row < (UINT)LAYER::END; ++Row)
	{
		for (UINT Col = Row; Col < (UINT)LAYER::END; ++Col)
		{
			if (m_arrLayer[Row] & (1 << Col))
			{
				//int a = 0;
				CollisionLayerUpdate((LAYER)Row, (LAYER)Col);
			}
		}
	}
}

void CollisionManager::CheckLayer(LAYER _left, LAYER _right)
{
	UINT Row = (UINT)_left;
	UINT Col = (UINT)_right;
	if (Row > Col)
		std::swap(Row, Col);

	if (m_arrLayer[Row] & (1 << Col))
	{
		m_arrLayer[Row] &= ~(1 << Col);
	}
	else
	{
		m_arrLayer[Row] |= (1 << Col);
	}
	int a = 0;
}

void CollisionManager::CheckReset()
{
	memset(m_arrLayer, 0, sizeof(UINT) * (UINT)LAYER::END);
}

void CollisionManager::CollisionLayerUpdate(LAYER left, LAYER right)
{
	std::shared_ptr<Scene> currentScene = GET_MANAGER(SceneManager)->GetCurrentScene();
	const vector<Object*>& leftLayerVec = currentScene->GetLayerObjects(left);
	const vector<Object*>& rightLayerVec = currentScene->GetLayerObjects(right);
	map<ULONGLONG, bool>::iterator iter;
	for (size_t i = 0; i < leftLayerVec.size(); ++i)
	{
		Collider* leftCollider = leftLayerVec[i]->GetComponent<Collider>();
		// 충돌체 없는 경우
		if (nullptr == leftCollider)
			continue;
		for (size_t j = 0; j < rightLayerVec.size(); j++)
		{
			Collider* rightCollider = rightLayerVec[j]->GetComponent<Collider>();
			// 충돌체가 없거나, 자기자신과의 충돌인 경우
			if (nullptr == rightCollider || leftLayerVec[i] == rightLayerVec[j] 
				|| leftLayerVec[i]->GetActive() == false 
				|| rightLayerVec[j]->GetActive() == false)
				continue;

			COLLIDER_ID colliderID; // 두 충돌체로만 만들 수 있는 ID
 			colliderID.left_ID = leftCollider->GetID();
			colliderID.right_ID = rightCollider->GetID();

			iter = m_mapCollisionInfo.find(colliderID.ID);
			// 이전 프레임 충돌한 적 없다.
			if (iter == m_mapCollisionInfo.end())
			{
				// 충돌 정보가 미등록된 상태인 경우 등록(충돌하지 않았다로)
				m_mapCollisionInfo.insert({ colliderID.ID, false });
				//m_mapCollisionInfo[colliderID.ID] = false;
				iter = m_mapCollisionInfo.find(colliderID.ID);
			}

			if (IsCollision(leftCollider, rightCollider))
			{
				// 이전에도 충돌중
				if (iter->second)
				{
					if (leftLayerVec[i]->GetIsDead() || rightLayerVec[j]->GetIsDead())
					{
						leftCollider->ExitCollision(rightCollider);
						rightCollider->ExitCollision(leftCollider);
						iter->second = false;
					}
					else
					{
						leftCollider->StayCollision(rightCollider);
						rightCollider->StayCollision(leftCollider);
					}
				}
				else // 이전에 충돌 x
				{
					if (!leftLayerVec[i]->GetIsDead() && !rightLayerVec[j]->GetIsDead())
					{
						leftCollider->EnterCollision(rightCollider);
						rightCollider->EnterCollision(leftCollider);
						iter->second = true;
					}
				}
			}
			else // 충돌 안하네?
			{
				if (iter->second) // 근데 이전에 충돌중
				{
					leftCollider->ExitCollision(rightCollider);
					rightCollider->ExitCollision(leftCollider);
					iter->second = false;
				}
			}
		}
	}
}

bool CollisionManager::IsCollision(Collider* _left, Collider* _right)
{
	Vec2 vLeftPos = _left->GetLatedUpatedPos();
	Vec2 vRightPos = _right->GetLatedUpatedPos();
	Vec2 vLeftSize = _left->GetSize();
	Vec2 vRightSize = _right->GetSize();

	RECT leftRt = RECT_MAKE(vLeftPos.x, vLeftPos.y, vLeftSize.x, vLeftSize.y);
	RECT rightRt = RECT_MAKE(vRightPos.x, vRightPos.y, vRightSize.x, vRightSize.y);
	RECT rt;

	return ::IntersectRect(&rt, &leftRt, &rightRt);
}
