#ifndef CLASS_HPP
#define CLASS_HPP
#include "enemyManager.hpp"
#include "player.hpp"
#include "globalvar.hpp"
#include <memory>
#include <algorithm>
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
	bool isDead = false;
};

class ProjectileManager {
private:
	vector<unique_ptr<Projectile>> projectiles;
	TextureManager& textureManager;
public:
	ProjectileManager(TextureManager& manager) : textureManager(manager) {}
	void creerProjectile(Player player);
	void creerProjectile(unique_ptr<Enemy>& enemy, int defVelocity);
	void detruireProjectile();
	void checkProjectileOutOfScreen(const unique_ptr<Projectile>& projectile, EnemyManager &manager, Player &player, Text &scoreText);
	void clear();
	const vector<unique_ptr<Projectile>>& getProjectiles() const;
};

#endif
