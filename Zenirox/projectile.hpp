#ifndef CLASS_HPP
#define CLASS_HPP
#include "enemyManager.hpp"
#include "player.hpp"
#include "globalvar.hpp"
using namespace sf;
using namespace std;


class Projectile {
public:
	Sprite sprite;
	TextureManager& textureManager;
	ID id;
	int velocity;
	Projectile(TextureManager& textureManager);
	~Projectile();
	void setProjectile();
};

class ProjectileManager {
private:
	vector<Projectile*> projectiles;
	TextureManager& textureManager;
public:
	ProjectileManager(TextureManager& manager) : textureManager(manager) {}
	~ProjectileManager();
	Projectile* creerProjectile(Player player);
	Projectile* creerProjectile(Enemy* enemy, int defVelocity);
	void detruireProjectile(Projectile* projectile);
	void checkProjectileOutOfScreen(Projectile* projectile, EnemyManager &manager, Player &player, Text &scoreText);
	vector<Projectile* > getProjectiles();
};

#endif
