#include "gameHUD.hpp"

gameHUD::gameHUD(TextureManager& textureManager, FontManager& fontManager) : textureManager(textureManager), fontManager(fontManager)
{
	warningDuration = sf::seconds(1);
}

void gameHUD::initCockpit()
{
	cockpit.setTexture(textureManager.getTexture("cockpit"));
}

void gameHUD::initCoin()
{
	coin.setTexture(textureManager.getTexture("coin"));
	coin.setScale(0.2, 0.2);
	coin.setPosition(0, 45);
}

void gameHUD::initWarningText()
{
	warningText.setFont(fontManager.getFont("Engcomica"));
	warningText.setString("HURRY UP!");
	warningText.setFillColor(sf::Color::Red);
	warningText.setOutlineColor(sf::Color::Black);
	warningText.setOutlineThickness(4);
	warningText.setScale(1.5, 1.5);
	warningText.setPosition(450, 20);
}

