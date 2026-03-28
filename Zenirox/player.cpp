#include "player.hpp"
#include <iostream>
#include "globalvar.hpp"
using namespace std;


void Player::setSprite() {

	handleShipTexture();
	sprite.rotate(90);
	sprite.setPosition(200, HEIGHT / 2);
}

void Player::handleShipTexture()
{
	switch (ship)
	{
	case Default:
		sprite.setTexture(textureManager.getTexture("ship"));
		break;
	case Ship1:
		sprite.setTexture(textureManager.getTexture("ship1"));
		break;
	case Ship2:
		sprite.setTexture(textureManager.getTexture("ship2"));
		break;
	case Ship3:
		sprite.setTexture(textureManager.getTexture("ship3"));
	default:
		break;
	}
}

Player::Player(TextureManager& manager) : attackCooldown(seconds(0.2)), boostDuration(seconds(2.5)), textureManager(manager) {
	if (!impactB.loadFromFile("sounds/hit.ogg")) throw runtime_error("Erreur de chargement du son d'impact");
	impact.setBuffer(impactB);
	if (!bonusB.loadFromFile("sounds/boost.ogg")) throw runtime_error("Erreur de chargement du son de bonus");
	if (!malusB.loadFromFile("sounds/malus.ogg")) throw runtime_error("Erreur de chargement du son de malus");
	if (!buyB.loadFromFile("sounds/buy.ogg")) throw runtime_error("Erreur de chargement du son d'achat");
	bonus.setBuffer(bonusB);
	malus.setBuffer(malusB);
	buy.setBuffer(buyB);
	if (difficulty == Easy)
	{
		HP = 2000;
		maxHP = 2000;
		maxShield = 1000;
		attack = 20;
	}
	if (difficulty == Hardcore)
	{
		HP = 500;
		maxHP = 500;
		maxShield = 250;
	}
	HP = maxHP;
}

void Player::checkOutOfScreen() {
	if (sprite.getPosition().y < MAXHEIGHT)
		sprite.setPosition(sprite.getPosition().x, MAXHEIGHT);
	else if (sprite.getPosition().y > HEIGHT - sprite.getGlobalBounds().height)
		sprite.setPosition(sprite.getPosition().x, HEIGHT-sprite.getGlobalBounds().height);
	
}
void Player::increaseScore(int toIncrease)
{
	currentScore += toIncrease;
}
void Player::decreaseScore(Text& scoreText, int toDecrease)
{
	currentScore -= toDecrease;
	if (currentScore < 0)
		currentScore = 0;
}

void Player::setDifficulty(Difficulty defDifficulty)
{
	difficulty = defDifficulty;
	{
		if (difficulty == Easy)
		{
			maxHP = 2000;
			maxShield = 1000;
			attack = 200;
		}
		else if (difficulty == Normal)
		{
			maxHP = 1000;
			maxShield = 500;
			attack = 10;
		}
		else if (difficulty == Hardcore)
		{
			maxHP = 500;
			maxShield = 250;
			attack = 10;
		}
		HP = maxHP;
	}
}