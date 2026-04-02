#ifndef POWERUPS_HPP
#define POWERUPS_HPP
#include "globalvar.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "player.hpp"
#include "enemyManager.hpp"
#include <memory>
#include <utility>
#include <algorithm>

using namespace std;
using namespace sf;

enum Powerup {
	heart, evilHeart, battery, evilBattery, shield, evilShield
};

class Utilitary
{
public:
	Sprite sprite;
	float velocity = 3;
	Powerup type;
	Utilitary();
	~Utilitary();
	void setUtilitary(TextureManager& textureManager);
	void moveUtilitary();
	bool isDead = false;	
	
};

class UtilitaryManager {
private:
	vector<unique_ptr<Utilitary>> utilitaryList;
	TextureManager& textureManager;
public:
	UtilitaryManager(TextureManager& manager);
	void creerUtilitary(Powerup type, float width, float height);
	void detruireUtilitary();
	vector<unique_ptr<Utilitary>>& getUtilitaryList();
	void checkUtilitary(unique_ptr<Utilitary>& h, Player& player, EnemyManager& eManager);
	void clear();
};


#endif