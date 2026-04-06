#include "background.hpp"
#include <iostream>
#include <stdexcept>

Background::Background(TextureManager& manager, float speed)
    : scrollSpeed(speed) {

	sprite.setTexture(manager.getTexture("palier1"));
    sprite.setPosition(0, 0);

	sprite2.setTexture(manager.getTexture("palier1"));
    sprite2.setPosition(sprite.getGlobalBounds().width, 0);
}

void Background::update(float deltaTime) {
    sprite.move(scrollSpeed * deltaTime, 0);
    sprite2.move(scrollSpeed * deltaTime, 0);

    if (sprite.getPosition().x + sprite.getGlobalBounds().width <= 0) {
        sprite.setPosition(sprite2.getPosition().x + sprite2.getGlobalBounds().width, 0);
    }
    if (sprite2.getPosition().x + sprite2.getGlobalBounds().width <= 0) {
        sprite2.setPosition(sprite.getPosition().x + sprite.getGlobalBounds().width, 0);
    }
}

void Background::draw(gameWindow& gameWindow) {
    gameWindow.draw(sprite);
    gameWindow.draw(sprite2);
}

void Background::setUpTier(TextureManager& manager, std::string tier) {
	sprite.setTexture(manager.getTexture(tier));
}
