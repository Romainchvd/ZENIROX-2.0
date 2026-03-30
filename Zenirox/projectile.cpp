#include <iostream>
#include <SFML/Graphics.hpp>
#include "projectile.hpp"
#include "score.hpp"
using namespace sf;

Projectile::Projectile(TextureManager& textureManager) : textureManager(textureManager) {};
Projectile::~Projectile() { std::cout << "Projectile detruit" << std::endl; }

void Projectile::setProjectile() {
	if(id == PLAYER)
	{
		sprite.setTexture(textureManager.getTexture("projectilePlayer"));
	}
	else
	{
		sprite.setTexture(textureManager.getTexture("projectileEnemy"));
	}
	sprite.setScale(0.3 , 0.3);
		
}

void ProjectileManager::creerProjectile(Player player) {
	auto p = make_unique<Projectile>(textureManager);
	p->sprite.setOrigin(p->sprite.getGlobalBounds().width / 2, p->sprite.getGlobalBounds().height / 2);
	p->id = player.id;
	p->setProjectile();
	projectiles.push_back(move(p));
}

void ProjectileManager::creerProjectile(unique_ptr<Enemy>& enemy, int defVelocity) {
	auto p = make_unique<Projectile>(textureManager);
	p->sprite.setOrigin(p->sprite.getGlobalBounds().width, p->sprite.getGlobalBounds().height / 2);
	p->sprite.rotate(180);
	p->id = enemy->id;
	p->setProjectile();
	p->velocity = defVelocity;
	projectiles.push_back(move(p));
	switch (enemy->id)
	{
	case ENNEMI1:
		p->sprite.setPosition(enemy->sprite.getPosition().x, enemy->sprite.getPosition().y + enemy->sprite.getGlobalBounds().height -60);
		break;
	case ENNEMI2:
		p->sprite.setPosition(enemy->sprite.getPosition().x, enemy->sprite.getPosition().y + enemy->sprite.getGlobalBounds().height - 85);
		break;
	case ENNEMI3:
		p->sprite.setPosition(enemy->sprite.getPosition().x, enemy->sprite.getPosition().y + enemy->sprite.getGlobalBounds().height - 135);
		break;
	case BOSS1:
		p->sprite.setPosition(enemy->sprite.getPosition().x, enemy->sprite.getPosition().y + enemy->sprite.getGlobalBounds().height -70);
		break;
	case BOSS2:
		p->sprite.setPosition(enemy->sprite.getPosition().x, enemy->sprite.getPosition().y + enemy->sprite.getGlobalBounds().height -140);
		break;
	case BOSS3:
		p->sprite.setPosition(enemy->sprite.getPosition().x, enemy->sprite.getPosition().y + enemy->sprite.getGlobalBounds().height -68);
		break;
	case BOSS4:
		p->sprite.setPosition(enemy->sprite.getPosition().x, enemy->sprite.getPosition().y + enemy->sprite.getGlobalBounds().height - 110);
		break;
	default:
		break;
	}
}
void ProjectileManager::detruireProjectile(unique_ptr<Projectile>& projectile)
{
	auto it = find_if(projectiles.begin(), projectiles.end(), projectile.get());
	if (it != projectiles.end()) {
		projectiles.erase(it);
	}
}
const vector<unique_ptr<Projectile>>& ProjectileManager::getProjectiles() const { return projectiles; }
void ProjectileManager::clear() {
	projectiles.clear();
}

void ProjectileManager::checkProjectileOutOfScreen(unique_ptr<Projectile>& projectile, EnemyManager &manager, Player &player, Text &scoreText) {
	if (projectile->sprite.getPosition().y > HEIGHT || projectile->sprite.getPosition().y < 0 || projectile->sprite.getPosition().x > WIDTH || projectile->sprite.getPosition().x < 0)
	detruireProjectile(projectile);
	else
		for (auto i = 0; i < manager.getEnemies().size(); i++)
		{
			if (projectile->sprite.getGlobalBounds().intersects(manager.getEnemies()[i]->sprite.getGlobalBounds()) && projectile->id == PLAYER)
			{
				detruireProjectile(projectile);
				manager.getEnemies()[i]->impact.play();
				if (manager.getEnemies()[i]->shield == 0)
					manager.getEnemies()[i]->HP -= player.attack;
				else
				{
					manager.getEnemies()[i]->shield -= player.attack;
					if (manager.getEnemies()[i]->shield < 0)
						manager.getEnemies()[i]->shield = 0;
				}
				player.increaseScore(5);
				if (manager.getEnemies()[i]->HP <= 0 && manager.getEnemies()[i]->id != BOSS1 && manager.getEnemies()[i]->id != BOSS2 && manager.getEnemies()[i]->id != BOSS3 && manager.getEnemies()[i]->id != BOSS4)
					player.increaseScore(100);
				else if (manager.getEnemies()[i]->HP <= 0 && manager.getEnemies()[i]->id != ENNEMI1 && manager.getEnemies()[i]->id != ENNEMI2 && manager.getEnemies()[i]->id != ENNEMI3)
					player.increaseScore(200);
				break;
			}
			if (projectile->sprite.getGlobalBounds().intersects(player.sprite.getGlobalBounds()) && projectile->id != PLAYER)
			{
				
				detruireProjectile(projectile);
				player.impact.play();
				if (player.shield == 0)
					player.HP -= manager.getEnemies()[i]->AttackDamages;
				else
					player.shield -= manager.getEnemies()[i]->AttackDamages;
				
				break;
			}
			
		}
	}


