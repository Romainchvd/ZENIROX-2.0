#ifndef BACKGROUND_HPP
#define BACKGROUND_HPP

#include <SFML/Graphics.hpp>
#include "textureManager.hpp"
class Background {
private:
    float scrollSpeed;

public:
    sf::Sprite sprite;
    sf::Sprite sprite2;

 //   palier pal;

    Background(TextureManager& manager, float speed);
    void update(float deltaTime);
    void draw(sf::RenderWindow& window);

	void setUpTier(TextureManager& manager, std::string tier);
};

#endif
