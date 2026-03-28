#include "parallaxe.hpp"

#include <iostream>
using namespace std;

Starparallaxe::Starparallaxe(TextureManager& manager, float& speed, string& texture)
	: starSpeed(speed) {
	
	sprite.setTexture(manager.getTexture(texture));
	sprite2.setTexture(manager.getTexture(texture));
	sprite.setPosition(0, 0); 
    sprite2.setPosition(sprite.getGlobalBounds().width, 0); 
}

void Starparallaxe::update(float deltaTime) {
	
	sprite.move(starSpeed * deltaTime, 0);
    sprite2.move(starSpeed * deltaTime, 0);

    if (sprite.getPosition().x + sprite.getGlobalBounds().width <= 0) {
        sprite.setPosition(sprite2.getPosition().x + sprite2.getGlobalBounds().width, 0);
    }
    if (sprite2.getPosition().x + sprite2.getGlobalBounds().width <= 0) {
        sprite2.setPosition(sprite.getPosition().x + sprite.getGlobalBounds().width, 0);
    }
}



void Starparallaxe::draw(sf::RenderWindow& window) {
	window.draw(sprite);
	window.draw(sprite2);
}






    