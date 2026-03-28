#ifndef POWERUPS_HPP
#define POWERUPS_HPP
#include "globalvar.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "player.hpp"
#include "enemyManager.hpp"

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

	
};

class UtilitaryManager {
private:
	vector<Utilitary*> utilitaryList;
	TextureManager& textureManager;
public:
	UtilitaryManager(TextureManager& manager);
	~UtilitaryManager();
	Utilitary* creerUtilitary(Powerup type, float width, float height);
	void detruireUtilitary(Utilitary* utilitary);
	vector<Utilitary* > getUtilitaryList();
	void checkUtilitary(Utilitary* h, Player& player, EnemyManager& eManager);
};


#endif