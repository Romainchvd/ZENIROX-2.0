#include "obstacle.hpp"
#include "globalvar.hpp"
#include "player.hpp"

Obstacle::Obstacle(){}
Obstacle::~Obstacle() { cout << "Un obstacle a ete detruit" << endl; }
void Obstacle::setTexture(TextureManager& manager) {
	sprite.setTexture(manager.getTexture("meteor"));
}
void Obstacle::moveObstacle(int randValue)
{
	sprite.move(-velocity, 0);
	if (sprite.getPosition().x < -500)
	{
		switch (randValue)
		{
		case 0: sprite.setPosition(WIDTH + 3000, 500);
			break;
		case 1: sprite.setPosition(WIDTH + 3000, 750);
			break;
		case 2: sprite.setPosition(WIDTH + 3000, 250);
			break;
		default: sprite.setPosition(WIDTH + 3000, 500);
			break;
		}

		
		
	}
}
void Obstacle::moveObstacleF()
{
	sprite.move(-velocity, 0);
	if (sprite.getPosition().x < -500)
	{
		sprite.setPosition(3000, sprite.getPosition().y);
	}
}

void Obstacle::checkObstacle(Player& player)
{
	if (sprite.getGlobalBounds().intersects(player.sprite.getGlobalBounds()) && damageClock.getElapsedTime().asSeconds() > damageCooldown.asSeconds())
	{
		if (player.shield != 0)
			player.shield -= damages;
		else
			player.HP -= damages;
		damageClock.restart();
		player.impact.play();
	}
}



ObstacleManager::~ObstacleManager()
{
	for (auto obstacle : obstacles)
	{
		delete obstacle;
	}
	obstacles.clear();
}

Obstacle* ObstacleManager::creerObstacle(float width, float height) {
	Obstacle* o = new Obstacle();
	o->setTexture(manager);
	o->sprite.setPosition(width, height);
	o->sprite.setScale(0.25, 0.25);
	obstacles.push_back(o);
	return o;
	
}

vector<Obstacle*> ObstacleManager::getObstacles()
{
	return obstacles;
}
void ObstacleManager::detruireObstacle(Obstacle* obstacle)
{
	auto it = find(obstacles.begin(), obstacles.end(), obstacle);
	if (it != obstacles.end()) {
		delete* it;
		obstacles.erase(it);
	}
}
