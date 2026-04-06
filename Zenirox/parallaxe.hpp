#pragma once

#include "globalvar.hpp"
#include "game.hpp"
#include <SFML/Graphics.hpp>

class Starparallaxe {
private:

    float starSpeed;
public:
    sf::Sprite sprite;
    sf::Sprite sprite2;
    Starparallaxe(TextureManager& manager, float speed, string texture);
    void starTexture();
    void cloudTexture();
    void update(float deltaTime);
    void draw(sf::RenderWindow& window);
};