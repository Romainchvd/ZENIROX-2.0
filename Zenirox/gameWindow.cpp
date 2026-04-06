#include "gameWindow.hpp"
#include "globalvar.hpp"

gameWindow::gameWindow() {
	window.create(sf::VideoMode(1920, 1080), "Zenirox", sf::Style::Close);
	window.setFramerateLimit(60);
}

bool gameWindow::isOpen()
{
	return window.isOpen();
}

void gameWindow::display()
{
	window.display();
}

void gameWindow::clear()
{
	window.clear();
}

void gameWindow::close()
{
	window.close();
}

void gameWindow::draw(sf::Drawable& drawable)
{
	window.draw(drawable);
}

bool gameWindow::pollEvent(sf::Event& event)
{
	return window.pollEvent(event);
}
