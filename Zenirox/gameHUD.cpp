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
	coin.setScale(0.2f, 0.2f);
	coin.setPosition(0.f, 45.f);
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
	skull.setScale(0.1f, 0.1f);
	skull.setPosition(350.f, 0.f);
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

