#pragma once

#include "globalvar.hpp"
#include <SFML/Graphics.hpp>
#include "gameWindow.hpp"
#include "textureManager.hpp"

class Starparallaxe {
private:

    float starSpeed;
public:
    sf::Sprite sprite;
    sf::Sprite sprite2;
    Starparallaxe(TextureManager& manager, float speed, std::string texture);
    void starTexture();
    void cloudTexture();
    void update(float deltaTime);
    void draw(gameWindow& gameWindow);
};