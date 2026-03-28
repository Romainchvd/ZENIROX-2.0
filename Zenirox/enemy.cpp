#include "enemy.hpp"


void Enemy::setTexture(TextureManager& manager) {
	switch (id)
	{
	case ENNEMI1:
		sprite.setTexture(manager.getTexture("enemy1"));
		break;
	case ENNEMI2:
		sprite.setTexture(manager.getTexture("enemy2"));
		break;
	case ENNEMI3:
		sprite.setTexture(manager.getTexture("enemy3"));
		break;
	case BOSS1:
		sprite.setTexture(manager.getTexture("Boss1"));
		break;
	case BOSS2:
		sprite.setTexture(manager.getTexture("Boss2"));
		break;
	case BOSS3:
		sprite.setTexture(manager.getTexture("Boss3"));
		break;
	case BOSS4:
		sprite.setTexture(manager.getTexture("Boss4"));
		break;
	default:
		break;
	}
	}
void Enemy::setAttackAndHP() {
	switch (id)
	{
	case ENNEMI1:
		AttackDamages = 5;
		HP = 100;
		maxHP = 100;
		break;
	case ENNEMI2:
		AttackDamages = 10;
		HP = 200;
		maxHP = 200;
		break;
	case ENNEMI3:
		AttackDamages = 15;
		HP = 150;
		maxHP = 150;
		break;
	case BOSS1:
		AttackDamages = 10;
		HP = 400;
		maxHP = 400;
		break;
	case BOSS2:
		AttackDamages = 10;
		HP = 500;
		maxHP = 500;
		break;
	case BOSS3:
		AttackDamages = 10;
		HP = 600;
		maxHP = 600;
		shield = 200;
		maxShield = 200;
		break;
	case BOSS4:
		AttackDamages = 15;
		HP = 800;
		maxHP = 800;
		shield = 400;
		maxShield = 400;
		break;
	default:
		break;
	}
}

Enemy::Enemy() {
	if (!impactB.loadFromFile("sounds/hit.ogg")) throw runtime_error("Erreur de chargement du son d'impact");
	impact.setBuffer(impactB);
	if (!shot.loadFromFile("sounds/shot.ogg")) throw runtime_error("Erreur de chargement du son de tir");
	lasershot.setBuffer(shot);
}
Enemy::~Enemy() {
	{ cout << "Un ennemi a ete detruit" << endl; };
}
void Enemy::enemyMove() {
	if (sprite.getPosition().y < MAXHEIGHT)
		direction = down;
	else if (sprite.getPosition().y > HEIGHT - sprite.getGlobalBounds().height)
		direction = up;
	if (id == ENNEMI2 || id == ENNEMI3)
	{
		if (direction == up)
			sprite.move(-4, -velocity);
		else
			sprite.move(-4, velocity);
	}
	if (id == BOSS1 || id == BOSS2 || id == BOSS3 ||id == BOSS4)
	{
		if (direction == up)
			sprite.move(0, -velocity);
		else
			sprite.move(0, velocity);
	}
	if (id == ENNEMI1)
	{
		sprite.move(-4, 0);
	}
	if (sprite.getPosition().x < -500 && id != ENNEMI3)
	{
		sprite.setPosition(sprite.getPosition().x + WIDTH + 1000, sprite.getPosition().y);
	}
	if (sprite.getPosition().x < -500 && id == ENNEMI3)
	{
		sprite.setPosition(sprite.getPosition().x + WIDTH + 2000, sprite.getPosition().y);
	}
}

