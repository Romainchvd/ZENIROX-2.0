#ifndef OBSTACLE_HPP
#define OBSTACLE_HPP
#include <iostream>
#include <SFML/Graphics.hpp>
#include "textureManager.hpp"
#include "player.hpp"
using namespace std;
using namespace sf;

class Obstacle {
public:
	Sprite sprite;
	Clock damageClock;
	Time damageCooldown = seconds(2);
	float velocity = 7;
	int damages = 75;
	Obstacle();
	~Obstacle();
	void setTexture(TextureManager& manager);
	void moveObstacle(int randValue);
	void moveObstacleF();
	void checkObstacle(Player& player);
};

class ObstacleManager {
private:
	vector<Obstacle*> obstacles;
	TextureManager& manager;
public:
	ObstacleManager(TextureManager& manager) : manager(manager) {}
	~ObstacleManager();
	Obstacle* creerObstacle(float width, float height);
	void detruireObstacle(Obstacle* obstacle);
	vector<Obstacle* > getObstacles();
};





#endif