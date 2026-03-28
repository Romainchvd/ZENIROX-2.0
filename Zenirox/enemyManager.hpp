#pragma once
#include "enemy.hpp"

class EnemyManager {
private:
	vector<Enemy*> enemies;
public:
	~EnemyManager();
	Enemy* creerEnemy(ID defLevel, float width, float height, TextureManager& manager);
	void detruireEnemy(Enemy* enemy);
	void checkEnemy(Enemy* enemy, int& toKill, ExplosionManager& exManager);
	vector<Enemy* > getEnemies();
};