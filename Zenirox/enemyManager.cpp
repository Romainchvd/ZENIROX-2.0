#include "enemyManager.hpp"

EnemyManager::~EnemyManager() {
	for (auto enemy : enemies)
	{
		delete enemy;
	}
	enemies.clear();
}

Enemy* EnemyManager::creerEnemy(ID defLevel, float width, float height, TextureManager& manager)
{
	Enemy* e = new Enemy();
	e->id = defLevel;
	e->setTexture(manager);
	e->setAttackAndHP();
	e->sprite.setPosition(width, height);
	e->sprite.setScale(2, 2);
	e->boostDuration = seconds(2.5);
	if (defLevel == BOSS2)
		e->sprite.setScale(1.5, 1.5);
	else if (defLevel == BOSS3)
		e->sprite.setScale(1, 1);
	else if (defLevel == BOSS4)
		e->sprite.setScale(1, 1);
	switch (defLevel)
	{
	case ENNEMI1:
		e->id = ENNEMI1;
		break;
	case ENNEMI2:
		e->id = ENNEMI2;
		break;
	case ENNEMI3:
		e->id = ENNEMI3;
		break;
	case BOSS1:
		e->id = BOSS1;
		break;
	case BOSS2:
		e->id = BOSS2;
		break;
	case BOSS3:
		e->id = BOSS3;
		break;
	case BOSS4:
		e->id = BOSS4;
	default:
		break;
	}
	switch (e->id)
	{
	case ENNEMI1:
		e->attackCooldown = seconds(3);
		e->rechargeCooldown = seconds(0);
		break;
	case ENNEMI2:
		e->attackCooldown = seconds(1.5);
		e->rechargeCooldown = seconds(0);
		break;
	case ENNEMI3:
		e->attackCooldown = seconds(1);
		e->rechargeCooldown = seconds(1);
		break;
	case BOSS1:
		e->attackCooldown = seconds(0.08);
		e->rechargeCooldown = seconds(2);
		e->velocity = 3;
		break;
	case BOSS2:
		e->attackCooldown = seconds(0.2);
		e->rechargeCooldown = seconds(2);
		e->velocity = 5;
		break;
	case BOSS3:
		e->attackCooldown = seconds(0.2);
		e->rechargeCooldown = seconds(2);
		break;
	case BOSS4:
		e->attackCooldown = seconds(0.06);
		e->rechargeCooldown = seconds(2);
		e->velocity = 6;
		break;
	}
	enemies.push_back(e);
	return e;
}
void EnemyManager::detruireEnemy(Enemy* enemy) {
	auto it = find(enemies.begin(), enemies.end(), enemy);
	if (it != enemies.end()) {
		delete* it;
		enemies.erase(it);
	}
}


void EnemyManager::checkEnemy(Enemy* enemy, int& toKill, ExplosionManager& exManager)
{
	if (enemy->HP < 1)
	{
		exManager.creerExplosion(enemy);
		detruireEnemy(enemy);
		--toKill;
	}
}
vector<Enemy* > EnemyManager::getEnemies() {
	return enemies;
}