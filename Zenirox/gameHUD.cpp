#include "gameHUD.hpp"

GameHUD::GameHUD(TextureManager& textureManager, FontManager& fontManager) : textureManager(textureManager), fontManager(fontManager)
{
	warningDuration = sf::seconds(1);
}

void GameHUD::initCockpit()
{
	cockpit.setTexture(textureManager.getTexture("cockpit"));
}

void GameHUD::initCoin()
{
	coin.setTexture(textureManager.getTexture("coin"));
	coin.setScale(0.2, 0.2);
	coin.setPosition(0, 45);
}

void GameHUD::initWarningText()
{
	warningText.setFont(fontManager.getFont("Engcomica"));
	warningText.setString("HURRY UP!");
	warningText.setFillColor(sf::Color::Red);
	warningText.setOutlineColor(sf::Color::Black);
	warningText.setOutlineThickness(4);
	warningText.setScale(1.5, 1.5);
	warningText.setPosition(450, 20);
}

void GameHUD::initSkull()
{
	skull.setTexture(textureManager.getTexture("skull"));
	skull.setColor(sf::Color::Red);
	skull.setScale(0.1, 0.1);
	skull.setPosition(350, 0);
}

void GameHUD::handleWarning(sf::RenderWindow& window)
{
	if (warningClock.getElapsedTime().asSeconds() > warningDuration.asSeconds())
	{
		window.draw(skull);
		window.draw(warningText);
	}
	if (warningClock.getElapsedTime().asSeconds() > warningDuration.asSeconds() + 1)
		warningClock.restart();
}

