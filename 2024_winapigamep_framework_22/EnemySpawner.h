#pragma once

enum class EnemyType
{
	EnemyA,
	EnemyB,
	EnemyC,
	Boss
};

class EnemySpawner
{
public:
	EnemySpawner();
	~EnemySpawner();

	void SpawnEnemy(Vec2 pos, EnemyType enemyType);
};
