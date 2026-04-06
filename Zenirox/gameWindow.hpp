#pragma once
#include "globalvar.hpp"
#include <SFML/Graphics.hpp>

class gameWindow
{
public:
	sf::RenderWindow window;
	gameWindow();
	bool isOpen();
	void display();
	void clear();
	void close();
	void draw(sf::Drawable& drawable);
	bool pollEvent(sf::Event& event);
};