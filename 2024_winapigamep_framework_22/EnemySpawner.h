#pragma once
class Enemy;
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

	Enemy* SpawnEnemy(Vec2 pos, EnemyType enemyType);
};
