#include "enemyManager.hpp"


void EnemyManager::creerEnemy(ID defLevel, float width, float height, TextureManager& manager)
{
	auto e = make_unique<Enemy>();
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
		e->attackCooldown = seconds(3.f);
		e->rechargeCooldown = seconds(0.f);
		break;
	case ENNEMI2:
		e->attackCooldown = seconds(1.5f);
		e->rechargeCooldown = seconds(0.f);
		break;
	case ENNEMI3:
		e->attackCooldown = seconds(1.f);
		e->rechargeCooldown = seconds(1.f);
		break;
	case BOSS1:
		e->attackCooldown = seconds(0.08f);
		e->rechargeCooldown = seconds(2.f);
		e->velocity = 3;
		break;
	case BOSS2:
		e->attackCooldown = seconds(0.2f);
		e->rechargeCooldown = seconds(2.f);
		e->velocity = 5;
		break;
	case BOSS3:
		e->attackCooldown = seconds(0.2f);
		e->rechargeCooldown = seconds(2.f);
		break;
	case BOSS4:
		e->attackCooldown = seconds(0.06f);
		e->rechargeCooldown = seconds(2.f);
		e->velocity = 6;
		break;
	}
	enemies.push_back(move(e));
}
void EnemyManager::detruireEnemy(unique_ptr<Enemy>& enemy) {
	auto it = find_if(enemies.begin(), enemies.end(), enemy.get());
	if (it != enemies.end()) {
		enemies.erase(it);
	}
}


void EnemyManager::checkEnemy(unique_ptr<Enemy>& enemy, int& toKill, ExplosionManager& exManager)
{
	if (enemy->HP < 1)
	{
		exManager.creerExplosion(enemy);
		detruireEnemy(enemy);
	}
}
void EnemyManager::clear()
{
	enemies.clear();
}
vector<unique_ptr<Enemy>>& EnemyManager::getEnemies() {
	return enemies;
}