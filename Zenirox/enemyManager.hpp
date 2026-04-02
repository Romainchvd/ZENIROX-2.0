#pragma once
#include "enemy.hpp"
#include <memory>
#include <algorithm>
class EnemyManager {
private:
	vector<unique_ptr<Enemy>> enemies;
public:
	void creerEnemy(ID defLevel, float width, float height, TextureManager& manager);
	void detruireEnemy();
	void checkEnemy(unique_ptr<Enemy>& enemy, int& toKill, ExplosionManager& exManager);
	void clear();
	vector<unique_ptr<Enemy>>& getEnemies();
};