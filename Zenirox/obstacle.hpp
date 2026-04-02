#ifndef OBSTACLE_HPP
#define OBSTACLE_HPP
#include <iostream>
#include <SFML/Graphics.hpp>
#include "textureManager.hpp"
#include "player.hpp"
#include <memory>
#include <algorithm>
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
	bool isDead = false;
};

class ObstacleManager {
private:
	vector<unique_ptr<Obstacle>> obstacles;
	TextureManager& manager;
public:
	ObstacleManager(TextureManager& manager) : manager(manager) {}
	void creerObstacle(float width, float height);
	void detruireObstacle();
	vector<unique_ptr<Obstacle>>& getObstacles();
	void clear();
};





#endif