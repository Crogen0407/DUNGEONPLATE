#pragma once

enum class EnemyType
{
	EnemyA,
	EnemyB,
	EnemyC,
	EnemyD,
	EnemyE,
	Boss
};

class EnemySpawner
{
public:
	EnemySpawner();
	~EnemySpawner();

	void SpawnEnemy(Vec2 pos, EnemyType enemyType);
};
