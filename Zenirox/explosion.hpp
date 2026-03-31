#ifndef EXPLOSION_HPP
#define EXPLOSION_HPP
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <SFML/Audio.hpp>
#include <memory>
#include <algorithm>
#include "textureManager.hpp"

using namespace std;
using namespace sf;

class Enemy;
class Player;

class Explosion {
public:
	
	Sprite sprite;
	Sound boom;
	SoundBuffer boomB;
	Clock explosionClock;
	Time frameDuration = seconds(0.05);
	int frame = 0;
	void setExplosion(TextureManager& textureManager);
	void animate();
};

class ExplosionManager {
private:
	vector<unique_ptr<Explosion>> explosions;
public:
	TextureManager& textureManager;
	ExplosionManager(TextureManager& tm);
	void creerExplosion(unique_ptr<Enemy>& enemy);
	void creerExplosion(Player player);
	vector<unique_ptr<Explosion>>& getExplosions();
	void detruireExplosion(unique_ptr<Explosion>& explosion);
	void clear();
};

#endif 